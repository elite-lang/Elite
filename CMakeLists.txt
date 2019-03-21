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
# include(${CONAN_LLVM_ROOT}/lib/cmake/llvm/LLVMConfig.cmake)

# if(NOT LLVM_INSTALL_PREFIX)
#     message(FATAL_ERROR "ERROR! LLVM NOT FOUND!")
# endif()

# message(STATUS "Found LLVM ${LLVM_PACKAGE_VERSION}")
# message(STATUS "Using LLVMConfig.cmake in: ${LLVM_DIR}")

# include_directories(${LLVM_INCLUDE_DIRS})
# add_definitions(${LLVM_DEFINITIONS})
# llvm_map_components_to_libnames(llvm_libs
# 	support core irreader mc mcjit bitwriter x86codegen target)


## Flex/Bison configuration 
find_package(BISON REQUIRED)
find_package(FLEX REQUIRED)

if (WIN32)
    set (ADDITIONAL_FLEX_FLAGS "--wincompat")
else()
    set (ADDITIONAL_FLEX_FLAGS "")
endif()
FLEX_TARGET(SCANNER ${CMAKE_CURRENT_SOURCE_DIR}/src/Parser/scanner.l
${CMAKE_CURRENT_BINARY_DIR}/scanner.cpp DEFINES_FILE ${CMAKE_CURRENT_BINARY_DIR}/scanner.h COMPILE_FLAGS ${ADDITIONAL_FLEX_FLAGS})
BISON_TARGET(PARSER ${CMAKE_CURRENT_SOURCE_DIR}/src/Parser/parser.y
${CMAKE_CURRENT_BINARY_DIR}/parser.cpp COMPILE_FLAGS "-d -v")
ADD_FLEX_BISON_DEPENDENCY(SCANNER PARSER)

# 设定编译器版本和相关目录

set (CMAKE_CXX_STANDARD 14)
add_definitions(-D_GLIBCXX_USE_CXX11_ABI=0) ## It's important for gtest

SET (CMAKE_CXX_FLAGS_DEBUG "-g -D_GLIBCXX_DEBUG")
SET (CMAKE_CXX_FLAGS_MINSIZEREL "-Os -DNDEBUG")
SET (CMAKE_CXX_FLAGS_RELEASE "-O3 -DNDEBUG")
SET (CMAKE_CXX_FLAGS_RELWITHDEBINFO "-O2 -g")

include_directories(src include header_libs)

set( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin )
set( CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib )
set( CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib )


# file(GLOB_RECURSE source_files
#         ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp
#     )
file(GLOB source_files 
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Model/*.cpp
)
list(REMOVE_ITEM source_files  ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp)

# 生成库目标
add_library(${PROJECT_NAME} ${source_files} ${BISON_PARSER_OUTPUTS} ${FLEX_SCANNER_OUTPUTS})
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