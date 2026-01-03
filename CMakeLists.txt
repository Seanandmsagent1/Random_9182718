cmake_minimum_required(VERSION 3.25)

# This part downloads the Geode SDK so the Robot can find it
set(GEODE_FETCH_SDK ON)
include(FetchContent)
FetchContent_Declare(
    geode
    GIT_REPOSITORY https://github.com/geode-sdk/geode.git
    GIT_TAG main
)
FetchContent_MakeAvailable(geode)

project(AdorabooReminder)

# Use your unique ID here
add_geode_mod(
    com.plybiter.adorablo
    VERSION v1.1.0
    RESOURCES
    SOURCES src/main.cpp
)
