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

#include <exception>
#include <stdexcept>

class JVMException {
public:
    explicit JVMException(std::string reason);

    std::string what() const { return pMessage; }

private:
    std::string pMessage;
};

class ClassNotFoundException : public JVMException {
public:
    explicit ClassNotFoundException(const std::string &reason);
};

class MethodNotFoundException : public JVMException {
public:
    explicit MethodNotFoundException(const std::string &reason);
};