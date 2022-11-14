//
// Created by xshx on 2022/11/4.
//
#include "AndroidRuntime.h"
#include <vector>
/*static*/
#define NELEM(m) (sizeof(m) / sizeof((m)[0]))
#define REG_JNI(name)      { name, #name }

struct RegJNIRec {
    int (*mProc)(JNIEnv*);
    const char* mName;
};

extern "C"  int register_jni_procs(const RegJNIRec array[], size_t count, JNIEnv* env);
extern int register_com_android_internal_os_Zygote(JNIEnv *env);

static const RegJNIRec gRegJNI[] = {

        REG_JNI(register_com_android_internal_os_Zygote),

};

JavaVM* AndroidRuntime::mJavaVM = NULL;



AndroidRuntime::AndroidRuntime(char* argBlockStart, const int argBlockLength) {

//    gCurRuntime = this;


}
void AndroidRuntime::start(const char* className, const vector<string>& options, bool zygote) {

    printf("start \n");
    JNIEnv* env;

    if (startVm(&mJavaVM, &env, zygote) != 0) {
        return;
    }

    /*
     * Register android functions.
     */
    if (startReg(env) < 0) {
        printf("Unable to register all android natives\n");
        return;
    }else{
        printf("regist jni success\n");
    }

    jclass startClass  =(env)->FindClass( "com/wave/os/ZygoteInit");
    if( startClass ==NULL ){
        printf("JavaVM unable to locate class %s\n" ,className);
    }else{
        jmethodID startMeth =(env)->GetStaticMethodID( startClass, "main","([Ljava/lang/String;)V");
        if( startMeth == NULL ){
            printf("JavaVM unable to find main() in '%s'\n", className);
        } else{
            (env)->CallStaticVoidMethod(startClass, startMeth, NULL);
            printf("call zygoteinit main\n");
        }
    }
    printf("Shutting down VM\n");


}
int AndroidRuntime::startVm(JavaVM** pJavaVM, JNIEnv** pEnv, bool zygote){
    JavaVMInitArgs args;
    JavaVMOption options;
    args.version = JNI_VERSION_1_8;
    args.nOptions = 1;
    options.optionString ="-Djava.class.path=./";
    args.options = &options;
    args.ignoreUnrecognized = 0;
    printf("");
    if (JNI_CreateJavaVM(pJavaVM, (void**)pEnv, &args) < 0) {
        printf("Launch JVM Failed\n");

    } else{
        printf("Launch JVM ! :)\n");

    }

    return  0;
}
/*static*/ int AndroidRuntime::startReg(JNIEnv* env){
    if (register_jni_procs(gRegJNI, NELEM(gRegJNI), env) < 0) {
        return  -1;
    }
    return  0;
}

/*
 * Register native methods using JNI.
 */
/*static*/ int AndroidRuntime::registerNativeMethods(JNIEnv* env,
                                                     const char* className, const JNINativeMethod* gMethods, int numMethods)
{
//    return jniRegisterNativeMethods(env, className, gMethods, numMethods);
//    return registerNativeMethods(env, className, gMethods, numMethods);

    jclass clazz;
    clazz = env->FindClass(className);
    if (clazz == NULL) {
        return JNI_FALSE;
    }
    if (env->RegisterNatives(clazz, gMethods, numMethods) < 0) {
        return JNI_FALSE;
    }

    return JNI_TRUE;
}



AndroidRuntime::~AndroidRuntime()
{
}


int register_jni_procs(const RegJNIRec array[], size_t count, JNIEnv* env)
{
    for (size_t i = 0; i < count; i++) {
        if (array[i].mProc(env) < 0) {

            return -1;
        }
    }
    return 0;
}

