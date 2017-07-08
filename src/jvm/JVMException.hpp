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