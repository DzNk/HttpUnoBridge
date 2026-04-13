#pragma once
#include <mutex>

#include "http_api.hpp"

class ExecutorService {
    std::mutex mutex_;
    std::vector<std::string> data_map;

    std::thread http_thread_;
    std::unique_ptr<HttpApiService> http_api_service_;

public:
    ExecutorService() {
        http_api_service_ = std::make_unique<HttpApiService>(
            std::ref(mutex_),
            std::ref(data_map)
        );
    }

    void run() {
        http_api_service_->register_routes();
        http_thread_ = std::thread([this]() {
            http_api_service_->run();
        });

        while (true) {
            {
                std::lock_guard lock(mutex_);
                std::cout << "Size of map - " << data_map.size() << std::endl;
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
    }

    ~ExecutorService() {
        if (http_thread_.joinable()) {
            http_thread_.join();
        }
    }
};
