#include "Classes.h"
#include <iostream>

using namespace std;

int main() {
    // Criando uma Pessoa (que herda de Usuario)
    Pessoa pessoa("pessoa123", "senhaPessoa", "Carlos Silva", 30, "123.456.789-00", "M", "01/01/1994", "MG123456", "carlos@email.com", "Rua A, 123");
    cout << "Pessoa Original: " << endl;
    pessoa.imprimirInformacoes();
    cout << "Login: " << pessoa.getLogin() << endl;
    cout << "Senha: " << pessoa.getSenha() << endl;
    
    // Testando os set
    pessoa.setNome("João Pereira");
    pessoa.setIdade(35);
    pessoa.setCpf("987.654.321-00");
    pessoa.setEndereco("Rua D, 987");
    pessoa.setEmail("joao@email.com");
    pessoa.setLogin("joao123");
    pessoa.setSenha("novaSenha123");

    cout << "\nPessoa após alterações: " << endl;
    pessoa.imprimirInformacoes();
    cout << "Login: " << pessoa.getLogin() << endl;
    cout << "Senha: " << pessoa.getSenha() << endl;
    cout << endl;

    // Criando um Aluno (que herda de Pessoa)
    Aluno aluno("aluno123", "senhaAluno", "Ana Oliveira", 20, "987.654.321-00", "F", "05/02/2003", "SP987654", "ana@email.com", "Rua B, 456", 
                "A12345", "Engenharia", 2021, 8.5);
    cout << "Aluno Original: " << endl;
    aluno.imprimirInformacoes();
    cout << "Número de Matrícula: " << aluno.getNumeroMatricula() << endl;
    cout << "Curso: " << aluno.getCurso() << endl;

    // Testando os set
    aluno.setNome("Maria Costa");
    aluno.setIdade(22);
    aluno.setCpf("123.456.789-00");
    aluno.setCurso("Sistemas de Informação");
    aluno.setAnoEntrada(2020);
    aluno.setMediaGeral(9.2);

    cout << "\nAluno após alterações: " << endl;
    aluno.imprimirInformacoes();
    cout << "Número de Matrícula: " << aluno.getNumeroMatricula() << endl;
    cout << "Curso: " << aluno.getCurso() << endl;
    cout << "Ano de Entrada: " << aluno.getAnoEntrada() << endl;
    cout << "Média Geral: " << aluno.getMediaGeral() << endl;
    cout << endl;

    // Criando um Professor (que herda de Pessoa)
    Professor professor("professor123", "senhaProfessor", "João Souza", 45, "321.654.987-00", "M", "12/03/1978", "RJ654321", "joao@email.com", "Rua C, 789", 
                        5000.00, "Titular");
    cout << "Professor Original: " << endl;
    professor.imprimirInformacoes();
    cout << "Salário: " << professor.getSalario() << endl;
    cout << "Tipo de Professor: " << professor.getTipo() << endl;

    // Testando os set
    professor.setNome("Carlos Silva");
    professor.setIdade(50);
    professor.setCpf("654.321.987-00");
    professor.setSalario(5500.00);
    professor.setTipo("Adjunto");

    cout << "\nProfessor após alterações: " << endl;
    professor.imprimirInformacoes();
    cout << "Salário: " << professor.getSalario() << endl;
    cout << "Tipo de Professor: " << professor.getTipo() << endl;
    cout << endl;

    // Criando uma Empresa (que herda de Usuario)
    Empresa empresa("Tech Ltda", "12.345.678/0001-90", "empresa@email.com", "empresa123", "senhaEmpresa");
    cout << "Empresa Original: " << endl;
    cout << "Nome: " << empresa.getNome() << endl;
    cout << "CNPJ: " << empresa.getCnpj() << endl;
    cout << "Email: " << empresa.getEmail() << endl;
    cout << "Login: " << empresa.getLogin() << endl;
    cout << "Senha: " << empresa.getSenha() << endl;

    // Testando os set
    empresa.setNome("Tech Solutions");
    empresa.setCnpj("98.765.432/0001-99");
    empresa.setEmail("tech@email.com");
    empresa.setLogin("tech123");
    empresa.setSenha("novaSenhaTech");

    cout << "\nEmpresa após alterações: " << endl;
    cout << "Nome: " << empresa.getNome() << endl;
    cout << "CNPJ: " << empresa.getCnpj() << endl;
    cout << "Email: " << empresa.getEmail() << endl;
    cout << "Login: " << empresa.getLogin() << endl;
    cout << "Senha: " << empresa.getSenha() << endl;
    cout << endl;

    // Criando uma Vaga
    Vaga vaga("Desenvolvedor de Software", "Conhecimento em C++, Java", "Vale transporte, plano de saúde");
    cout << "Vaga Original: " << endl;
    cout << "Descrição: " << vaga.getDescricao() << endl;
    cout << "Requisitos: " << vaga.getRequisito() << endl;
    cout << "Benefícios: " << vaga.getBeneficios() << endl;

    // Testando os set
    vaga.setDescricao("Desenvolvedor Full Stack");
    vaga.setRequisito("Conhecimento em React, Node.js");
    vaga.setBeneficios("Vale alimentação, plano de saúde, home office");

    cout << "\nVaga após alterações: " << endl;
    cout << "Descrição: " << vaga.getDescricao() << endl;
    cout << "Requisitos: " << vaga.getRequisito() << endl;
    cout << "Benefícios: " << vaga.getBeneficios() << endl;
    cout << endl;

    return 0;
}