cmake_minimum_required(VERSION 3.17)
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

set(SOURCE_FILES runAllTests.cpp chatTest.cpp messageNotificationTest.cpp messageTest.cpp userTest.cpp)
add_executable(runAllTests.cpp ${SOURCE_FILES})
target_link_libraries(runAllTests.cpp ${GTEST_BOTH_LIBRARIES} core pthread)