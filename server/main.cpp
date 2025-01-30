#include <cpprest/http_listener.h>
#include <cpprest/json.h>
#include <iostream>
#include <vector>
#include <mutex>
#include <thread>

using namespace web;
using namespace web::http;
using namespace web::http::experimental::listener;

std::mutex vaga_mutex;

// Classe Vaga
class Vaga {
private:
    int id;
    std::string titulo;
    std::string descricao;
    std::string empresa;
    std::string data_abertura;
    double salario;

public:
    // Construtor
    Vaga(int id, std::string titulo, std::string descricao, std::string empresa, std::string data_abertura, double salario)
        : id(id), titulo(std::move(titulo)), descricao(std::move(descricao)), empresa(std::move(empresa)), 
          data_abertura(std::move(data_abertura)), salario(salario) {}

    // Getters
    int getId() const { return id; }
    std::string getTitulo() const { return titulo; }
    std::string getDescricao() const { return descricao; }
    std::string getEmpresa() const { return empresa; }
    std::string getDataAbertura() const { return data_abertura; }
    double getSalario() const { return salario; }

    // Setters
    void setTitulo(const std::string& t) { titulo = t; }
    void setDescricao(const std::string& d) { descricao = d; }
    void setEmpresa(const std::string& e) { empresa = e; }
    void setDataAbertura(const std::string& da) { data_abertura = da; }
    void setSalario(double s) { salario = s; }

    // Serializa para JSON
    json::value toJson() const {
        json::value vaga_json;
        vaga_json[U("id")] = json::value::number(id);
        vaga_json[U("titulo")] = json::value::string(U(titulo));
        vaga_json[U("descricao")] = json::value::string(U(descricao));
        vaga_json[U("empresa")] = json::value::string(U(empresa));
        vaga_json[U("data_abertura")] = json::value::string(U(data_abertura));
        vaga_json[U("salario")] = json::value::number(salario);
        return vaga_json;
    }
};

// Vetor para armazenar as vagas
std::vector<Vaga> vagas;
int next_id = 1;

// Função para criar uma nova vaga
void criar_vaga(const http_request& request) {
    request.extract_json().then([&](json::value body) {
        std::lock_guard<std::mutex> lock(vaga_mutex);

        std::string titulo = body[U("titulo")].as_string();
        std::string descricao = body[U("descricao")].as_string();
        std::string empresa = body[U("empresa")].as_string();
        std::string data_abertura = body[U("data_abertura")].as_string();
        double salario = body[U("salario")].as_double();

        Vaga nova_vaga(next_id++, titulo, descricao, empresa, data_abertura, salario);
        vagas.push_back(nova_vaga);

        request.reply(status_codes::Created, nova_vaga.toJson());
    }).wait();
}

// Função para listar todas as vagas
void listar_vagas(const http_request& request) {
    json::value response_data = json::value::array();

    std::lock_guard<std::mutex> lock(vaga_mutex);

    for (size_t i = 0; i < vagas.size(); i++) {
        response_data[i] = vagas[i].toJson();
    }

    request.reply(status_codes::OK, response_data);
}

// Função para atualizar uma vaga
void atualizar_vaga(const http_request& request) {
    auto id = std::stoi(request.relative_uri().path().substr(6));
    
    request.extract_json().then([&](json::value body) {
        std::lock_guard<std::mutex> lock(vaga_mutex);

        for (auto& vaga : vagas) {
            if (vaga.getId() == id) {
                if (body.has_field(U("titulo"))) vaga.setTitulo(body[U("titulo")].as_string());
                if (body.has_field(U("descricao"))) vaga.setDescricao(body[U("descricao")].as_string());
                if (body.has_field(U("empresa"))) vaga.setEmpresa(body[U("empresa")].as_string());
                if (body.has_field(U("data_abertura"))) vaga.setDataAbertura(body[U("data_abertura")].as_string());
                if (body.has_field(U("salario"))) vaga.setSalario(body[U("salario")].as_double());

                request.reply(status_codes::OK, vaga.toJson());
                return;
            }
        }
        request.reply(status_codes::NotFound, U("Vaga não encontrada"));
    }).wait();
}

// Função para deletar uma vaga
void deletar_vaga(const http_request& request) {
    auto id = std::stoi(request.relative_uri().path().substr(6));

    std::lock_guard<std::mutex> lock(vaga_mutex);

    auto it = std::remove_if(vagas.begin(), vagas.end(), [&](const Vaga& v) { return v.getId() == id; });

    if (it != vagas.end()) {
        vagas.erase(it, vagas.end());
        request.reply(status_codes::OK, U("Vaga removida"));
    } else {
        request.reply(status_codes::NotFound, U("Vaga não encontrada"));
    }
}

int main() {
    http_listener listener(U("http://localhost:8080"));

    listener.support(methods::POST, [](const http_request& request) {
        if (request.relative_uri().path() == U("/vaga")) {
            criar_vaga(request);
        }
    });

    listener.support(methods::GET, [](const http_request& request) {
        if (request.relative_uri().path() == U("/vaga")) {
            listar_vagas(request);
        }
    });

    listener.support(methods::PATCH, [](const http_request& request) {
        if (request.relative_uri().path().find(U("/vaga/")) == 0) {
            atualizar_vaga(request);
        }
    });

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
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
    } catch (const std::exception& e) {
        std::cerr << "Erro: " << e.what() << std::endl;
    }

    return 0;
}
