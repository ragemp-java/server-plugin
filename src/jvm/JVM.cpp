#include "JVM.hpp"
#include <iostream>


JNIEnv* JVM::createJavaVirtualMachine()
{
	//options[0].optionString = "-Djava.class.path=C:\\Users\\Fabian Jungwirth\\IdeaProjects\\javaruntimeparent\\java-runtime-launcher\\target";
	JavaVMOption jvmopt[1];
	jvmopt[0].optionString = "-Djava.class.path=.";

	JavaVMInitArgs vmArgs;
	vmArgs.version = JNI_VERSION_1_2;
	vmArgs.nOptions = 1;
	vmArgs.options = jvmopt;
	vmArgs.ignoreUnrecognized = JNI_TRUE;

	// Create the JVM
	JavaVM *javaVM;
	JNIEnv *jniEnv;
	JNI_CreateJavaVM(&javaVM, reinterpret_cast<void**>(&jniEnv), &vmArgs);
	/*if (flag == JNI_ERR) {
		std::cout << "Error creating VM. Exiting...\n";
		return nullptr;
	}

	jclass jcls = jniEnv->FindClass("org/jnijvm/Demo");
	if (jcls == NULL) {
		jniEnv->ExceptionDescribe();
		javaVM->DestroyJavaVM();
		return nullptr;
	}
	if (jcls != NULL) {
		jmethodID methodId = jniEnv->GetStaticMethodID(jcls, "greet", "(Ljava/lang/String;)V");
		if (methodId != NULL) {
			jstring str = jniEnv->NewStringUTF("10");
			jniEnv->CallStaticVoidMethod(jcls, methodId, str);
			if (jniEnv->ExceptionCheck()) {
				jniEnv->ExceptionDescribe();
				jniEnv->ExceptionClear();
			}
		}
	}*/

	//javaVM->DestroyJavaVM();
	return nullptr; 
}
