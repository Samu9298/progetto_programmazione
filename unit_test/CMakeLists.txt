cmake_minimum_required(VERSION 3.22)

add_subdirectory(./lib/googletest)
set(${gtest_SOURCE_DIR} ./lib/googletest/googletest)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

set(TEST_SOURCE_FILES runAllTest.cpp
        BankAccountTest.cpp
        OperationFactoryTest.cpp
        AccountFactoryTest.cpp)

find_package(wxWidgets REQUIRED COMPONENTS net core base adv)
include(${wxWidgets_USE_FILE})
add_executable(runAllTest ${TEST_SOURCE_FILES})
target_link_libraries(runAllTest gtest gtest_main coreLibrary ${wxWidgets_LIBRARIES})