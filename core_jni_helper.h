//
// Created by xshx on 2022/11/4.
//

#ifndef ANDRUNTIME_CORE_JNI_HELPER_JAVA_H
#define ANDRUNTIME_CORE_JNI_HELPER_JAVA_H
#include "AndroidRuntime.h"
#define NELEM(m) (sizeof(m) / sizeof((m)[0]))

static inline int RegisterMethodsOrDie(JNIEnv* env, const char* className,
                                       const JNINativeMethod* gMethods, int numMethods) {

    int res = AndroidRuntime::registerNativeMethods(env, className, gMethods, numMethods);
    if(res < 0){
        printf("Unable to register native methods.");
    }else{
        printf("registe native methods %s\n", className);
    }
    return res;
}
#endif //ANDRUNTIME_CORE_JNI_HELPER_JAVA_H
