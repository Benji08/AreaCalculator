cmake_minimum_required(VERSION 3.21)
project(22l_proi_areacalculator_bartosz_pawlak)

set(CMAKE_CXX_STANDARD 14)

include_directories(AreaCalculatorLib)

add_library(AreaCalculatorLib AreaCalculatorLib/Circle.h AreaCalculatorLib/Circle.cpp AreaCalculatorLib/Square.h AreaCalculatorLib/Square.cpp)

add_executable(AreaCalculatorApp AreaCalculatorApp/AreaCalculatorApp.cpp)
target_link_libraries(AreaCalculatorApp PUBLIC AreaCalculatorLib)
message("CLion > Visual Studio ez")

#testy
include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
if(WIN32)
    # For Windows: Prevent overriding the parent project's compiler/linker settings
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
endif(WIN32)
FetchContent_MakeAvailable(googletest)

enable_testing()
add_executable(AreaCalculatorUnitTest AreaCalculatorUnitTest/AreaCalculatorUnitTest.cpp)
target_link_libraries(AreaCalculatorUnitTest PUBLIC gtest_main AreaCalculatorLib)

include(GoogleTest)
gtest_discover_tests(AreaCalculatorUnitTest)