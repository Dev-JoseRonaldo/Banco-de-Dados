#include <cpprest/http_listener.h>
#include <cpprest/json.h>
#include <iostream>
#include <thread>
#include <chrono>

using namespace web;
using namespace web::http;
using namespace web::http::experimental::listener;

void say_hello(const http_request& request) {
    json::value response_data;
    response_data[U("message")] = json::value::string(U("Hello world!"));

    request.reply(status_codes::OK, response_data);
}

int main() {
    http_listener listener(U("http://localhost:8080"));

    listener.support(methods::GET, [](const http_request& request) {
        if (request.relative_uri().path() == U("/hello")) {
            say_hello(request);
        }
    });

    try {

        listener
            .open()
            .then([]() { 
                std::wcout << L"Servidor rodando em http://localhost:8080" << std::endl; 
            })
            .wait();

        // Adicionando um loop de espera para manter o servidor de pé
        while (true) {
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
    } catch (const std::exception& e) {
        std::cerr << "An error occurred: " << e.what() << std::endl;
    }

    return 0;
}
