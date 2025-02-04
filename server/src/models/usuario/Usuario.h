#ifndef USUARIO_H
#define USUARIO_H

#include <string>

// Declaração da classe
class Usuario {
// Atributos protecteds (encapsulamento)
protected:
    std::string login;
    std::string senha;

public:
    // Construtor
    Usuario(const std::string& login, const std::string& senha);

    // Getters
    std::string getLogin() const;
    std::string getSenha() const;

    // Setters
    void setLogin(const std::string& novoLogin);
    void setSenha(const std::string& novaSenha);

    // Método virtal para classes derivadas implementem seu próprio cadastro (polimorfismo)
    virtual void cadastro();
};

#endif