#include "Pessoa.h"
#include <iostream>

using namespace std;

Pessoa::Pessoa(const string& login, const string& senha, const string& nome, int idade, const string& cpf, const string& sexo, const string& data_nascimento, const string& rg, const string& email, const string& endereco)
    : Usuario(login, senha), nome(nome), idade(idade), cpf(cpf), sexo(sexo), data_nascimento(data_nascimento), rg(rg), email(email), endereco(endereco) {}

string Pessoa::getNome() const {
    return nome;
}

int Pessoa::getIdade() const {
    return idade;
}

string Pessoa::getCpf() const {
    return cpf;
}

string Pessoa::getSexo() const {
    return sexo;
}

string Pessoa::getDataNascimento() const {
    return data_nascimento;
}

string Pessoa::getRg() const {
    return rg;
}

string Pessoa::getEmail() const {
    return email;
}

string Pessoa::getEndereco() const {
    return endereco;
}

void Pessoa::imprimirInformacoes() const {
    cout << "Nome: " << nome << endl;
    cout << "Idade: " << idade << endl;
    cout << "CPF: " << cpf << endl;
    cout << "Sexo: " << sexo << endl;
    cout << "Data de Nascimento: " << data_nascimento << endl;
    cout << "RG: " << rg << endl;
    cout << "Email: " << email << endl;
    cout << "Endereço: " << endereco << endl;
}

void Pessoa::setNome(const string& novoNome) {
    nome = novoNome;
}

void Pessoa::setIdade(int novaIdade) {
    idade = novaIdade;
}

void Pessoa::setCpf(const string& novoCpf) {
    cpf = novoCpf;
}

void Pessoa::setSexo(const string& novoSexo) {
    sexo = novoSexo;
}

void Pessoa::setDataNascimento(const string& novaDataNascimento) {
    data_nascimento = novaDataNascimento;
}

void Pessoa::setRg(const string& novoRg) {
    rg = novoRg;
}

void Pessoa::setEmail(const string& novoEmail) {
    email = novoEmail;
}

void Pessoa::setEndereco(const string& novoEndereco) {
    endereco = novoEndereco;
}