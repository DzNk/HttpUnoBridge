#include <exterrnal/crow_all.h>

#include "services/executor.hpp"

int main() {
    auto loop = ExecutorService();
    loop.PrintName();

    // crow::SimpleApp app;
    //
    // CROW_ROUTE(app, "/")([](const crow::request &req) {
    //     auto body = crow::json::load(req.body);
    //     auto data = body["data"];
    //     int value = data.i();
    //     return value;
    // });
    //
    // app.port(18080).multithreaded().run();
}
