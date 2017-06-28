#include "JVM.hpp"
#include <iostream>

JNIEnv* JVM::createJavaVirtualMachine()
{
	JavaVM *javaVM;
	JNIEnv *jniEnv;
	JavaVMInitArgs vm_args;
	JavaVMOption options[4];

	options[0].optionString = "-Djava.compiler=NONE";           /* disable JIT */
	options[1].optionString = "-Djava.class.path=./plugins/launcher.jar;"; /* user classes */
	options[2].optionString = "-Djava.library.path=./plugins/RageJava.dll";  /* set native library path */
	options[3].optionString = "-verbose:jni";                   /* print JNI-related messages */

	vm_args.version = JNI_VERSION_1_8;
	vm_args.options = options;
	vm_args.nOptions = 4;
	vm_args.ignoreUnrecognized = true;

	/* Note that in the JDK/JRE, there is no longer any need to call
	* JNI_GetDefaultJavaVMInitArgs.
	*/
	std::cout << "init jvm..." << std::endl;
	auto res = JNI_CreateJavaVM(&javaVM, (void **)&jniEnv, &vm_args);
	std::cout << res << " result" << std::endl;
	jclass jcls = jniEnv->FindClass("de/demofire/ragemultiplayer/launcher/Main");
	if(jcls == NULL)
	{
		std::cout << "class is null" << std::endl;
		return nullptr;
	}
	std::cout << "class found" << std::endl;
	jmethodID methodId = jniEnv->GetStaticMethodID(jcls, "main", "()V");
	if (methodId == NULL)
	{
		std::cout << "method is null" << std::endl;
		return nullptr;
	}
	jniEnv->CallStaticVoidMethod(jcls, methodId);
	if(jniEnv->ExceptionCheck())
	{
		auto throwable = jniEnv->ExceptionOccurred();
		auto throwableCls = jniEnv->GetObjectClass(throwable);
		auto printStackTraceId = jniEnv->GetMethodID(throwableCls, "printStackTrace", "()V");
		

		jniEnv->CallVoidMethod(throwable, printStackTraceId);
		jniEnv->ExceptionClear();
	}
	//options[0].optionString = "-Djava.class.path=C:\\Users\\Fabian Jungwirth\\IdeaProjects\\javaruntimeparent\\java-runtime-launcher\\target";
	/*JavaVMOption jvmopt[1];
	jvmopt[0].optionString = "-Djava.class.path=.";

	JavaVMInitArgs vmArgs;
	vmArgs.version = JNI_VERSION_1_2;
	vmArgs.nOptions = 1;
	vmArgs.options = jvmopt;
	vmArgs.ignoreUnrecognized = JNI_TRUE;

	// Create the JVM
	JavaVM *javaVM;
	JNIEnv *jniEnv;
	JNI_CreateJavaVM(&javaVM, reinterpret_cast<void**>(&jniEnv), &vmArgs);*/
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
