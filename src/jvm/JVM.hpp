#ifndef RAGEJAVA_JVM_HPP
#define RAGEJAVA_JVM_HPP

#include "jni.h"

class JVM
{
public:
	static JNIEnv* createJavaVirtualMachine();
};

#endif //RAGEJAVA_JVM_HPP
