cmake_minimum_required(VERSION 3.16)
project(shortest_path LANGUAGES CXX)

add_executable(shortest_path src/main.cpp)
target_compile_features(shortest_path PRIVATE cxx_std_17)
