#ifndef USUARIO_H
#define USUARIO_H

#include <string>

class Usuario {
protected:
    std::string login;
    std::string senha;

public:
    Usuario(const std::string& login, const std::string& senha);

    std::string getLogin() const;
    std::string getSenha() const;

    void setLogin(const std::string& novoLogin);
    void setSenha(const std::string& novaSenha);

    virtual void cadastro();
};

#endif