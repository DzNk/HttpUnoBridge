#pragma once
#include <functional>
#include <mutex>

#include "exterrnal/crow_all.h"

class HttpApiService {
    std::reference_wrapper<std::mutex> mutex_;
    std::reference_wrapper<std::vector<std::string> > data_map;

    crow::SimpleApp app;

public:
    HttpApiService(std::mutex &mtx, std::vector<std::string> &data)
        : mutex_(mtx), data_map(data) {
    }

    void register_routes() {
        CROW_ROUTE(app, "/item/add/<string>").methods(crow::HTTPMethod::POST)
        ([this](const std::string &item) {
            std::lock_guard lock(mutex_.get());
            data_map.get().push_back(item);
            return crow::response{crow::status::CREATED, item};
        });
    }

    void run() {
        app.port(18080).run();
    }
};
