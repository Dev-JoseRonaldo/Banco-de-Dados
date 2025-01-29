#include "./Crow/include/crow.h"

int main() {
    crow::SimpleApp app;


    CROW_ROUTE(app, "/hello")
    ([](){
        return "Hello, World!";
    });

    app.port(8080).multithreaded().run();
}
