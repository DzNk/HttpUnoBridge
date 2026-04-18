#pragma once
#include <functional>
#include <mutex>
#include <string>
#include <crow.h>
#include <uuid.h>

#include "libreoffice/document.hpp"
#include "schemas/api.hpp"

class HttpApiService {
    std::reference_wrapper<std::mutex> mutex_;
    std::reference_wrapper<std::unordered_map<std::string, LibreOfficeDocument> > data_map;

    crow::SimpleApp app;

public:
    HttpApiService(std::mutex &mtx, std::unordered_map<std::string, LibreOfficeDocument> &data)
        : mutex_(mtx), data_map(data) {
    }

    void register_routes() {
        CROW_ROUTE(app, "/init").methods(crow::HTTPMethod::POST)
        ([this](const crow::request &req) {
            ApiSchemas::DocumentInitResponse documentInitResponse;

            auto inputJson = nlohmann::json::parse(req.body);
            auto documentInitRequest = inputJson.get<ApiSchemas::DocumentInitRequest>();
            documentInitResponse.name = documentInitRequest.name;

            uuids::uuid_system_generator gen;
            auto uuid_ = gen();
            documentInitResponse.uuid = uuids::to_string(uuid_);

            crow::response response;
            response.set_header("Content-Type", crow::mime_types.at("json"));

            nlohmann::json j = documentInitResponse;
            response.body = j.dump();

            // std::lock_guard lock(mutex_.get());
            return response;
        });
    }

    void run() {
        app.port(18080).run();
    }
};
