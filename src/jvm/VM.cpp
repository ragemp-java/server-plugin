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
#include <fstream>

static JavaVM *javaVM = nullptr;

JavaVM *JVM::VM::getJVM() {
    return javaVM;
}

bool JVM::VM::create() {
    std::cout << "Creating Java Virtual Machine ... " << std::endl;

    if (!VM::createJVM()) {
        std::cout << "Failed to initialize Java Virtual Machine" << std::endl;
        return false;
    }

    JNIEnv *env = attachCurrentThread();

    if (!VM::findAndExecuteMain(env)) {
        std::cout << "Failed to execute Launcher" << std::endl;
        return false;
    }

    Exception::initialize(env);
    Object::initialize(env);

    detachCurrentThread();
    return true;
}

bool JVM::VM::checkForException(JNIEnv *env, bool detachAfterCheck) {
    if (env->ExceptionCheck()) {
        jthrowable throwable = env->ExceptionOccurred();
        jclass throwableCls = env->GetObjectClass(throwable);
        jmethodID printStackTraceId = env->GetMethodID(throwableCls, "printStackTrace", "()V");

        env->CallVoidMethod(throwable, printStackTraceId);
        env->ExceptionClear();
        if(detachAfterCheck) {
            getJVM()->DetachCurrentThread();
        }
        return true;
    }
    if(detachAfterCheck) {
        getJVM()->DetachCurrentThread();
    }
    return false;
}

bool JVM::VM::findAndExecuteMain(JNIEnv *env) {
    jclass jClass = env->FindClass(JVM_LAUNCHER_CLASS_NAME.c_str());
    if (jClass == nullptr) {
        std::cout << std::endl << "Couldn't find expected VM main class" << std::endl;
        return false;
    }
    jmethodID methodId = env->GetStaticMethodID(jClass, JVM_LAUNCHER_METHOD_NAME.c_str(), "(I)V");
    if (methodId == nullptr) {
        std::cout << std::endl << "Couldn't find expected VM main method" << std::endl;
        return false;
    }
    env->CallStaticVoidMethod(jClass, methodId, OS);
    if (checkForException(env)) {
        return false;
    }
    return true;
}

bool JVM::VM::createJVM() {
    JavaVMInitArgs vm_args;
//    auto options = new JavaVMOption[3];

    std::string libraryPath = "-Djava.library.path=./plugin";

    std::vector<char *> optionStrings;
    std::ifstream optionStream("./jvm.txt", std::ifstream::in);
    if (optionStream.is_open())
    {
        optionStrings.reserve(20);
        while (optionStream.good())
        {
            auto option = new char[128];
            optionStream.getline(option, 128);
            auto p = option + strlen(option) - 1;
            if (p >= option && *p == '\r') *p = 0;
            if (strlen(option) < 1) continue;
            optionStrings.push_back(option);
        }
        optionStream.close();
    }

    auto options = new JavaVMOption[optionStrings.size() + 2];
#if defined(WINDOWS)
    options[0].optionString = "-Djava.class.path=./plugins/java-runtime-api-1.0-SNAPSHOT.jar;./plugins/java-runtime-runtime-1.0-SNAPSHOT.jar;./plugins/java-runtime-launcher-1.0-SNAPSHOT.jar;";
#elif defined(LINUX)
    options[0].optionString = "-Djava.class.path=plugins/java-runtime-api-1.0-SNAPSHOT.jar:plugins/java-runtime-runtime-1.0-SNAPSHOT.jar:plugins/java-runtime-runtime-1.0-SNAPSHOT.jar:";
#endif

    options[1].optionString = "-Djava.library.path=./plugins";
    for (unsigned int i = 0; i < optionStrings.size(); i++)
    {
        std::cout << optionStrings[i] << std::endl;
        options[i + 2].optionString = optionStrings[i];
    }


//    options[2].optionString = "-agentlib:jdwp=transport=dt_socket,server=y,suspend=n,address=5005 -agentpath:'C:/Users/Fabian Jungwirth/Desktop/visualvm_14/profiler/lib/deployed/jdk16/windows-amd64/profilerinterface.dll'='C:\Users\Fabian Jungwirth\Desktop\visualvm_14\profiler\lib'5006";
    vm_args.version = JNI_VERSION_1_8;
    vm_args.options = options;
    vm_args.nOptions = (jint) (optionStrings.size() + 2);
    vm_args.ignoreUnrecognized = JNI_FALSE;
    JNIEnv *env;
    int res = JNI_CreateJavaVM(&javaVM, (void **) &env, &vm_args);
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

jclass JVM::VM::getClass(JNIEnv *env, std::string className) {
    jclass jClass = env->FindClass(className.c_str());
    if (jClass == nullptr) {
        std::cerr << "JVM class " + className + " not found" << std::endl;
        throw ClassNotFoundException(className + " not found");
    }
    return jClass;
}

jmethodID JVM::VM::getMethodId(JNIEnv *env, jclass jClass, std::string methodName, std::string methodSignature) {
    jmethodID methodId = env->GetMethodID(jClass, methodName.c_str(), methodSignature.c_str());
    if (methodId == nullptr) {
        std::cerr << "JVM method " << methodName << " not found" << std::endl;
        throw MethodNotFoundException(methodName + " not found");
    }
    return methodId;
}

jmethodID JVM::VM::getStaticMethodId(JNIEnv *env, jclass jClass, std::string methodName, std::string methodSignature) {
    jmethodID methodId = env->GetStaticMethodID(jClass, methodName.c_str(), methodSignature.c_str());
    if (methodId == nullptr) {
        std::cerr << "JVM static method " << methodName << " not found";
        throw MethodNotFoundException(methodName + " not found");
    }
    return methodId;
}

JNIEnv *JVM::VM::attachCurrentThread() {
    JNIEnv *env;
    getJVM()->AttachCurrentThread((void **) &env, nullptr);
    return env;
}

void JVM::VM::detachCurrentThread() {
    getJVM()->DetachCurrentThread();
}
