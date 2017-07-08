#pragma once

#include <exception>
#include <stdexcept>

class JVMException {
public:
    JVMException(std::string reason);

    std::string what() const { return pMessage; }

private:
    std::string pMessage;
};


class ClassNotFoundException: public JVMException {
public:
    ClassNotFoundException(const std::string &reason);
};

class MethodNotFoundException: public JVMException {
public:
    MethodNotFoundException(const std::string &reason);
};