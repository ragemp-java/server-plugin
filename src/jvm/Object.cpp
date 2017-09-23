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

static jclass arrayListClass;
static jmethodID arrayListConstructor;
static jmethodID arrayListAddMethod;

void JVM::Object::initialize() {
    vector3Class = VM::getClass("mp/rage/plugin/java/api/vector/Vector3");
    vector3Constructor = VM::getJNIEnv()->GetMethodID(vector3Class, "<init>", "(FFF)V");

//    playerHeadBlendClass = VM::getJNIEnv()->FindClass("mp/rage/plugin/java/api/player/PlayerHeadBlend");
//    playerHeadBlendConstructor = VM::getJNIEnv()->GetMethodID(playerHeadBlendClass, "<init>", "(IIFFF)V");

    rgbColorClass = VM::getJNIEnv()->FindClass("mp/rage/plugin/java/api/color/RGBColor");
    rgbColorConstructor = VM::getJNIEnv()->GetMethodID(rgbColorClass, "<init>", "(III)V");

    arrayListClass = VM::getJNIEnv()->FindClass("java/util/ArrayList");
    arrayListConstructor = VM::getJNIEnv()->GetMethodID(arrayListClass, "<init>", "(I)V");
    arrayListAddMethod = VM::getJNIEnv()->GetMethodID(arrayListClass, "add","(Ljava/lang/Object;)Z");
}

jobject JVM::Object::vector3(float x, float y, float z) {
    return VM::getJNIEnv()->NewObject(vector3Class, vector3Constructor, x, y, z);
}

jobject JVM::Object::playerHeadBlend(int shape, int skin, float shapeMix, float skinMix, float thirdMix) {
    return VM::getJNIEnv()->NewObject(playerHeadBlendClass, playerHeadBlendConstructor, shape, skin, shapeMix, skinMix, thirdMix);
}

jobject JVM::Object::rgbColor(int red, int green, int blue) {
    return VM::getJNIEnv()->NewObject(rgbColorClass, rgbColorConstructor, red, green, blue);
}

jobject JVM::Object::intArrayList(std::vector<int> ids) {
    jobject arrayList = VM::getJNIEnv()->NewObject(arrayListClass, arrayListConstructor, ids.size());

    for (int id : ids) {
        VM::getJNIEnv()->CallObjectMethod(arrayList, arrayListAddMethod, id);
    }
    return arrayList;
}