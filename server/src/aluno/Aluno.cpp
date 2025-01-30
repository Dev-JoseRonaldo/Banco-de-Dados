#include "Aluno.h"

// Implementação do construtor
Aluno::Aluno(std::string login, std::string senha, std::string nome, int idade, std::string cpf, std::string sexo,
             std::string data_nascimento, std::string rg, std::string email, std::string endereco,
             std::string numero_matricula, std::string curso, int ano_matricula, double media_geral)
    : Pessoa(login, senha, nome, idade, cpf, sexo, data_nascimento, rg, email, endereco), // Chama o construtor da classe base Pessoa
      numero_matricula(numero_matricula), curso(curso), ano_matricula(ano_matricula), media_geral(media_geral) {}

// Implementação dos métodos getter e setter
std::string Aluno::getNumeroMatricula() const {
    return numero_matricula;
}

std::string Aluno::getCurso() const {
    return curso;
}

int Aluno::getAnoMatricula() const {
    return ano_matricula;
}

double Aluno::getMediaGeral() const {
    return media_geral;
}

void Aluno::setNumeroMatricula(const std::string& numero_matricula) {
    this->numero_matricula = numero_matricula;
}

void Aluno::setCurso(const std::string& curso) {
    this->curso = curso;
}

void Aluno::setAnoMatricula(int ano_matricula) {
    this->ano_matricula = ano_matricula;
}

void Aluno::setMediaGeral(double media_geral) {
    this->media_geral = media_geral;
}

// Implementação do método toJson
web::json::value Aluno::toJson() const {
    web::json::value json_obj;
    json_obj[U("numero_matricula")] = web::json::value::string(numero_matricula);
    json_obj[U("curso")] = web::json::value::string(curso);
    json_obj[U("ano_matricula")] = web::json::value::number(ano_matricula);
    json_obj[U("media_geral")] = web::json::value::number(media_geral);
    return json_obj;
}
