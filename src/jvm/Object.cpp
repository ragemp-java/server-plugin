/*
 * Copyright (c) 2017 Noxaro aka Fabian Jungwirth
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 3.0 of the License, or (at your option) any later version.
 * See the file COPYING included with this distribution for more information.
 */

#include "Object.hpp"

static jclass vector3Class;
static jmethodID vector3Constructor;

static jclass playerHeadBlendClass;
static jmethodID playerHeadBlendConstructor;

static jclass rgbColorClass;
static jmethodID rgbColorConstructor;

static jclass rgbaColorClass;
static jmethodID rgbaColorConstructor;

static jclass arrayListClass;
static jmethodID arrayListConstructor;
static jmethodID arrayListAddMethod;

void JVM::Object::initialize(JNIEnv *env) {
    vector3Class = VM::getClass(env, JVM_API_MAIN_PACKAGE_NAME + "vector/Vector3");
    vector3Constructor = VM::getMethodId(env, vector3Class, "<init>", "(FFF)V");

//    playerHeadBlendClass = VM::getClass("mp/game/plugin/java/api/player/PlayerHeadBlend");
//    playerHeadBlendConstructor = env->GetMethodID(playerHeadBlendClass, "<init>", "(IIFFF)V");

    rgbColorClass = VM::getClass(env, JVM_API_MAIN_PACKAGE_NAME + "color/RGBColor");
    rgbColorConstructor = VM::getMethodId(env, rgbColorClass, "<init>", "(III)V");

    rgbaColorClass = VM::getClass(env, JVM_API_MAIN_PACKAGE_NAME + "color/RGBAColor");
    rgbaColorConstructor = VM::getMethodId(env, rgbaColorClass, "<init>", "(IIII)V");

    arrayListClass = VM::getClass(env, "java/util/ArrayList");
    arrayListConstructor = VM::getMethodId(env, arrayListClass, "<init>", "(I)V");
    arrayListAddMethod = VM::getMethodId(env, arrayListClass, "add","(Ljava/lang/Object;)Z");
}

jobject JVM::Object::vector3(JNIEnv *env, float x, float y, float z) {
    return env->NewObject(vector3Class, vector3Constructor, x, y, z);
}

jobject JVM::Object::playerHeadBlend(JNIEnv *env, int shape, int skin, float shapeMix, float skinMix, float thirdMix) {
    return env->NewObject(playerHeadBlendClass, playerHeadBlendConstructor, shape, skin, shapeMix, skinMix, thirdMix);
}

jobject JVM::Object::rgbColor(JNIEnv *env, int red, int green, int blue) {
    return env->NewObject(rgbColorClass, rgbColorConstructor, red, green, blue);
}

jobject JVM::Object::rgbaColor(JNIEnv *env, int red, int green, int blue, int alpha) {
    return env->NewObject(rgbColorClass, rgbColorConstructor, red, green, blue, alpha);
}

jobject JVM::Object::intArrayList(JNIEnv *env, std::vector<int> ids) {
    jobject arrayList = env->NewObject(arrayListClass, arrayListConstructor, ids.size());

    for (int id : ids) {
        env->CallObjectMethod(arrayList, arrayListAddMethod, id);
    }
    return arrayList;
}