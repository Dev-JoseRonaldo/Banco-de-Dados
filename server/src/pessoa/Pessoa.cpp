#include "Pessoa.h"

Pessoa::Pessoa(std::string login, std::string senha, std::string nome, int idade, std::string cpf, 
               std::string sexo, std::string data_nascimento, std::string rg,
               std::string email, std::string endereco)
    : Usuario(login, senha), nome(nome), idade(idade), cpf(cpf), sexo(sexo), data_nascimento(data_nascimento),
      rg(rg), email(email), endereco(endereco) {}

// Métodos getters
std::string Pessoa::getNome() const {
    return nome;
}

int Pessoa::getIdade() const {
    return idade;
}

std::string Pessoa::getCpf() const {
    return cpf;
}

std::string Pessoa::getSexo() const {
    return sexo;
}

std::string Pessoa::getDataNascimento() const {
    return data_nascimento;
}

std::string Pessoa::getRg() const {
    return rg;
}

std::string Pessoa::getEmail() const {
    return email;
}

std::string Pessoa::getEndereco() const {
    return endereco;
}

// Métodos setters
void Pessoa::setNome(const std::string& nome) {
    this->nome = nome;
}

void Pessoa::setIdade(int idade) {
    this->idade = idade;
}

void Pessoa::setCpf(const std::string& cpf) {
    this->cpf = cpf;
}

void Pessoa::setSexo(const std::string& sexo) {
    this->sexo = sexo;
}

void Pessoa::setDataNascimento(const std::string& data_nascimento) {
    this->data_nascimento = data_nascimento;
}

void Pessoa::setRg(const std::string& rg) {
    this->rg = rg;
}

void Pessoa::setEmail(const std::string& email) {
    this->email = email;
}

void Pessoa::setEndereco(const std::string& endereco) {
    this->endereco = endereco;
}

// Implementação do método toJson
web::json::value Pessoa::toJson() const {
    web::json::value json_obj;

    // Preenche o objeto JSON com os dados de Pessoa
    json_obj[U("nome")] = web::json::value::string(nome);
    json_obj[U("idade")] = web::json::value::number(idade);
    json_obj[U("cpf")] = web::json::value::string(cpf);
    json_obj[U("sexo")] = web::json::value::string(sexo);
    json_obj[U("data_nascimento")] = web::json::value::string(data_nascimento);
    json_obj[U("rg")] = web::json::value::string(rg);
    json_obj[U("email")] = web::json::value::string(email);
    json_obj[U("endereco")] = web::json::value::string(endereco);

    return json_obj;
}
