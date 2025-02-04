#include "Professor.h"

using namespace std;

Professor::Professor(const string& login, const string& senha, const string& nome, int idade, const string& cpf, const string& sexo, const string& data_nascimento, const string& rg, const string& email, const string& endereco,
                    double salario, const string& tipo)
    : Pessoa(login, senha, nome, idade, cpf, sexo, data_nascimento, rg, email, endereco), salario(salario), tipo(tipo) {}

double Professor::getSalario() const {
    return salario;
}

string Professor::getTipo() const {
    return tipo;
}

void Professor::setSalario(double novoSalario) {
    salario = novoSalario;
}

void Professor::setTipo(const string& novoTipo) {
    tipo = novoTipo;
}