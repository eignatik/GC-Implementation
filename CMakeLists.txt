cmake_minimum_required(VERSION 3.6)
project(garbagecollector)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main/main.cpp main/util/PropertiesUtil.cpp main/util/PropertiesUtil.h main/util/Logger.cpp main/util/Logger.h main/gc/GC.cpp main/gc/GC.h main/gc/core/GCProperties.cpp main/gc/core/GCProperties.h main/gc/core/mappers/PropertiesMapper.cpp main/gc/core/mappers/PropertiesMapper.h)
add_executable(garbagecollector ${SOURCE_FILES})