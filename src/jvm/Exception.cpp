/*
 * Copyright (c) 2017 Noxaro aka Fabian Jungwirth
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 3.0 of the License, or (at your option) any later version.
 * See the file COPYING included with this distribution for more information.
 */

#include "Exception.hpp"

static jclass notImplementedExceptionClass;
static jclass playerNotFoundExceptionClass;
static jclass vehicleNotFoundExceptionClass;
static jclass jniExecutionExceptionClass;
static jclass checkpointNotFoundExceptionClass;

void JVM::Exception::initialize(JNIEnv *env) {
    notImplementedExceptionClass = JVM::VM::getClass(env, "mp/rage/api/exception/NotImplementedException");
    jniExecutionExceptionClass = JVM::VM::getClass(env,"mp/rage/api/exception/JNIExecutionException");
    playerNotFoundExceptionClass = JVM::VM::getClass(env,"mp/rage/api/exception/game/PlayerNotFoundException");
    vehicleNotFoundExceptionClass = JVM::VM::getClass(env,"mp/rage/api/exception/game/VehicleNotFoundException");
    checkpointNotFoundExceptionClass = JVM::VM::getClass(env,"mp/rage/api/exception/game/CheckpointNotFoundException");
}

void JVM::Exception::throwNotImplementedException(JNIEnv *env, std::string reason) {
    env->ThrowNew(notImplementedExceptionClass, reason.c_str());
}

void JVM::Exception::throwPlayerNotFoundException(JNIEnv *env, int playerId) {
    env->ThrowNew(playerNotFoundExceptionClass, std::to_string(playerId).c_str());
}

void JVM::Exception::throwVehicleNotFoundException(JNIEnv *env, int vehicleId) {
    env->ThrowNew(vehicleNotFoundExceptionClass, std::to_string(vehicleId).c_str());
}

void JVM::Exception::throwJNIExecutionException(JNIEnv *env, std::string reason) {
    env->ThrowNew(jniExecutionExceptionClass, reason.c_str());
}

void JVM::Exception::throwCheckpointNotFoundException(JNIEnv *env, int checkpointId) {
    env->ThrowNew(checkpointNotFoundExceptionClass, std::to_string(checkpointId).c_str());
}

