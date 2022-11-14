#include <iostream>
#include "AndroidRuntime.h"
#include <vector>

using namespace std;
class AppRuntime : public AndroidRuntime{
public:
    AppRuntime(char* argBlockStart, const size_t argBlockLength): AndroidRuntime(argBlockStart, argBlockLength) {
        ;
    }
};


int main(int argc, char* const argv[]){
    std::cout << "Hello, World!" << std::endl;
    AppRuntime runtime(argv[0], argc);

    bool zygote = true;
    vector<std::string> args;

    if( zygote ){
        runtime.start("com.wave.os.ZygoteInit", args, zygote);

    }
    return 0;
}
