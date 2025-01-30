#include "Classes.h"
using namespace std;
#include <ostream>
#include <iostream>

// Métodos da classe Usuario
Usuario::Usuario(const string& login, const string& senha)
    : login(login), senha(senha) {}

string Usuario::getLogin() const {
    return login;
}

string Usuario::getSenha() const {
    return senha;
}

void Usuario::setLogin(const string& novoLogin) {
    login = novoLogin;
}

void Usuario::setSenha(const string& novaSenha) {
    senha = novaSenha;
}

void Usuario::cadastro() {
    cout << "Cadastro realizado com sucesso!" << endl;
}

// Métodos da classe Pessoa
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

// Métodos da classe Aluno
Aluno::Aluno(const string& login, const string& senha, const string& nome, int idade, const string& cpf, const string& sexo, const string& data_nascimento, const string& rg, const string& email, const string& endereco,
             const string& numero_matricula, const string& curso, int ano_entrada, double media_geral)
    : Pessoa(login, senha, nome, idade, cpf, sexo, data_nascimento, rg, email, endereco), numero_matricula(numero_matricula), curso(curso), ano_entrada(ano_entrada), media_geral(media_geral) {}

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

// Métodos da classe Professor
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

// Métodos da classe Empresa
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

// Métodos da classe Vaga
Vaga::Vaga(const string& descricao, const string& requisito, const string& beneficios)
    : descricao(descricao), requisito(requisito), beneficios(beneficios) {}

string Vaga::getDescricao() const {
    return descricao;
}

string Vaga::getRequisito() const {
    return requisito;
}

string Vaga::getBeneficios() const {
    return beneficios;
}

void Vaga::setDescricao(const string& novaDescricao) {
    descricao = novaDescricao;
}

void Vaga::setRequisito(const string& novoRequisito) {
    requisito = novoRequisito;
}

void Vaga::setBeneficios(const string& novosBeneficios) {
    beneficios = novosBeneficios;
}
