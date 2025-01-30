#ifndef ALUNO_H
#define ALUNO_H

#include "Pessoa.h"
#include <cpprest/json.h>  // Para trabalhar com JSON

class Aluno : public Pessoa {
private:
    std::string numero_matricula;
    std::string curso;
    int ano_matricula;
    double media_geral;

public:
    Aluno(std::string login, std::string senha, std::string nome, int idade, std::string cpf, std::string sexo,
          std::string data_nascimento, std::string rg, std::string email, std::string endereco,
          std::string numero_matricula, std::string curso, int ano_matricula, double media_geral);

    std::string getNumeroMatricula() const;
    std::string getCurso() const;
    int getAnoMatricula() const;
    double getMediaGeral() const;

    void setNumeroMatricula(const std::string& numero_matricula);
    void setCurso(const std::string& curso);
    void setAnoMatricula(int ano_matricula);
    void setMediaGeral(double media_geral);

    // Declaração do método virtual para converter Aluno em JSON
    virtual web::json::value toJson() const;

    virtual ~Aluno() = default;
};

#endif
