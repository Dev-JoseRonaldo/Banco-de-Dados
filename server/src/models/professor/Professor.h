#ifndef PROFESSOR_H
#define PROFESSOR_H

#include "Pessoa.h"
#include <string>

// Declaração da classe (herda de pessoa)
class Professor : public Pessoa {
// Atributos protecteds (encapsulamento)
private:
    double salario;
    std::string tipo;

// Construtor
public:
    Professor(const std::string& login, const std::string& senha, const std::string& nome, int idade, const std::string& cpf, const std::string& sexo, const std::string& data_nascimento, const std::string& rg, const std::string& email, const std::string& endereco,
              double salario, const std::string& tipo);

    // Getters
    double getSalario() const;
    std::string getTipo() const;

    // Setters
    void setSalario(double novoSalario);
    void setTipo(const std::string& novoTipo);
};

#endif