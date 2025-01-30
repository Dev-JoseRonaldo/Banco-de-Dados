#include "Empresa.h"

Empresa::Empresa(std::string login, std::string senha, std::string nome, std::string cnpj, std::string email)
    : Usuario(login, senha), nome(nome), cnpj(cnpj), email(email) {}

std::string Empresa::getNome() const {
    return nome;
}

std::string Empresa::getCnpj() const {
    return cnpj;
}

std::string Empresa::getEmail() const {
    return email;
}

void Empresa::setNome(const std::string& nome) {
    this->nome = nome;
}

void Empresa::setCnpj(const std::string& cnpj) {
    this->cnpj = cnpj;
}

void Empresa::setEmail(const std::string& email) {
    this->email = email;
}

// Implementação do método toJson
web::json::value Empresa::toJson() const {
    web::json::value json_obj = Usuario::toJson();  // Chama o toJson da classe base Usuario

    // Adiciona as propriedades da classe Empresa ao JSON
    json_obj[U("nome")] = web::json::value::string(nome);
    json_obj[U("cnpj")] = web::json::value::string(cnpj);
    json_obj[U("email")] = web::json::value::string(email);

    return json_obj;
}
