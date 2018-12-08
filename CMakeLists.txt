cmake_minimum_required(VERSION 3.5)
project("Elite")

if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/build/conanbuildinfo.cmake)
    include(${CMAKE_CURRENT_SOURCE_DIR}/build/conanbuildinfo.cmake)
else()
    include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
endif()
conan_basic_setup()

SET(VERSION_MAJOR "0")
SET(VERSION_MINOR "10")
SET(VERSION_PATCH "0")

# SET (CMAKE_BUILD_TYPE Release) # 默认构建Debug模式

# 寻找依赖项
find_package(LLVM REQUIRED CONFIG)
message(STATUS "Found LLVM ${LLVM_PACKAGE_VERSION}")
message(STATUS "Using LLVMConfig.cmake in: ${LLVM_DIR}")

include_directories(${LLVM_INCLUDE_DIRS})
add_definitions(${LLVM_DEFINITIONS})
llvm_map_components_to_libnames(llvm_libs
	support core irreader mc mcjit bitwriter x86codegen target)

find_package(BISON)
find_package(FLEX)

# 设定编译器版本和相关目录

set (CMAKE_CXX_STANDARD 14)
include_directories(src include header_libs)

set( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin )
set( CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib )
set( CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib )


file(GLOB_RECURSE source_files
        ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp
    )
list(REMOVE_ITEM  source_files  ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp)


# 生成库目标
add_library(${PROJECT_NAME} ${source_files})
add_executable(${PROJECT_NAME}_exe ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp)
# 链接库
target_link_libraries(${PROJECT_NAME}_exe ${PROJECT_NAME} ${llvm_libs})

# 指定动态库版本
# VERSION 动态库版本
# SOVERSION API版本
if (BUILD_SHARED_LIBS)
set_target_properties(${PROJECT_NAME} PROPERTIES VERSION ${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH} SOVERSION ${VERSION_MAJOR})
endif()

add_subdirectory(doc)
add_subdirectory(test)
add_subdirectory(runtime)