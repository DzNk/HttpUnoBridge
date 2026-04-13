#include <exterrnal/crow_all.h>

#include "services/executor.hpp"

int main() {
    auto executor = ExecutorService();
    executor.run();
}
