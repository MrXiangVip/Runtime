//
// Created by xshx on 2022/11/4.
//
#include <jni.h>
#include "core_jni_helper.h"

//#define NELEM(m) (sizeof(m) / sizeof((m)[0]))
jstring fun1(JNIEnv *jniEnv, jobject jobject1){
    return (jniEnv)->NewStringUTF("我是Native方法sayHello的实现你好");
};

jstring fun2(JNIEnv *jniEnv, jobject jobject1){
    return (jniEnv)->NewStringUTF("我是Native方法sayBye的实现拜拜");
};
static const JNINativeMethod gMethods[] = {

        {"sayHello","()Ljava/lang/String;", (void*)fun1},
        {"sayBye","()Ljava/lang/String;",   (void*)fun2}
};
int register_com_android_internal_os_Zygote(JNIEnv* env) {
    printf("registe zygote methods \n");
    return RegisterMethodsOrDie(env, "com/wave/os/Zygote", gMethods, NELEM(gMethods));

//    return 0;
}