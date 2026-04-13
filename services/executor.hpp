#pragma once
#include <string>

class ExecutorService {
private:
    const std::mutex mutex_;

public:
    ExecutorService() {
    }
};
