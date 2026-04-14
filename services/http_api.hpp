#pragma once
#include <functional>
#include <mutex>
#include <string>
#include <crow.h>

class HttpApiService {
    std::reference_wrapper<std::mutex> mutex_;
    std::reference_wrapper<std::vector<std::string> > data_map;

    crow::SimpleApp app;

public:
    HttpApiService(std::mutex &mtx, std::vector<std::string> &data)
        : mutex_(mtx), data_map(data) {
    }

    void register_routes() {
        CROW_ROUTE(app, "/item/add").methods(crow::HTTPMethod::POST)
        ([this](const crow::request &req) {
            req.body;
            std::lock_guard lock(mutex_.get());
            return crow::response(400);
        });
    }

    void run() {
        app.port(18080).run();
    }
};
