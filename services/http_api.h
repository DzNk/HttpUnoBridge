#pragma once
#include <functional>
#include <mutex>

#include "exterrnal/crow_all.h"

class HttpApiService {
private:
    std::reference_wrapper<std::mutex> mutex_;
    crow::SimpleApp app;

public:
    HttpApiService(std::mutex &mutex) {
        mutex_ = mutex;

        CROW_ROUTE(app, "/add/<int>/<int>")
        ([](int a, int b) {
            return std::to_string(a + b);
        });
    }
};
