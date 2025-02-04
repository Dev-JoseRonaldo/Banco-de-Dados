#ifndef ALUNO_H
#define ALUNO_H

#include "Pessoa.h"
#include <string>

class Aluno : public Pessoa {
// Atributos privados (encapsulamento)
private:
    std::string numero_matricula;
    std::string curso;
    int ano_entrada;
    double media_geral;

public:
    // Construtor
    Aluno(const std::string& login, const std::string& senha, const std::string& nome, int idade, const std::string& cpf, const std::string& sexo, const std::string& data_nascimento, const std::string& rg, const std::string& email, const std::string& endereco,
          const std::string& numero_matricula, const std::string& curso, int ano_entrada, double media_geral);

    // Getters
    std::string getNumeroMatricula() const;
    std::string getCurso() const;
    int getAnoEntrada() const;
    double getMediaGeral() const;

    // Setters
    void setNumeroMatricula(const std::string& novoNumero);
    void setCurso(const std::string& novoCurso);
    void setAnoEntrada(int novoAno);
    void setMediaGeral(double novaMedia);
};

#endif