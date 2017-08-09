#pragma once

#include <string>
#include <iostream>
#include "jni.h"
#include "JVMException.hpp"


const std::string JVM_LAUNCHER_MAIN_PACKAGE_NAME = "de/demofire/ragemultiplayer/launcher/";
const std::string JVM_LAUNCHER_CLASS_NAME = JVM_LAUNCHER_MAIN_PACKAGE_NAME + "Main";
const std::string JVM_LAUNCHER_METHOD_NAME = "main";

class JVM {
public:
    static bool createJavaVirtualMachine();

    static JNIEnv *getJNIEnv();

    static JavaVM *getJVM();

    static bool checkForException();

    static jclass getClass(std::string className);

    static jmethodID getStaticMethod(jclass jClass, std::string methodName, std::string methodSignature);

private:
    static bool findAndExecuteMain();

    static bool createJVM();
};