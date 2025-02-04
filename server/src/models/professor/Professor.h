#ifndef PROFESSOR_H
#define PROFESSOR_H

#include "Pessoa.h"
#include <string>

class Professor : public Pessoa {
private:
    double salario;
    std::string tipo;

public:
    Professor(const std::string& login, const std::string& senha, const std::string& nome, int idade, const std::string& cpf, const std::string& sexo, const std::string& data_nascimento, const std::string& rg, const std::string& email, const std::string& endereco,
              double salario, const std::string& tipo);

    double getSalario() const;
    std::string getTipo() const;

    void setSalario(double novoSalario);
    void setTipo(const std::string& novoTipo);
};

#endif