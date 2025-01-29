cmake_minimum_required(VERSION 3.10)
project(server)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Diretório do Crow
set(CROW_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/Crow/include")

# Diretório do Asio (caso você tenha baixado manualmente o Asio)
set(ASIO_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/Asio/asio/include")

# Diretório do Boost
find_package(Boost REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})

# Adiciona os diretórios de includes
include_directories(${CROW_INCLUDE_DIR})
include_directories(${ASIO_INCLUDE_DIR})

# Adiciona o executável principal
add_executable(server ../main.cpp)

# Linka a biblioteca Boost ao executável
target_link_libraries(server ${Boost_LIBRARIES})
