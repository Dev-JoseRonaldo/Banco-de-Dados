#include <cpprest/http_listener.h>
#include <cpprest/json.h>
#include <iostream>
#include <vector>
#include <mutex>
#include <thread>
#include "handlers/VagaHandlers.h"
#include "empresa/Empresa.h"
#include "professor/Professor.h"
#include "aluno/Aluno.h"

using namespace web;
using namespace web::http;
using namespace web::http::experimental::listener;

std::vector<Empresa> empresas;
std::vector<Professor> professores;
std::vector<Aluno> alunos;

// Função para criar um aluno
void criar_aluno(const http_request& request) {
    // Captura a variável 'request' para dentro da lambda
    request.extract_json().then([&](web::json::value requestBody) { // Aqui usamos [&] para capturar todas as variáveis por referência
        std::string login = requestBody[U("login")].as_string();
        std::string senha = requestBody[U("senha")].as_string();
        std::string nome = requestBody[U("nome")].as_string();
        int idade = requestBody[U("idade")].as_integer();
        std::string cpf = requestBody[U("cpf")].as_string();
        std::string sexo = requestBody[U("sexo")].as_string();
        std::string data_nascimento = requestBody[U("data_nascimento")].as_string();
        std::string rg = requestBody[U("rg")].as_string();
        std::string email = requestBody[U("email")].as_string();
        std::string endereco = requestBody[U("endereco")].as_string();
        std::string numero_matricula = requestBody[U("numero_matricula")].as_string();
        std::string curso = requestBody[U("curso")].as_string();
        int ano_matricula = requestBody[U("ano_matricula")].as_integer();
        double media_geral = requestBody[U("media_geral")].as_double();

        Aluno aluno(login, senha, nome, idade, cpf, sexo, data_nascimento, rg, email, endereco,
                    numero_matricula, curso, ano_matricula, media_geral);
        alunos.push_back(aluno);

        web::http::http_response response;
        response.set_status_code(status_codes::Created);
        response.set_body(U("Aluno criado com sucesso"));
        request.reply(response);  // Aqui, 'request' é passado como referência por meio da captura da lambda
    }).wait();
}

#include <mutex>

std::mutex aluno_mutex;  // Mutex para proteger o acesso à lista de alunos

// Função para listar todos os alunos
void listar_alunos(const web::http::http_request& request) {
    web::json::value response_data = web::json::value::array();

    std::lock_guard<std::mutex> lock(aluno_mutex);  // Bloqueia o acesso à lista de alunos

    for (size_t i = 0; i < alunos.size(); ++i) {
        // Convertendo cada aluno para um formato JSON, supondo que a classe Aluno tenha um método toJson()
        response_data[i] = alunos[i].toJson(); 
    }

    request.reply(web::http::status_codes::OK, response_data);  // Retorna a resposta com o status OK
}

// Função para criar uma empresa
void criar_empresa(const http_request& request) {
    request.extract_json().then([&](web::json::value requestBody) {
        std::string login = requestBody[U("login")].as_string();
        std::string senha = requestBody[U("senha")].as_string();
        std::string nome = requestBody[U("nome")].as_string();
        std::string cnpj = requestBody[U("cnpj")].as_string();
        std::string email = requestBody[U("email")].as_string();

        Empresa empresa(login, senha, nome, cnpj, email);
        empresas.push_back(empresa);

        web::http::http_response response;
        response.set_status_code(status_codes::Created);
        response.set_body(U("Empresa criada com sucesso"));
        request.reply(response);
    }).wait();
}

// Função para listar todas as empresas
void listar_empresas(const http_request& request) {
    web::json::value result;
    for (size_t i = 0; i < empresas.size(); ++i) {
        result[U("empresa" + std::to_string(i))] = web::json::value::string(empresas[i].getNome());
    }

    request.reply(status_codes::OK, result);
}

// Função para criar um professor
void criar_professor(const http_request& request) {
    request.extract_json().then([&](web::json::value requestBody) {
        std::string login = requestBody[U("login")].as_string();
        std::string senha = requestBody[U("senha")].as_string();
        std::string nome = requestBody[U("nome")].as_string();
        int idade = requestBody[U("idade")].as_integer();
        std::string cpf = requestBody[U("cpf")].as_string();
        std::string sexo = requestBody[U("sexo")].as_string();
        std::string data_nascimento = requestBody[U("data_nascimento")].as_string();
        std::string rg = requestBody[U("rg")].as_string();
        std::string email = requestBody[U("email")].as_string();
        std::string endereco = requestBody[U("endereco")].as_string();
        double salario = requestBody[U("salario")].as_double();
        std::string tipo = requestBody[U("tipo")].as_string();

        Professor professor(login, senha, nome, idade, cpf, sexo, data_nascimento, rg, email, endereco, salario, tipo);
        professores.push_back(professor);

        web::http::http_response response;
        response.set_status_code(status_codes::Created);
        response.set_body(U("Professor criado com sucesso"));
        request.reply(response);
    }).wait();
}

// Função para listar todos os professores
void listar_professores(const http_request& request) {
    web::json::value result;
    for (size_t i = 0; i < professores.size(); ++i) {
        result[U("professor" + std::to_string(i))] = web::json::value::string(professores[i].getNome());
    }

    request.reply(status_codes::OK, result);
}

int main() {
    http_listener listener(U("http://localhost:8080"));

    // Rota para criar uma empresa
    listener.support(methods::POST, [](const http_request& request) {
        if (request.relative_uri().path() == U("/empresa")) {
            criar_empresa(request);
        }
    });

    // Rota para listar todas as empresas
    listener.support(methods::GET, [](const http_request& request) {
        if (request.relative_uri().path() == U("/empresa")) {
            listar_empresas(request);
        }
    });

    // Rota para criar um professor
    listener.support(methods::POST, [](const http_request& request) {
        if (request.relative_uri().path() == U("/professor")) {
            criar_professor(request);
        }
    });

    // Rota para listar todos os professores
    listener.support(methods::GET, [](const http_request& request) {
        if (request.relative_uri().path() == U("/professor")) {
            listar_professores(request);
        }
    });

    // Rota para criar um aluno
    listener.support(methods::POST, [](const http_request& request) {
        if (request.relative_uri().path() == U("/aluno")) {
            criar_aluno(request);
        }
    });

    // Rota para listar todos os alunos
    listener.support(methods::GET, [](const http_request& request) {
        if (request.relative_uri().path() == U("/aluno")) {
            listar_alunos(request);
        }
    });

    // Rota para criar uma vaga
    listener.support(methods::POST, [](const http_request& request) {
        if (request.relative_uri().path() == U("/vaga")) {
            criar_vaga(request);
        }
    });

    // Rota para listar todas as vagas
    listener.support(methods::GET, [](const http_request& request) {
        if (request.relative_uri().path() == U("/vaga")) {
            listar_vagas(request);
        }
    });

    // Rota para atualizar uma vaga
    listener.support(methods::PATCH, [](const http_request& request) {
        if (request.relative_uri().path().find(U("/vaga/")) == 0) {
            atualizar_vaga(request);
        }
    });

    // Rota para deletar uma vaga
    listener.support(methods::DEL, [](const http_request& request) {
        if (request.relative_uri().path().find(U("/vaga/")) == 0) {
            deletar_vaga(request);
        }
    });

    try {
        listener
            .open()
            .then([]() { std::wcout << L"Servidor rodando em http://localhost:8080" << std::endl; })
            .wait();

        while (true) {
            // Aguarda novas requisições
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
    } catch (const std::exception& e) {
        std::cerr << "Erro: " << e.what() << std::endl;
    }

    return 0;
}