#ifndef EMPRESA_H
#define EMPRESA_H

#include "Usuario.h"
#include <string>

// Declaração da classe
class Empresa : public Usuario {
// Atributos privados (encapsulamento)
private:
    std::string nome;
    std::string cnpj;
    std::string email;

public:
    // Construtor
    Empresa(const std::string& nome, const std::string& cnpj, const std::string& email, const std::string& login, const std::string& senha);

    // Getters
    std::string getNome() const;
    std::string getCnpj() const;
    std::string getEmail() const;

    // Setters
    void setNome(const std::string& novoNome);
    void setCnpj(const std::string& novoCnpj);
    void setEmail(const std::string& novoEmail);
};

#endif