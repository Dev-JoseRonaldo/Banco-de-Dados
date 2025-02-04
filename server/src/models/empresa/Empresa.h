#ifndef EMPRESA_H
#define EMPRESA_H

#include "Usuario.h"
#include <string>

class Empresa : public Usuario {
private:
    std::string nome;
    std::string cnpj;
    std::string email;

public:
    Empresa(const std::string& nome, const std::string& cnpj, const std::string& email, const std::string& login, const std::string& senha);

    std::string getNome() const;
    std::string getCnpj() const;
    std::string getEmail() const;

    void setNome(const std::string& novoNome);
    void setCnpj(const std::string& novoCnpj);
    void setEmail(const std::string& novoEmail);
};

#endif