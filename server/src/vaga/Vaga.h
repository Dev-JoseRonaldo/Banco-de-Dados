#ifndef VAGA_H
#define VAGA_H

#include <cpprest/json.h>
#include <string>

class Vaga {
private:
    int id;
    std::string titulo;
    std::string descricao;
    std::string empresa;
    std::string data_abertura;
    double salario;

public:
    // Construtor
    Vaga(int id, std::string titulo, std::string descricao, std::string empresa, std::string data_abertura, double salario);

    // Getters
    int getId() const;
    std::string getTitulo() const;
    std::string getDescricao() const;
    std::string getEmpresa() const;
    std::string getDataAbertura() const;
    double getSalario() const;

    // Setters
    void setTitulo(const std::string& t);
    void setDescricao(const std::string& d);
    void setEmpresa(const std::string& e);
    void setDataAbertura(const std::string& da);
    void setSalario(double s);

    // Serializa para JSON
    web::json::value toJson() const;
};

#endif
