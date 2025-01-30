cmake_minimum_required(VERSION 3.5)

project(server)

set(CMAKE_CXX_STANDARD 14)

# Encontrar dependências
find_package(cpprestsdk REQUIRED)
find_package(OpenSSL REQUIRED)

# Diretórios de inclusão
include_directories(${CMAKE_SOURCE_DIR}/src)
include_directories(${CMAKE_SOURCE_DIR}/src/vaga)
include_directories(${CMAKE_SOURCE_DIR}/src/empresa)
include_directories(${CMAKE_SOURCE_DIR}/src/pessoa)
include_directories(${CMAKE_SOURCE_DIR}/src/usuario)
include_directories(${CMAKE_SOURCE_DIR}/src/professor)
include_directories(${CMAKE_SOURCE_DIR}/src/aluno)

# Arquivos fontes
set(SOURCES
    src/main.cpp
    src/vaga/Vaga.cpp
    src/empresa/Empresa.cpp
    src/aluno/Aluno.cpp
    src/professor/Professor.cpp
    src/pessoa/Pessoa.cpp
    src/usuario/Usuario.cpp
    src/handlers/VagaHandlers.cpp
)

# Criar o executável
add_executable(server ${SOURCES})

# Linkar bibliotecas
target_link_libraries(server PRIVATE cpprest OpenSSL::Crypto OpenSSL::SSL pthread)
