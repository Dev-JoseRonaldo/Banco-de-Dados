#include "VagaHandlers.h"
#include <mutex>
#include <algorithm>
#include <iostream>

extern std::vector<Vaga> vagas;
extern int next_id;
std::mutex vaga_mutex;

std::vector<Vaga> vagas;
int next_id = 0;

void criar_vaga(const web::http::http_request& request) {
    request.extract_json().then([&](web::json::value body) {
        std::lock_guard<std::mutex> lock(vaga_mutex);

        std::string titulo = body[U("titulo")].as_string();
        std::string descricao = body[U("descricao")].as_string();
        std::string empresa = body[U("empresa")].as_string();
        std::string data_abertura = body[U("data_abertura")].as_string();
        double salario = body[U("salario")].as_double();

        Vaga nova_vaga(next_id++, titulo, descricao, empresa, data_abertura, salario);
        vagas.push_back(nova_vaga);

        request.reply(web::http::status_codes::Created, nova_vaga.toJson());
    }).wait();
}

void listar_vagas(const web::http::http_request& request) {
    web::json::value response_data = web::json::value::array();

    std::lock_guard<std::mutex> lock(vaga_mutex);

    for (size_t i = 0; i < vagas.size(); i++) {
        response_data[i] = vagas[i].toJson();
    }

    request.reply(web::http::status_codes::OK, response_data);
}

void atualizar_vaga(const web::http::http_request& request) {
    auto id = std::stoi(request.relative_uri().path().substr(6));
    
    request.extract_json().then([&](web::json::value body) {
        std::lock_guard<std::mutex> lock(vaga_mutex);

        for (auto& vaga : vagas) {
            if (vaga.getId() == id) {
                if (body.has_field(U("titulo"))) vaga.setTitulo(body[U("titulo")].as_string());
                if (body.has_field(U("descricao"))) vaga.setDescricao(body[U("descricao")].as_string());
                if (body.has_field(U("empresa"))) vaga.setEmpresa(body[U("empresa")].as_string());
                if (body.has_field(U("data_abertura"))) vaga.setDataAbertura(body[U("data_abertura")].as_string());
                if (body.has_field(U("salario"))) vaga.setSalario(body[U("salario")].as_double());

                request.reply(web::http::status_codes::OK, vaga.toJson());
                return;
            }
        }
        request.reply(web::http::status_codes::NotFound, U("Vaga não encontrada"));
    }).wait();
}

void deletar_vaga(const web::http::http_request& request) {
    auto id = std::stoi(request.relative_uri().path().substr(6));

    std::lock_guard<std::mutex> lock(vaga_mutex);

    auto it = std::remove_if(vagas.begin(), vagas.end(), [&](const Vaga& v) { return v.getId() == id; });

    if (it != vagas.end()) {
        vagas.erase(it, vagas.end());
        request.reply(web::http::status_codes::OK, U("Vaga removida"));
    } else {
        request.reply(web::http::status_codes::NotFound, U("Vaga não encontrada"));
    }
}
