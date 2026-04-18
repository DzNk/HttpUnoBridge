#pragma once
#include <functional>
#include <mutex>
#include <string>
#include <crow.h>
#include <uuid.h>
#include "schemas/api.hpp"

class HttpApiService {
    std::reference_wrapper<std::mutex> mutex_;
    std::reference_wrapper<std::vector<std::string> > data_map;

    crow::SimpleApp app;

public:
    HttpApiService(std::mutex &mtx, std::vector<std::string> &data)
        : mutex_(mtx), data_map(data) {
    }

    void register_routes() {
        CROW_ROUTE(app, "/init").methods(crow::HTTPMethod::POST)
        ([this](const crow::request &req) {
            ApiSchemas::DataInitResponse resp;
            uuids::uuid_system_generator gen;
            auto u = gen();
            resp.uuid = uuids::to_string(u);
            resp.name = "valera";

            nlohmann::json j = resp;

            crow::response res;
            res.set_header("Content-Type", "application/json");
            res.body = j.dump();
            return res;
            // std::lock_guard lock(mutex_.get());
        });
    }

    void run() {
        app.port(18080).run();
    }
};
