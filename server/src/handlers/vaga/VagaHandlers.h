#ifndef VAGAHANDLERS_H
#define VAGAHANDLERS_H

#include <cpprest/http_listener.h>
#include <cpprest/json.h>
#include "models/vaga/Vaga.h"

extern std::vector<Vaga> vagas; // Vetor global que armazena as vagas
extern int next_id; // Variável global que armazena o próximo ID a ser usado

// Declaração das funções handlers para as requisições HTTP

// Função handler para criar uma nova vaga (requisição POST para /vagas)
void criar_vaga(const web::http::http_request& request);

// Função handler para listar todas as vagas (requisição GET para /vagas)
void listar_vagas(const web::http::http_request& request);

// Função handler para atualizar uma vaga existente (requisição PUT para /vagas/{id})
void atualizar_vaga(const web::http::http_request& request);

// Função handler para deletar uma vaga (requisição DELETE para /vagas/{id})
void deletar_vaga(const web::http::http_request& request);

#endif
