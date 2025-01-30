#ifndef EMPRESA_H
#define EMPRESA_H

#include "Usuario.h"
#include <cpprest/json.h>  // Biblioteca para manipulação de JSON

class Empresa : public Usuario {
private:
    std::string nome;
    std::string cnpj;
    std::string email;

public:
    Empresa(std::string login, std::string senha, std::string nome, std::string cnpj, std::string email);
    
    std::string getNome() const;
    std::string getCnpj() const;
    std::string getEmail() const;
    
    void setNome(const std::string& nome);
    void setCnpj(const std::string& cnpj);
    void setEmail(const std::string& email);

    // Método para converter Empresa em JSON
    web::json::value toJson() const;

    virtual ~Empresa() = default;
};

#endif
