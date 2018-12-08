enable_testing()
find_package(GTest REQUIRED)

include_directories (${CMAKE_CURRENT_SOURCE_DIR})
include_directories (${GTEST_INCLUDE_DIRS})
file(GLOB_RECURSE test_source_files ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

add_executable (all_test ${test_source_files})

if (WIN32)
	set(PTHREAD "")
else()
	set(PTHREAD pthread)
endif()

target_link_libraries(all_test
                        ${PROJECT_NAME}
                        ${GTEST_BOTH_LIBRARIES}
                        ${PTHREAD})

add_test(AllTest all_test)

add_custom_target( runtest ALL
                   DEPENDS all_test)

add_custom_command(TARGET runtest
                   POST_BUILD
                   COMMAND all_test)
