//
// Created by xshx on 2022/11/4.
//

#ifndef ANDRUNTIME_ANDROIDRUNTIME_H
#define ANDRUNTIME_ANDROIDRUNTIME_H

#include <vector>
#include <string>
#include <jni.h>

using namespace std;
class AndroidRuntime {
public:
    AndroidRuntime(char *argBlockStart, int argBlockSize);

    virtual ~AndroidRuntime();

    void start(const char *classname, const vector<string> &options, bool zygote);

    int startVm(JavaVM **pJavaVM, JNIEnv **pEnv, bool zygote);
    /**
     * Register a set of methods in the specified class.
     */
    static int registerNativeMethods(JNIEnv* env,
                                     const char* className, const JNINativeMethod* gMethods, int numMethods);
private:
    static JavaVM *mJavaVM;
    static int startReg(JNIEnv* env);

};



#endif //ANDRUNTIME_ANDROIDRUNTIME_H
