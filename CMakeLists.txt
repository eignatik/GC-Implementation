cmake_minimum_required(VERSION 3.6)
project(garbagecollector)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp util/PropertiesUtil.cpp util/PropertiesUtil.h util/Logger.cpp util/Logger.h)
add_executable(garbagecollector ${SOURCE_FILES})