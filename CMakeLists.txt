cmake_minimum_required (VERSION 2.6)
project (SRCTest) 
file(GLOB SOURCES
    src/*.h
    src/*.cpp
)
add_executable(SRCTest ${SOURCES})