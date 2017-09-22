cmake_minimum_required(VERSION 3.6)
project(garbagecollector)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main/main.cpp main/util/PropertiesUtil.cpp main/util/PropertiesUtil.h main/util/Logger.cpp main/util/Logger.h test/testSample.h)
add_executable(garbagecollector ${SOURCE_FILES})