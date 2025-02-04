#include "Aluno.h"

using namespace std;

// Construtor
Aluno::Aluno(const string& login, const string& senha, const string& nome, int idade, const string& cpf, const string& sexo, const string& data_nascimento, const string& rg, const string& email, const string& endereco,
             const string& numero_matricula, const string& curso, int ano_entrada, double media_geral)
    : Pessoa(login, senha, nome, idade, cpf, sexo, data_nascimento, rg, email, endereco), numero_matricula(numero_matricula), curso(curso), ano_entrada(ano_entrada), media_geral(media_geral) {}

// Getters
string Aluno::getNumeroMatricula() const {
    return numero_matricula;
}

string Aluno::getCurso() const {
    return curso;
}

int Aluno::getAnoEntrada() const {
    return ano_entrada;
}

double Aluno::getMediaGeral() const {
    return media_geral;
}

// Setters
void Aluno::setNumeroMatricula(const string& novoNumero) {
    numero_matricula = novoNumero;
}

void Aluno::setCurso(const string& novoCurso) {
    curso = novoCurso;
}

void Aluno::setAnoEntrada(int novoAno) {
    ano_entrada = novoAno;
}

void Aluno::setMediaGeral(double novaMedia) {
    media_geral = novaMedia;
}