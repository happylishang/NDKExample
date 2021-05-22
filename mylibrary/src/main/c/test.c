#include <jni.h>
#include <assert.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

JNIEXPORT   jstring   digest(JNIEnv *env, jobject jobject,
                             jstring tc) {
    return tc;
}
static const char *classPathName = "com/netease/mylibrary/JNIUtil";
static JNINativeMethod methods[] = {
        {"md5Digest", "(Ljava/lang/String;)Ljava/lang/String;", (void *) digest},
};

static int registerNatives(JNIEnv *env) {
    jclass  clazz = (*env)->FindClass(env, classPathName);
    if (clazz == NULL)
        return JNI_FALSE;
    if ((*env)->RegisterNatives(env, clazz, methods, sizeof (methods) / sizeof(methods[0])) < 0) {
        return JNI_FALSE;
    }
    return JNI_TRUE;
}
//加载入口
jint JNI_OnLoad(JavaVM *vm, void *reserved) {
    JNIEnv *env = NULL;
    jint result = -1;
    if ((*vm)->GetEnv(vm, (void **) &env, JNI_VERSION_1_4) != JNI_OK)
        goto bail;
    //注册本地方法
    if (!registerNatives(env))
        goto bail;
    result = JNI_VERSION_1_4;
    bail:
    return result;
}
