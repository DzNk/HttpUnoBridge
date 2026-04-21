#pragma once

#include "http_api.hpp"

class ExecutorService {
    std::thread http_thread_;
    std::unique_ptr<HttpApiService> http_api_service_;

public:
    ExecutorService() {
        http_api_service_ = std::make_unique<HttpApiService>(
        );
    }

    void run() {
        http_api_service_->register_routes();
        http_thread_ = std::thread([this]() {
            http_api_service_->run();
        });
    }

    ~ExecutorService() {
        if (http_thread_.joinable()) {
            http_thread_.join();
        }
    }
};
