#ifndef PESSOA_H
#define PESSOA_H

#include "Usuario.h"
#include <string>

class Pessoa : public Usuario {
protected:
    std::string nome;
    int idade;
    std::string cpf;
    std::string sexo;
    std::string data_nascimento;
    std::string rg;
    std::string email;
    std::string endereco;

public:
    Pessoa(const std::string& login, const std::string& senha, const std::string& nome, int idade, const std::string& cpf, const std::string& sexo, const std::string& data_nascimento, const std::string& rg, const std::string& email, const std::string& endereco);

    std::string getNome() const;
    int getIdade() const;
    std::string getCpf() const;
    std::string getSexo() const;
    std::string getDataNascimento() const;
    std::string getRg() const;
    std::string getEmail() const;
    std::string getEndereco() const;

    void imprimirInformacoes() const;

    void setNome(const std::string& novoNome);
    void setIdade(int novaIdade);
    void setCpf(const std::string& novoCpf);
    void setSexo(const std::string& novoSexo);
    void setDataNascimento(const std::string& novaDataNascimento);
    void setRg(const std::string& novoRg);
    void setEmail(const std::string& novoEmail);
    void setEndereco(const std::string& novoEndereco);
};

#endif