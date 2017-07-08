#include "JVMException.hpp"

JVMException::JVMException(std::string reason): pMessage(reason) {}

ClassNotFoundException::ClassNotFoundException(const std::string &reason) : JVMException(reason) {}

MethodNotFoundException::MethodNotFoundException(const std::string &reason) : JVMException(reason) {}
