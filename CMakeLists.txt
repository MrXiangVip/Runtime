cmake_minimum_required(VERSION 3.15)
project(AndRuntime)

set(CMAKE_CXX_STANDARD 14)
include_directories(/usr/lib/jvm/java-8-openjdk-amd64/include  /usr/lib/jvm/java-8-openjdk-amd64/include/linux)
link_directories(/usr/lib/jvm/java-8-openjdk-amd64/jre/lib/amd64/server)

add_executable(AndRuntime main.cpp AndroidRuntime.cpp com_wave_os_Zygote.cpp)
target_link_libraries(AndRuntime jvm)
