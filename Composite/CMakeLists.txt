cmake_minimum_required(VERSION 3.11.0)
project(composite VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# include(FetchContent)
# FetchContent_Declare(
#    googletest
#    GIT_REPOSITORY      https://github.com/google/googletest.git
#    GIT_TAG main
# )
# FetchContent_MakeAvailable(googletest)


set(SOURCES src/CombatUnit.h src/CombatGroup.h src/Legionary.h src/Pretorian.h src/Maniple.h)
add_executable(composite main.cpp ${SOURCES})


# add_executable(testShapes tests/testShapes.cpp tests/testLinkedList.cpp tests/testShapesCollection.cpp ${SOURCES})
# target_link_libraries(testShapes PUBLIC gtest_main)