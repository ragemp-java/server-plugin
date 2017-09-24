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
#include "Exception.hpp"
#include "Object.hpp"


const std::string JVM_LAUNCHER_MAIN_PACKAGE_NAME = "mp/rage/launcher/";
const std::string JVM_API_MAIN_PACKAGE_NAME = "mp/rage/api/";
const std::string JVM_LAUNCHER_CLASS_NAME = JVM_LAUNCHER_MAIN_PACKAGE_NAME + "Launcher";
const std::string JVM_LAUNCHER_METHOD_NAME = "main";

namespace JVM {

    class VM {
    public:
        static bool create();

        static JNIEnv *getJNIEnv();

        static JavaVM *getJVM();

        static bool checkForException();

        static jclass getClass(std::string className);

        static jmethodID getMethodId(jclass jClass, std::string methodName, std::string methodSignature);

        static jmethodID getStaticMethodId(jclass jClass, std::string methodName, std::string methodSignature);

    private:
        static bool findAndExecuteMain();

        static bool createJVM();

    };
}