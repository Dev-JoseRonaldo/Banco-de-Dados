#include "Empresa.h"

using namespace std;

Empresa::Empresa(const string& nome, const string& cnpj, const string& email, const string& login, const string& senha)
    : Usuario(login, senha), nome(nome), cnpj(cnpj), email(email) {}

string Empresa::getNome() const {
    return nome;
}

string Empresa::getCnpj() const {
    return cnpj;
}

string Empresa::getEmail() const {
    return email;
}

void Empresa::setNome(const string& novoNome) {
    nome = novoNome;
}

void Empresa::setCnpj(const string& novoCnpj) {
    cnpj = novoCnpj;
}

void Empresa::setEmail(const string& novoEmail) {
    email = novoEmail;
}