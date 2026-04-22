#include "executor.hpp"

ExecutorService::ExecutorService() {
    http_api_service_ = std::make_unique<HttpApiService>();
}

void ExecutorService::run() {
    http_api_service_->register_routes();
    http_thread_ = std::thread([this]() {
        http_api_service_->run();
    });
}

ExecutorService::~ExecutorService() {
    if (http_thread_.joinable()) {
        http_thread_.join();
    }
}
