#include "Usuario.h"
#include <iostream>

using namespace std;

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