cmake_minimum_required(VERSION 3.5)

project(server)

set(CMAKE_CXX_STANDARD 14)

find_package(cpprestsdk REQUIRED)
find_package(OpenSSL REQUIRED)

add_executable(server main.cpp)

target_link_libraries(server PRIVATE cpprest OpenSSL::Crypto OpenSSL::SSL)

target_link_libraries(server PRIVATE cpprest OpenSSL::Crypto OpenSSL::SSL pthread)
