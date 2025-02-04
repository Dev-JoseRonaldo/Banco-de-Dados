#include "Vaga.h"

// Construtor da classe Vaga
Vaga::Vaga(int id, std::string titulo, std::string descricao, std::string empresa, std::string data_abertura, double salario)
    : id(id), titulo(std::move(titulo)), descricao(std::move(descricao)), empresa(std::move(empresa)), 
      data_abertura(std::move(data_abertura)), salario(salario) {}

// Getters
int Vaga::getId() const { return id; }
std::string Vaga::getTitulo() const { return titulo; }
std::string Vaga::getDescricao() const { return descricao; }
std::string Vaga::getEmpresa() const { return empresa; }
std::string Vaga::getDataAbertura() const { return data_abertura; }
double Vaga::getSalario() const { return salario; }

// Setters
void Vaga::setTitulo(const std::string& t) { titulo = t; }
void Vaga::setDescricao(const std::string& d) { descricao = d; }
void Vaga::setEmpresa(const std::string& e) { empresa = e; }
void Vaga::setDataAbertura(const std::string& da) { data_abertura = da; }
void Vaga::setSalario(double s) { salario = s; }

// Método para Serializa a vaga para formato JSON (importante para a API REST)
web::json::value Vaga::toJson() const {
    web::json::value vaga_json;
    vaga_json[U("id")] = web::json::value::number(id);
    vaga_json[U("titulo")] = web::json::value::string(U(titulo));
    vaga_json[U("descricao")] = web::json::value::string(U(descricao));
    vaga_json[U("empresa")] = web::json::value::string(U(empresa));
    vaga_json[U("data_abertura")] = web::json::value::string(U(data_abertura));
    vaga_json[U("salario")] = web::json::value::number(salario);
    return vaga_json;
}
