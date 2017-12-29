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

#include <jni.h>
#include "VM.hpp"
#include <exception>
#include <stdexcept>

namespace JVM {
    class Exception {
    public:
        static void throwNotImplementedException(std::string reason);

        static void throwPlayerNotFoundException(int playerId);

        static void throwVehicleNotFoundException(int vehicleId);

        static void throwJNIExecutionException(std::string reason);

        static void throwCheckpointNotFoundException(int checkpointId);
    };


}

class JNIException {
public:
    explicit JNIException(std::string reason) : pMessage(reason) {}

    std::string what() const { return pMessage; }

private:
    std::string pMessage;
};

class ClassNotFoundException : public JNIException {
public:
    explicit ClassNotFoundException(const std::string &reason) : JNIException(reason) {}
};

class MethodNotFoundException : public JNIException {
public:
    explicit MethodNotFoundException(const std::string &reason) : JNIException(reason) {}
};