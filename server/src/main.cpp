#include <cpprest/http_listener.h>
#include <cpprest/json.h>
#include <iostream>
#include <vector>
#include <mutex>
#include <thread>
#include "handlers/vaga/VagaHandlers.h"

using namespace web;
using namespace web::http;
using namespace web::http::experimental::listener;

int main() {
    http_listener listener(U("http://localhost:8080"));

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
