#ifndef USUARIO_H
#define USUARIO_H

#include <string>
#include <cpprest/json.h>  // Biblioteca para manipulação de JSON

class Usuario {
private:
    std::string login;
    std::string senha;

public:
    Usuario(std::string login, std::string senha);
    std::string getLogin() const;
    std::string getSenha() const;
    void setLogin(const std::string& login);
    void setSenha(const std::string& senha);
    
    // Adiciona o método toJson
    virtual web::json::value toJson() const;

    virtual ~Usuario() = default;
};

#endif
