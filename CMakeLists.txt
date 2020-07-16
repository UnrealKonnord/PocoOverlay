cmake_minimum_required(VERSION 3.16)

#
# Import a local dotenv
#
if (EXISTS "${CMAKE_SOURCE_DIR}/.env")
    message("-- Import .env")
    file(READ "${CMAKE_SOURCE_DIR}/.env" dotenv)
    string(REGEX MATCHALL "[^=\n]+=[^\n]+" dotenv ${dotenv})
    foreach(envVar IN ITEMS ${dotenv})
            string(REGEX MATCHALL "^[^=]+" envKey ${envVar})
            string(REGEX MATCHALL "[^=]+$" envValue ${envVar})
            set(ENV{${envKey}} ${envValue})
    endforeach()
endif()

project(PocoOverlay VERSION 0.0.1)

set(CMAKE_CXX_STANDARD 11)

add_library(PocoOverlay STATIC include/PocoOverlay/All.hpp src/Dummy.cpp)

#
# When BuildPocoOverlayGoogleTest is equal to true then build the unit test
#
if ("$ENV{BuildPocoOverlayGoogleTest}" STREQUAL "true")
    add_subdirectory(test)
endif()