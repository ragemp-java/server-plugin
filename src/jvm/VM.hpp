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

#ifdef __unix__
static const int OS = 0;
#define LINUX
#elif defined(_WIN32) || defined(WIN32)
static const int OS = 1;
#define WINDOWS
#else
static const int OS = -1;
#endif


const std::string JVM_LAUNCHER_MAIN_PACKAGE_NAME = "mp/rage/launcher/";
const std::string JVM_API_MAIN_PACKAGE_NAME = "mp/rage/api/";
const std::string JVM_LAUNCHER_CLASS_NAME = JVM_LAUNCHER_MAIN_PACKAGE_NAME + "Launcher";
const std::string JVM_LAUNCHER_METHOD_NAME = "main";

namespace JVM {

    class VM {
    public:
        static bool create();

        static JavaVM *getJVM();

        static bool checkForException(JNIEnv *env, bool detachAfterCheck = false);

        static jclass getClass(JNIEnv *env, std::string className);

        static jmethodID getMethodId(JNIEnv *env, jclass jClass, std::string methodName, std::string methodSignature);

        static jmethodID getStaticMethodId(JNIEnv *env, jclass jClass, std::string methodName, std::string methodSignature);

        static JNIEnv *attachCurrentThread();

        static void detachCurrentThread();

    private:
        static bool findAndExecuteMain(JNIEnv *env);

        static bool createJVM();

        static std::vector<char *> readJVMConfiguration();
    };
}