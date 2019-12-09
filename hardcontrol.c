/* gcc -I/usr/lib/jvm/java-1.7.0-openjdk-amd64/include/ -fPIC -shared -o libnative.so native.c  */


#include <stdio.h>
#include <jni.h> /* /usr/lib/jvm/java-1.7.0-openjdk-amd64/include/ */
#include <stdlib.h>

#include <android/log.h> /* liblog */

//__android_log_printf(ANDROID_LOG_DEBUG, "JNIDemo","native add ...");

#if 0
typedef struct {
    char *name;          /* Java里调用的函数名 */
    char *signature;    /* JNI字段描述符, 用来表示Java里调用的函数的参数和返回值类型 */
    void *fnPtr;          /* C语言实现的本地函数 */
} JNINativeMethod;
#endif


jint ledOpen(JNIEnv *env, jclass cls)
{	
	__android_log_print(ANDROID_LOG_DEBUG, "ledOpen","native ledOpen ...");
	return 0;
}

void ledClose(JNIEnv *env, jclass cls)
{	
	__android_log_print(ANDROID_LOG_DEBUG, "ledClose","native ledClose ...");
}

jint ledCtrl(JNIEnv *env, jclass cls,jint which, jint status)
{	
	__android_log_print(ANDROID_LOG_DEBUG, "ledCtrl","native ledCtrl: %d %d",which,status);
	return 0;
}

static const JNINativeMethod methods[] = {
	{"ledOpen", "()I", (void *)ledOpen},
	{"ledClose", "()V", (void *)ledClose},
	{"ledCtrl", "(II)I", (void *)ledCtrl},
};


/* System.loadLibrary */
JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM *jvm, void *reserved)
{
	 JNIEnv *env;
	 jclass cls;
	 
	 if ((*jvm)->GetEnv(jvm, (void **)&env, JNI_VERSION_1_4)) {
	 	return JNI_ERR; /* JNI version not supported */
	 }
	 cls = (*env)->FindClass(env, "com/example/andylu/hardlibrary/HardControl");
	 if (cls == NULL) {
	 	return JNI_ERR;
	 }

	 /* 2. map java hello <-->c  c_hello */

	if((*env)->RegisterNatives(env, cls, methods, sizeof(methods)/sizeof(methods[0])) < 0)
		return JNI_ERR;
	
	 return JNI_VERSION_1_4;
}

