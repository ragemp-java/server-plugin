/*
 * Copyright (c) 2017 Noxaro aka Fabian Jungwirth
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 3.0 of the License, or (at your option) any later version.
 * See the file COPYING included with this distribution for more information.
 */

#include "VM.hpp"
#include "Converter.hpp"

static JNIEnv *jniEnv = nullptr;
static JavaVM *javaVM = nullptr;

JNIEnv *JVM::VM::getJNIEnv() {
    return jniEnv;
}

JavaVM *JVM::VM::getJVM() {
    return javaVM;
}

bool JVM::VM::create() {
    std::cout << "Creating Java Virtual Machine ... " << std::endl;

    if (!VM::createJVM()) {
        std::cout << "Failed to initialize Java Virtual Machine" << std::endl;
        return false;
    }

    if (!VM::findAndExecuteMain()) {
        std::cout << "Failed to execute Launcher" << std::endl;
        return false;
    }

    Object::initialize();
    return true;
}

bool JVM::VM::checkForException() {
    if (jniEnv->ExceptionCheck()) {
        jthrowable throwable = jniEnv->ExceptionOccurred();
        jclass throwableCls = jniEnv->GetObjectClass(throwable);
        jmethodID printStackTraceId = jniEnv->GetMethodID(throwableCls, "printStackTrace", "()V");

        jniEnv->CallVoidMethod(throwable, printStackTraceId);
        jniEnv->ExceptionClear();
        return true;
    }
    return false;
}

bool JVM::VM::findAndExecuteMain() {
    jclass jClass = jniEnv->FindClass(JVM_LAUNCHER_CLASS_NAME.c_str());
    if (jClass == nullptr) {
        std::cout << std::endl << "Couldn't find expected VM main class" << std::endl;
        return false;
    }
    jmethodID methodId = jniEnv->GetStaticMethodID(jClass, JVM_LAUNCHER_METHOD_NAME.c_str(), "(I)V");
    if (methodId == nullptr) {
        std::cout << std::endl << "Couldn't find expected VM main method" << std::endl;
        return false;
    }
    jint jOS = JVM::Converter::toJInt(OS);
    jniEnv->CallStaticVoidMethod(jClass, methodId, jOS);
    if (checkForException()) {
        return false;
    }
    return true;
}

bool JVM::VM::createJVM() {
    JavaVMInitArgs vm_args;
    auto options = new JavaVMOption[2];

    std::string libraryPath = "-Djava.library.path=/plugin"; //+ FILE_ENDING;
    options[0].optionString = "-Djava.class.path=plugins/java-runtime-launcher-1.0-SNAPSHOT.jar:";
    options[1].optionString = const_cast<char *>(libraryPath.c_str());

    vm_args.version = JNI_VERSION_1_8;
    vm_args.options = options;
    vm_args.nOptions = 2;
    vm_args.ignoreUnrecognized = JNI_FALSE;

    int res = JNI_CreateJavaVM(&javaVM, (void **) &jniEnv, &vm_args);
    if (res != JNI_OK) {
        switch (res) {
            case JNI_ERR:
                printf("Error: %d\nunknown error", res);
                break;
            case JNI_EDETACHED:
                printf("Error: %d\nthread detached from the VM", res);
                break;
            case JNI_EVERSION:
                printf("Error: %d\nJNI version error", res);
                break;
            case JNI_ENOMEM:
                printf("Error %d:\nnot enough memory", res);
                break;
            case JNI_EEXIST:
                printf("Error %d:\nVM already created", res);
                break;
            case JNI_EINVAL:
                printf("Error %d\ninvalid arguments ", res);
                break;
            default:
                printf("Unknown startup error %d", res);
        }
        javaVM->DestroyJavaVM();
        return false;
    } else {
        return true;
    }
}

jclass JVM::VM::getClass(std::string className) {
    jclass jClass = jniEnv->FindClass(className.c_str());
    if (jClass == nullptr) {
        std::cerr << "JVM class " + className + " not found" << std::endl;
        throw ClassNotFoundException(className + " not found");
    }
    return jClass;
}

jmethodID JVM::VM::getMethodId(jclass jClass, std::string methodName, std::string methodSignature) {
    jmethodID methodId = jniEnv->GetMethodID(jClass, methodName.c_str(), methodSignature.c_str());
    if (methodId == nullptr) {
        std::cerr << "JVM method " << methodName << " not found" << std::endl;
        throw MethodNotFoundException(methodName + " not found");
    }
    return methodId;
}

jmethodID JVM::VM::getStaticMethodId(jclass jClass, std::string methodName, std::string methodSignature) {
    jmethodID methodId = jniEnv->GetStaticMethodID(jClass, methodName.c_str(), methodSignature.c_str());
    if (methodId == nullptr) {
        std::cerr << "JVM static method " << methodName << " not found";
        throw MethodNotFoundException(methodName + " not found");
    }
    return methodId;
}