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

void JVM::Exception::throwNotImplementedException(std::string reason) {
    jclass clazz = VM::getJNIEnv()->FindClass("mp/rage/plugin/java/api/exception/NotImplementedException");
    VM::getJNIEnv()->ThrowNew(clazz, reason.c_str());
}

void JVM::Exception::throwPlayerNotFoundException(int playerId) {
    jclass clazz = VM::getJNIEnv()->FindClass("mp/rage/plugin/java/api/exception/PlayerNotFoundException");
    VM::getJNIEnv()->ThrowNew(clazz, std::to_string(playerId).c_str());
}