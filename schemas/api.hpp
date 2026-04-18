#pragma once
#include <string>
#include <nlohmann/json.hpp>

namespace ApiSchemas {
    class DataInitResponse {
    public:
        std::string uuid;
        std::string name;
        NLOHMANN_DEFINE_TYPE_INTRUSIVE(DataInitResponse, uuid, name);
    };
}
