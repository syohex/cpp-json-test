CMAKE_MINIMUM_REQUIRED(VERSION 2.8.11)
PROJECT(json-test)

SET(CMAKE_CXX_FLAGS "-Wall -std=c++11")

INCLUDE_DIRECTORIES(
  "json/src"
)

ADD_EXECUTABLE(
  "json-test"
  json-test.cpp
)
