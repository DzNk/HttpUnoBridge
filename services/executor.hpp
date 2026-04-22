#pragma once

#include <thread>
#include "http_api.hpp"

class ExecutorService {
    std::thread http_thread_;
    std::unique_ptr<HttpApiService> http_api_service_;

public:
    ExecutorService();

    void run();

    ~ExecutorService();
};
