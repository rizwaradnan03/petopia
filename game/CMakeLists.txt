cmake_minimum_required(VERSION 3.25)

project(
    petopia
    VERSION 1.0.0
    DESCRIPTION "Raylib C++ Game"
    LANGUAGES CXX
)


# ======================================
# C++ Configuration
# ======================================

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)


# Generate compile_commands.json
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)


# Default build type
if(NOT CMAKE_BUILD_TYPE)
    set(
        CMAKE_BUILD_TYPE
        Debug
        CACHE STRING
        "Build type"
        FORCE
    )
endif()



# ======================================
# Sources
# ======================================

file(
    GLOB_RECURSE GAME_SOURCES
    CONFIGURE_DEPENDS
    "${CMAKE_SOURCE_DIR}/src/*.cpp"
    "${CMAKE_SOURCE_DIR}/cmd/*.cpp"
)


add_executable(
    ${PROJECT_NAME}
    ${GAME_SOURCES}
)



# ======================================
# Include
# ======================================

target_include_directories(
    ${PROJECT_NAME}
    PRIVATE

    ${CMAKE_SOURCE_DIR}/include
)



# ======================================
# Dependencies
# ======================================

find_package(raylib REQUIRED)


find_package(PkgConfig REQUIRED)

pkg_check_modules(
    PQXX
    REQUIRED
    libpqxx
)



target_include_directories(
    ${PROJECT_NAME}
    PRIVATE
    ${PQXX_INCLUDE_DIRS}
)


target_link_directories(
    ${PROJECT_NAME}
    PRIVATE
    ${PQXX_LIBRARY_DIRS}
)



target_link_libraries(
    ${PROJECT_NAME}

    PRIVATE

    raylib

    ${PQXX_LIBRARIES}

    pq

    m

    dl

    pthread

)



# ======================================
# Compiler flags
# ======================================

if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")

    target_compile_options(
        ${PROJECT_NAME}

        PRIVATE

        -Wall
        -Wextra
        -Wpedantic

    )


endif()



# ======================================
# Debug
# ======================================

target_compile_definitions(
    ${PROJECT_NAME}

    PRIVATE

    $<$<CONFIG:Debug>:DEBUG>

)



# ======================================
# Release Optimization
# ======================================

if(CMAKE_BUILD_TYPE STREQUAL "Release")


    include(CheckIPOSupported)

    check_ipo_supported(
        RESULT
        IPO_SUPPORTED
    )


    if(IPO_SUPPORTED)

        set_property(
            TARGET
            ${PROJECT_NAME}

            PROPERTY
            INTERPROCEDURAL_OPTIMIZATION TRUE
        )

    endif()



    target_compile_options(
        ${PROJECT_NAME}

        PRIVATE

        -O3
        -march=native

    )


endif()



# ======================================
# Assets
# ======================================

add_custom_command(

    TARGET
    ${PROJECT_NAME}

    POST_BUILD

    COMMAND
    ${CMAKE_COMMAND}
    -E
    copy_directory

    ${CMAKE_SOURCE_DIR}/storage

    $<TARGET_FILE_DIR:${PROJECT_NAME}>/storage

)



# ======================================
# Output directory
# ======================================

set_target_properties(
    ${PROJECT_NAME}

    PROPERTIES

    RUNTIME_OUTPUT_DIRECTORY

    ${CMAKE_BINARY_DIR}/bin

)