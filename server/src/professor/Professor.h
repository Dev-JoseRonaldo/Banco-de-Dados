#ifndef PROFESSOR_H
#define PROFESSOR_H

#include "Pessoa.h"
#include <cpprest/json.h>  // Biblioteca para manipulação de JSON

class Professor : public Pessoa {
private:
    double salario;
    std::string tipo;

public:
    Professor(std::string login, std::string senha, std::string nome, int idade, std::string cpf, std::string sexo,
              std::string data_nascimento, std::string rg, std::string email, std::string endereco,
              double salario, std::string tipo);
    
    double getSalario() const;
    std::string getTipo() const;
    
    void setSalario(double salario);
    void setTipo(const std::string& tipo);
    
    // Sobrescrever o método toJson para incluir dados do Professor
    web::json::value toJson() const;

    virtual ~Professor() = default;
};

#endif
