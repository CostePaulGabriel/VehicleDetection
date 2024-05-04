cmake_minimum_required(VERSION 3.21)

project(Project VERSION "1.0.0" DESCRIPTION "VehicleDetection." LANGUAGES CXX)

# CMake dependencies
include(GNUInstallDirs)
include(CheckCXXCompilerFlag)

# Custom modules
set(CMAKE_MODULE_PATH "${CMAKE_MODULE_PATH}" "${CMAKE_SOURCE_DIR}/cmake" CACHE INTERNAL "${PROJECT_NAME} CMake plugins dir.")
set(THIRDPARTY_DIR "${CMAKE_SOURCE_DIR}/Thirdparty" CACHE INTERNAL "${PROJECT_NAME} thirdparty libs dir.")

# Global properties
cmake_host_system_information(RESULT CPU_CORES QUERY NUMBER_OF_PHYSICAL_CORES)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# Language options
set(CMAKE_C_STANDARD 17)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Runtime options
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()
set(CMAKE_COLOR_MAKEFILE ON)
set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_BUILD_PARALLEL_LEVEL ${CPU_CORES})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/${CMAKE_INSTALL_BINDIR})

# Compiler settings.
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU")
    message(STATUS "Selecting cpp compiler ... " ${CMAKE_CXX_COMPILER})
    set(CMAKE_CXX_FLAGS_DEBUG "-O0 -g -DALLEN_DEBUG")
    set(CMAKE_CXX_FLAGS_RELEASE "-O3 -DNDEBUG")
    set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "-O3 -g -DNDEBUG")
    add_compile_options(
        -Wall
        -Wextra
        -Wpedantic
        $<$<COMPILE_LANGUAGE:CXX>:-Wdeprecated-enum-enum-conversion>
    )
    if(WIN32)
        set(CMAKE_EXE_LINKER_FLAGS "-mwindows") # Tell mingw to use main instead of WinMain.
    endif()
else()
    message(FATAL_ERROR "Unsupported compiler !")
endif()

add_subdirectory(Thirdparty EXCLUDE_FROM_ALL)
add_subdirectory(Rendering)
add_subdirectory(Detection)

find_package(Qt6 COMPONENTS Core Widgets Multimedia MultimediaWidgets REQUIRED)
if(NOT Qt6_FOUND)
    message(FATAL_ERROR "Qt6 not found. Install Qt6 !")
else()
    set(CMAKE_AUTOMOC ON)
    set(CMAKE_AUTOUIC ON)
    set(CMAKE_AUTORCC ON)
    set(QT6_LIBS Qt6::Core Qt6::Widgets Qt6::Multimedia Qt6::MultimediaWidgets)
endif()

set(OpenCV_DIR "${THIRDPARTY_DIR}/opencv/build" CACHE INTERNAL "Path to ocv.")
find_package(OpenCV REQUIRED)
if(OpenCV_FOUND)
    message(STATUS "Config: ${OpenCV_DIR}")
    message(STATUS "OpenCV version: ${OpenCV_VERSION}")
    message(STATUS "OpenCV libraries: ${OpenCV_LIBS}")
    message(STATUS "OpenCV include path: ${OpenCV_INCLUDE_DIRS}")
endif()

# Source
set(PROJ_HEADERS
    ${RENDERING_HEADERS}
)
set(PROJ_SRC
    ${RENDERING_SRC}
    ${CMAKE_SOURCE_DIR}/Main.cpp
)
set(PROJ_UI
    ${RENDERING_UI}
)
set(PROJ_LIBS
    ${QT6_LIBS}
    ${OpenCV_LIBS}
)

# Build setup
add_executable(${PROJECT_NAME})

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${PROJ_HEADERS} ${PROJ_SRC} ${PROJ_UI})

set_target_properties(${PROJECT_NAME}
    PROPERTIES
        DEBUG_POSTFIX d
        SOVERSION ${PROJECT_VERSION_MAJOR}
        VERSION ${PROJECT_VERSION}
        OUTPUT_NAME ${PROJECT_NAME}
        MACOSX_RPATH ON
)

target_compile_definitions(${PROJECT_NAME} PUBLIC _USE_MATH_DEFINES)

target_include_directories(${PROJECT_NAME}
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}>
        ${OpenCV_INCLUDE_DIRS}
)

target_sources(${PROJECT_NAME}
    PUBLIC
        ${PROJ_HEADERS}
    PRIVATE
        ${PROJ_SRC}
        ${PROJ_UI}
)

target_link_libraries(${PROJECT_NAME}
    PRIVATE
        ${PROJ_LIBS}
)
