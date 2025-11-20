# ! ------------------------------------------------------------------ !
# ! Changing this file incorrectly can cause your program to not build !
# ! If you don't know CMake well DO NOT touch this file                !
# ! ------------------------------------------------------------------ !

cmake_minimum_required(VERSION 3.20)
project(OOP VERSION 0.1.0)
enable_testing()

set(CMAKE_CXX_STANDARD 17)


#### GTest
option(FETCH_GOOGLETEST "Download googletest source" ON)
if(FETCH_GOOGLETEST)
    # reference: https://google.github.io/googletest/quickstart-cmake.html
    include(FetchContent)
    FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG release-1.12.1
    )
    # For Windows: Prevent overriding the parent project's compiler/linker settings
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
    FetchContent_MakeAvailable(googletest)
else()
    message("Using custom googletest installation")
    # reference: https://cmake.org/cmake/help/latest/module/FindGTest.html
    find_package(GTest REQUIRED)
endif()

include(files.cmake)

set(SRC_DIR ${CMAKE_SOURCE_DIR}/src)
set(INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)
set(TEST_DIR ${CMAKE_SOURCE_DIR}/test)

list(TRANSFORM SRC_FILES PREPEND ${SRC_DIR}/)
list(TRANSFORM INCLUDE_FILES PREPEND ${INCLUDE_DIR}/)
list(TRANSFORM TEST_FILES PREPEND ${TEST_DIR}/)

find_program(MEMORYCHECK_COMMAND valgrind)
set(MEMORYCHECK_COMMAND_OPTIONS
    "--error-exitcode=1 --track-origins=yes --leak-check=full"
)
include(CTest)

option(COVERAGE "Enable coverage" OFF)

if(COVERAGE)
    set(CMAKE_C_FLAGS "--coverage -g -O0")
    set(CMAKE_CXX_FLAGS "--coverage -g -O0")

    include(scripts/CodeCoverage.cmake)
    set(CODE_COVERAGE_VERBOSE ON)
    set(COVERAGE_EXCLUDE
        ${CMAKE_BINARY_DIR}/_deps/*
        ${PROJECT_SOURCE_DIR}/test/*
    )

    if(CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
        set(GCOVR_ADDITIONAL_ARGS
            --gcov-executable "llvm-cov gcov"
        )
    endif()

    append_coverage_compiler_flags()
    setup_target_for_coverage_gcovr_html(
        NAME ut_all_coverage
        DEPENDENCIES ut_all
        EXCLUDE ${COVERAGE_EXCLUDE}
    )
endif()

if(MSVC)
    set(TARGET_COMPILER_OPTIONS
        /W4
    )
else()
    set(TARGET_COMPILER_OPTIONS
        -Wall -pedantic
    )
endif()

add_executable(ut_all
    ${SRC_FILES}
    ${INCLUDE_FILES}
    ${TEST_FILES}
)
target_link_libraries(ut_all
    GTest::gtest_main
)
target_include_directories(ut_all PRIVATE
    ${INCLUDE_DIR}
)
target_compile_options(ut_all PRIVATE
    ${TARGET_COMPILER_OPTIONS}
)

add_executable(ut_ore
        include/Ore/Ore.hpp
        include/Ore/SmeltableOre.hpp
        include/Ore/CoalOre.hpp
        include/Ore/IronOre.hpp
        include/Ore/GoldOre.hpp
        include/Ore/DiamondOre.hpp
        include/Ore/ObsidianOre.hpp
        include/Ore/Product.hpp
        include/Ore/BreakExp.hpp
        include/Ore/SmeltExp.hpp
        include/Ore/DurabilityCost.hpp
        src/Ore/Ore.cpp
        src/Ore/SmeltableOre.cpp
        src/Ore/CoalOre.cpp
        src/Ore/IronOre.cpp
        src/Ore/GoldOre.cpp
        src/Ore/DiamondOre.cpp
        src/Ore/ObsidianOre.cpp
        test/Ore/ut_ore.cpp
        test/Ore/ut_coal_ore.cpp
        test/Ore/ut_iron_ore.cpp
        test/Ore/ut_gold_ore.cpp
        test/Ore/ut_diamond_ore.cpp
        test/Ore/ut_obsidian_ore.cpp
)
target_link_libraries(ut_ore
        GTest::gtest_main
)
target_include_directories(ut_ore PRIVATE
        ${INCLUDE_DIR}
)
target_compile_options(ut_ore PRIVATE
        ${TARGET_COMPILER_OPTIONS}
)

add_executable(ut_pickaxe
        include/Ore/Ore.hpp
        include/Ore/SmeltableOre.hpp
        include/Ore/CoalOre.hpp
        include/Ore/IronOre.hpp
        include/Ore/GoldOre.hpp
        include/Ore/DiamondOre.hpp
        include/Ore/ObsidianOre.hpp
        include/Ore/Product.hpp
        include/Ore/BreakExp.hpp
        include/Ore/SmeltExp.hpp
        include/Ore/DurabilityCost.hpp
        include/Pickaxe/Pickaxe.hpp
        include/Pickaxe/WoodenPickaxe.hpp
        include/Pickaxe/StonePickaxe.hpp
        include/Pickaxe/IronPickaxe.hpp
        include/Pickaxe/GoldPickaxe.hpp
        include/Pickaxe/DiamondPickaxe.hpp
        include/Pickaxe/PickaxeType.hpp
        include/Pickaxe/Durability.hpp
        src/Ore/Ore.cpp
        src/Ore/SmeltableOre.cpp
        src/Ore/CoalOre.cpp
        src/Ore/IronOre.cpp
        src/Ore/GoldOre.cpp
        src/Ore/DiamondOre.cpp
        src/Ore/ObsidianOre.cpp
        src/Pickaxe/Pickaxe.cpp
        src/Pickaxe/WoodenPickaxe.cpp
        src/Pickaxe/StonePickaxe.cpp
        src/Pickaxe/IronPickaxe.cpp
        src/Pickaxe/GoldPickaxe.cpp
        src/Pickaxe/DiamonPickaxe.cpp
        test/Pickaxe/ut_pickaxe.cpp
        test/Pickaxe/ut_wooden_pickaxe.cpp
        test/Pickaxe/ut_stone_pickaxe.cpp
        test/Pickaxe/ut_iron_pickaxe.cpp
        test/Pickaxe/ut_gold_pickaxe.cpp
        test/Pickaxe/ut_diamond_pickaxe.cpp
)
target_link_libraries(ut_pickaxe
        GTest::gtest_main
)
target_include_directories(ut_pickaxe PRIVATE
        ${INCLUDE_DIR}
)
target_compile_options(ut_pickaxe PRIVATE
        ${TARGET_COMPILER_OPTIONS}
)

add_executable(ut_furnace
        include/Ore/Ore.hpp
        include/Ore/SmeltableOre.hpp
        include/Ore/CoalOre.hpp
        include/Ore/IronOre.hpp
        include/Ore/GoldOre.hpp
        include/Ore/DiamondOre.hpp
        include/Ore/ObsidianOre.hpp
        include/Ore/Product.hpp
        include/Ore/BreakExp.hpp
        include/Ore/SmeltExp.hpp
        include/Ore/DurabilityCost.hpp
        include/Pickaxe/Pickaxe.hpp
        include/Pickaxe/WoodenPickaxe.hpp
        include/Pickaxe/StonePickaxe.hpp
        include/Pickaxe/IronPickaxe.hpp
        include/Pickaxe/GoldPickaxe.hpp
        include/Pickaxe/DiamondPickaxe.hpp
        include/Pickaxe/PickaxeType.hpp
        include/Pickaxe/Durability.hpp
        include/Furnace.hpp
        src/Ore/Ore.cpp
        src/Ore/SmeltableOre.cpp
        src/Ore/CoalOre.cpp
        src/Ore/IronOre.cpp
        src/Ore/GoldOre.cpp
        src/Ore/DiamondOre.cpp
        src/Ore/ObsidianOre.cpp
        src/Pickaxe/Pickaxe.cpp
        src/Pickaxe/WoodenPickaxe.cpp
        src/Pickaxe/StonePickaxe.cpp
        src/Pickaxe/IronPickaxe.cpp
        src/Pickaxe/GoldPickaxe.cpp
        src/Pickaxe/DiamonPickaxe.cpp
        src/Furnace.cpp
        test/ut_furnace.cpp
)
target_link_libraries(ut_furnace
        GTest::gtest_main
)
target_include_directories(ut_furnace PRIVATE
        ${INCLUDE_DIR}
)
target_compile_options(ut_furnace PRIVATE
        ${TARGET_COMPILER_OPTIONS}
)

include(GoogleTest)
gtest_discover_tests(ut_all)
