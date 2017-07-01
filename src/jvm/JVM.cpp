#include "JVM.hpp"
#include <iostream>

static JNIEnv* jniEnv = nullptr;
static JavaVM *javaVM = nullptr;

bool JVM::createJavaVirtualMachine()
{
	std::cout << "Creating Java Virtual Machine..." << std::endl;

    if(!JVM::createJVM()) {
        return false;
    }
    if(!JVM::findAndExecuteMain()) {
        return false;
    }
    return true;
}

JNIEnv *JVM::getJNIEnv() {
	return jniEnv;
}

bool JVM::checkForException() {
    if(jniEnv->ExceptionCheck())
    {
        jthrowable throwable = jniEnv->ExceptionOccurred();
        jclass throwableCls = jniEnv->GetObjectClass(throwable);
        jmethodID printStackTraceId = jniEnv->GetMethodID(throwableCls, "printStackTrace", "()V");

        jniEnv->CallVoidMethod(throwable, printStackTraceId);
        jniEnv->ExceptionClear();
        return true;
    }
    return false;
}

bool JVM::findAndExecuteMain() {
    jclass jClass = jniEnv->FindClass(JVM_LAUNCHER_CLASS_NAME);
    if(jClass == NULL)
    {
        std::cout << "Couldn't find expected JVM main class" << std::endl;
        return false;
    }
    jmethodID methodId = jniEnv->GetStaticMethodID(jClass, JVM_LAUNCHER_METHOD_NAME, "()V");
    if (methodId == NULL)
    {
        std::cout << "Couldn't find expected JVM main method" << std::endl;
        return false;
    }
    jniEnv->CallStaticVoidMethod(jClass, methodId);
    if(checkForException()) {
        return false;
    }
    return true;
}

bool JVM::createJVM() {
    JavaVMInitArgs vm_args;
    JavaVMOption options[4];

    options[0].optionString = "-Djava.compiler=NONE";           /* disable JIT */
    options[1].optionString = "-Djava.class.path=./plugins/launcher.jar;"; /* user classes */
    options[2].optionString = "-Djava.library.path=./plugins/RageJava.dll";  /* set native library path */
    options[3].optionString = "-verbose:jni";                   /* print JNI-related messages */

    vm_args.version = JNI_VERSION_1_8;
    vm_args.options = options;
    vm_args.nOptions = 4;
    vm_args.ignoreUnrecognized = (jboolean)"true";

    /* Note that in the JDK/JRE, there is no longer any need to call
    * JNI_GetDefaultJavaVMInitArgs.
    */
    int res = JNI_CreateJavaVM(&javaVM, (void **)&jniEnv, &vm_args);
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
        }
        javaVM->DestroyJavaVM();
        return false;
    }
    else {
        printf("JVM created successfully");
        return true;
    }
}
