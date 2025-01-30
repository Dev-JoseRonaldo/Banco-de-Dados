#include "Professor.h"

Professor::Professor(std::string login, std::string senha, std::string nome, int idade, std::string cpf, 
                     std::string sexo, std::string data_nascimento, std::string rg, std::string email, 
                     std::string endereco, double salario, std::string tipo)
    : Pessoa(login, senha, nome, idade, cpf, sexo, data_nascimento, rg, email, endereco), salario(salario), tipo(tipo) {}

double Professor::getSalario() const {
    return salario;
}

std::string Professor::getTipo() const {
    return tipo;
}

void Professor::setSalario(double salario) {
    this->salario = salario;
}

void Professor::setTipo(const std::string& tipo) {
    this->tipo = tipo;
}

// Implementação do método toJson
web::json::value Professor::toJson() const {
    // Converte os dados herdados da classe Pessoa
    web::json::value json_obj = Pessoa::toJson();

    // Adiciona as propriedades específicas de Professor
    json_obj[U("salario")] = web::json::value::number(salario);
    json_obj[U("tipo")] = web::json::value::string(tipo);

    return json_obj;
}
