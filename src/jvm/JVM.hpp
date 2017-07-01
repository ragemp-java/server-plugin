#ifndef RAGEJAVA_JVM_HPP
#define RAGEJAVA_JVM_HPP

#include "jni.h"

const char JVM_LAUNCHER_CLASS_NAME[] = "de/demofire/ragemultiplayer/launcher/Main";
const char JVM_LAUNCHER_METHOD_NAME[] = "main";

class JVM
{
public:
	static bool createJavaVirtualMachine();
	static JNIEnv* getJNIEnv();
	static bool checkForException();
private:
	static bool findAndExecuteMain();
	static bool createJVM();
};

#endif //RAGEJAVA_JVM_HPP
