#include "JVM.hpp"

static JNIEnv *jniEnv = nullptr;
static JavaVM *javaVM = nullptr;

JNIEnv *JVM::getJNIEnv() {
    return jniEnv;
}

JavaVM *JVM::getJVM() {
    return javaVM;
}

bool JVM::createJavaVirtualMachine() {
    std::cout << "Creating Java Virtual Machine ... ";

    if (!JVM::createJVM()) {
        return false;
    }
    if (!JVM::findAndExecuteMain()) {
        return false;
    }
    return true;
}

bool JVM::checkForException() {
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

bool JVM::findAndExecuteMain() {
    jclass jClass = jniEnv->FindClass(JVM_LAUNCHER_CLASS_NAME.c_str());
    if (jClass == NULL) {
        std::cout << std::endl << "Couldn't find expected JVM main class" << std::endl;
        return false;
    }
    jmethodID methodId = jniEnv->GetStaticMethodID(jClass, JVM_LAUNCHER_METHOD_NAME.c_str(), "()V");
    if (methodId == NULL) {
        std::cout << std::endl << "Couldn't find expected JVM main method" << std::endl;
        return false;
    }
    jniEnv->CallStaticVoidMethod(jClass, methodId);
    if (checkForException()) {
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
    options[3].optionString = "";//"-verbose:jni";                   /* print JNI-related messages */

    vm_args.version = JNI_VERSION_1_8;
    vm_args.options = options;
    vm_args.nOptions = 4;
    vm_args.ignoreUnrecognized = (jboolean) "true";

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
        }
        javaVM->DestroyJavaVM();
        return false;
    } else {
        std::cout << "[OK]" << std::endl;
        return true;
    }
}

jclass JVM::getClass(std::string className) {
    JNIEnv *env = JVM::getJNIEnv();
    jclass jClass = env->FindClass(className.c_str());
    if (jClass == nullptr) {
        throw ClassNotFoundException(className + " not found");
    }
    return jClass;
}

jmethodID JVM::getStaticMethod(jclass jClass, std::string methodName, std::string methodSignature) {
    JNIEnv *env = JVM::getJNIEnv();
    jmethodID methodId = env->GetStaticMethodID(jClass, methodName.c_str(), methodSignature.c_str());
    if (methodId == nullptr) {
        throw MethodNotFoundException(methodName + " not found");
    }
    return methodId;
}