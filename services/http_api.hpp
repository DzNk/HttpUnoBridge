#pragma once

#include "api/handlers/document.hpp"


class HttpApiService {
    crow::SimpleApp app;

public:
    HttpApiService() = default;

    void register_routes();

    void run();
};
