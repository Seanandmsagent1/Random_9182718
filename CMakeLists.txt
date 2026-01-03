cmake_minimum_required(VERSION 3.13)

# This line finds the Geode SDK robot instructions
find_package(Geode REQUIRED)

project(AdorabooReminder)

# This command creates your mod file
add_geode_mod(
    com.plybiter.adorablo
    VERSION v1.1.0
    RESOURCES
    SOURCES src/main.cpp
)

# Optional: This makes your code more modern
set_target_properties(com.plybiter.adorablo PROPERTIES
    CXX_STANDARD 20
    CXX_STANDARD_REQUIRED ON
)
