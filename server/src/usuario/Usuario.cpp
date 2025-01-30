#include "Usuario.h"

Usuario::Usuario(std::string login, std::string senha) 
    : login(login), senha(senha) {}

std::string Usuario::getLogin() const {
    return login;
}

std::string Usuario::getSenha() const {
    return senha;
}

void Usuario::setLogin(const std::string& login) {
    this->login = login;
}

void Usuario::setSenha(const std::string& senha) {
    this->senha = senha;
}

// Implementação do método toJson
web::json::value Usuario::toJson() const {
    // Cria um objeto JSON contendo os dados do usuário
    web::json::value json_obj;
    json_obj[U("login")] = web::json::value::string(login);
    json_obj[U("senha")] = web::json::value::string(senha);
    
    return json_obj;
}
