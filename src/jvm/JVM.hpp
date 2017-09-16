/*
 * Copyright (c) 2017 Noxaro aka Fabian Jungwirth
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 3.0 of the License, or (at your option) any later version.
 * See the file COPYING included with this distribution for more information.
 */

#pragma once

#include <string>
#include <iostream>
#include "jni.h"
#include "JVMException.hpp"


const std::string JVM_LAUNCHER_MAIN_PACKAGE_NAME = "mp/rage/plugin/java/launcher/";
const std::string JVM_LAUNCHER_CLASS_NAME = JVM_LAUNCHER_MAIN_PACKAGE_NAME + "Launcher";
const std::string JVM_LAUNCHER_METHOD_NAME = "main";

class JVM {
public:
    static bool createJavaVirtualMachine();

    static JNIEnv *getJNIEnv();

    static JavaVM *getJVM();

    static bool checkForException();

    static jclass getClass(std::string className);

    static jmethodID getStaticMethod(jclass jClass, std::string methodName, std::string methodSignature);

    static jobject createVector3(float x, float y, float z);

private:
    static bool findAndExecuteMain();

    static bool createJVM();
};