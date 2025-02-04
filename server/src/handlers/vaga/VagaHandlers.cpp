#include "VagaHandlers.h"
#include <mutex>
#include <algorithm>
#include <iostream>


extern std::vector<Vaga> vagas; // Vetor global de vagas
extern int next_id; // Próximo ID a ser atribuído a uma nova vaga
std::mutex vaga_mutex; // Mutex para proteger o acesso ao vetor de vagas (vagas) e ao next_id

std::vector<Vaga> vagas; //  Vetor para armazenar as vagas (Banco de dados)
int next_id = 0; // Variável global que controla o próximo ID (inicia em 0)

// Função para criar uma nova vaga (handler para requisições POST para /vagas)
void criar_vaga(const web::http::http_request& request) {
    request.extract_json().then([&](web::json::value body) {
        // Bloqueia o acesso ao vetor de vagas e ao next_id com um lock_guard
        std::lock_guard<std::mutex> lock(vaga_mutex);

        // Extrai os dados da vaga do objeto JSON
        std::string titulo = body[U("titulo")].as_string();
        std::string descricao = body[U("descricao")].as_string();
        std::string empresa = body[U("empresa")].as_string();
        std::string data_abertura = body[U("data_abertura")].as_string();
        double salario = body[U("salario")].as_double();

        // Cria um novo objeto Vaga com os dados
        Vaga nova_vaga(next_id++, titulo, descricao, empresa, data_abertura, salario);
        // Adiciona a nova vaga ao vetor de vagas
        vagas.push_back(nova_vaga);

        // Responde à requisição com status 201 (Created) e o JSON da nova vaga
        request.reply(web::http::status_codes::Created, nova_vaga.toJson());
    }).wait();
}

// Função para listar todas as vagas (handler para requisições GET para /vagas)
void listar_vagas(const web::http::http_request& request) {
    // Cria um array JSON para armazenar as vagas
    web::json::value response_data = web::json::value::array();

    // Bloqueia o acesso ao vetor de vagas com um lock_guard
    std::lock_guard<std::mutex> lock(vaga_mutex);

    // Itera sobre o vetor de vagas e adiciona cada vaga ao array JSON
    for (size_t i = 0; i < vagas.size(); i++) {
        response_data[i] = vagas[i].toJson();
    }

     // Responde à requisição com status 200 (OK) e o array JSON de vagas
    request.reply(web::http::status_codes::OK, response_data);
}

// Função para atualizar uma vaga existente (handler para requisições PUT para /vagas/{id})
void atualizar_vaga(const web::http::http_request& request) {
    // Extrai o ID da vaga da URL
    auto id = std::stoi(request.relative_uri().path().substr(6));
    
    // Extrai o JSON do corpo da requisição
    request.extract_json().then([&](web::json::value body) {
        // Bloqueia o acesso ao vetor de vagas com um lock_guard
        std::lock_guard<std::mutex> lock(vaga_mutex);

        // Itera sobre o vetor de vagas para encontrar a vaga com o ID correspondente
        for (auto& vaga : vagas) {
            if (vaga.getId() == id) {
                // Atualiza os campos da vaga com os dados do JSON, se presentes
                if (body.has_field(U("titulo"))) vaga.setTitulo(body[U("titulo")].as_string());
                if (body.has_field(U("descricao"))) vaga.setDescricao(body[U("descricao")].as_string());
                if (body.has_field(U("empresa"))) vaga.setEmpresa(body[U("empresa")].as_string());
                if (body.has_field(U("data_abertura"))) vaga.setDataAbertura(body[U("data_abertura")].as_string());
                if (body.has_field(U("salario"))) vaga.setSalario(body[U("salario")].as_double());
                
                // Responde à requisição com status 200 (OK) e o JSON da vaga atualizada
                request.reply(web::http::status_codes::OK, vaga.toJson());
                return;
            }
        }
        // Se a vaga não foi encontrada, responde com status 404 (Not Found)
        request.reply(web::http::status_codes::NotFound, U("Vaga não encontrada"));
    }).wait();
}

// Função para deletar uma vaga (handler para requisições DELETE para /vagas/{id})
void deletar_vaga(const web::http::http_request& request) {
    // Extrai o ID da vaga da URL
    auto id = std::stoi(request.relative_uri().path().substr(6));

    // Bloqueia o acesso ao vetor de vagas com um lock_guard
    std::lock_guard<std::mutex> lock(vaga_mutex);

    // Remove a vaga do vetor usando o remove_if e o erase
    auto it = std::remove_if(vagas.begin(), vagas.end(), [&](const Vaga& v) { return v.getId() == id; });

    // Verifica se a vaga foi encontrada e removida
    if (it != vagas.end()) {
        vagas.erase(it, vagas.end());

        // Responde à requisição com status 200 (OK) e uma mensagem confirmando a remoção
        request.reply(web::http::status_codes::OK, U("Vaga removida"));
    } else {
        // Se a vaga não foi encontrada, responde com status 404 (Not Found)
        request.reply(web::http::status_codes::NotFound, U("Vaga não encontrada"));
    }
}
