cmake_minimum_required(VERSION 3.5)

project(server)

set(CMAKE_CXX_STANDARD 14)

# Localiza a instalação do cpprestsdk e do OpenSSL
find_package(cpprestsdk REQUIRED)
find_package(OpenSSL REQUIRED)

# Adiciona o executável
add_executable(server main.cpp)

# Linka as bibliotecas cpprest e OpenSSL
target_link_libraries(server PRIVATE cpprest OpenSSL::Crypto OpenSSL::SSL)
