#ifndef PESSOA_H
#define PESSOA_H

#include "Usuario.h"
#include <cpprest/json.h>  // Biblioteca para manipulação de JSON

class Pessoa : public Usuario {
private:
    std::string nome;
    int idade;
    std::string cpf;
    std::string sexo;
    std::string data_nascimento;
    std::string rg;
    std::string email;
    std::string endereco;

public:
    Pessoa(std::string login, std::string senha, std::string nome, int idade, std::string cpf,
           std::string sexo, std::string data_nascimento, std::string rg,
           std::string email, std::string endereco);
    std::string getNome() const;
    int getIdade() const;
    std::string getCpf() const;
    std::string getSexo() const;
    std::string getDataNascimento() const;
    std::string getRg() const;
    std::string getEmail() const;
    std::string getEndereco() const;
    void setNome(const std::string& nome);
    void setIdade(int idade);
    void setCpf(const std::string& cpf);
    void setSexo(const std::string& sexo);
    void setDataNascimento(const std::string& data_nascimento);
    void setRg(const std::string& rg);
    void setEmail(const std::string& email);
    void setEndereco(const std::string& endereco);
    
    // Método para converter Pessoa em JSON
    web::json::value toJson() const;

    virtual ~Pessoa() = default;
};

#endif
