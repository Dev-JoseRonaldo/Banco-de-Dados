#ifndef VAGAHANDLERS_H
#define VAGAHANDLERS_H

#include <cpprest/http_listener.h>
#include <cpprest/json.h>
#include "models/vaga/Vaga.h"

extern std::vector<Vaga> vagas;
extern int next_id;

void criar_vaga(const web::http::http_request& request);
void listar_vagas(const web::http::http_request& request);
void atualizar_vaga(const web::http::http_request& request);
void deletar_vaga(const web::http::http_request& request);

#endif
