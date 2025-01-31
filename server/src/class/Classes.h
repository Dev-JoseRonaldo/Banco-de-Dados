#ifndef CLASSES_H
#define CLASSES_H
using namespace std;

#include <string>

class Usuario {
protected:
    string login;
    string senha;

public:
    Usuario(const string& login, const string& senha);

    string getLogin() const;
    string getSenha() const;

    void setLogin(const string& novoLogin);
    void setSenha(const string& novaSenha);

    void cadastro();
};

// Classe Pessoa herda de Usuario
class Pessoa : public Usuario {
protected:
    string nome;
    int idade;
    string cpf;
    string sexo;
    string data_nascimento;
    string rg;
    string email;
    string endereco;

public:
    Pessoa(const string& login, const string& senha, const string& nome, int idade, const string& cpf, const string& sexo, const string& data_nascimento, const string& rg, const string& email, const string& endereco);
    
    string getNome() const;
    int getIdade() const;
    string getCpf() const;
    string getSexo() const;
    string getDataNascimento() const;
    string getRg() const;
    string getEmail() const;
    string getEndereco() const;

    void imprimirInformacoes() const;

    void setNome(const string& novoNome);
    void setIdade(int novaIdade);
    void setCpf(const string& novoCpf);
    void setSexo(const string& novoSexo);
    void setDataNascimento(const string& novaDataNascimento);
    void setRg(const string& novoRg);
    void setEmail(const string& novoEmail);
    void setEndereco(const string& novoEndereco);
};

// Classe Aluno herda de Pessoa
class Aluno : public Pessoa {
private:
    string numero_matricula;
    string curso;
    int ano_entrada;
    double media_geral;

public:
    Aluno(const string& login, const string& senha, const string& nome, int idade, const string& cpf, const string& sexo, const string& data_nascimento, const string& rg, const string& email, const string& endereco,
          const string& numero_matricula, const string& curso, int ano_entrada, double media_geral);

    string getNumeroMatricula() const;
    string getCurso() const;
    int getAnoEntrada() const;
    double getMediaGeral() const;

    void setNumeroMatricula(const string& novoNumero);
    void setCurso(const string& novoCurso);
    void setAnoEntrada(int novoAno);
    void setMediaGeral(double novaMedia);
};

// Classe Professor herda de Pessoa
class Professor : public Pessoa {
private:
    double salario;
    string tipo;

public:
    Professor(const string& login, const string& senha, const string& nome, int idade, const string& cpf, const string& sexo, const string& data_nascimento, const string& rg, const string& email, const string& endereco,
              double salario, const string& tipo);

    double getSalario() const;
    string getTipo() const;

    void setSalario(double novoSalario);
    void setTipo(const string& novoTipo);
};

// Classe Empresa herda de Usuario
class Empresa : public Usuario {
private:
    string nome;
    string cnpj;
    string email;

public:
    Empresa(const string& nome, const string& cnpj, const string& email, const string& login, const string& senha);

    string getNome() const;
    string getCnpj() const;
    string getEmail() const;

    void setNome(const string& novoNome);
    void setCnpj(const string& novoCnpj);
    void setEmail(const string& novoEmail);
};

#endif // CLASSES_H