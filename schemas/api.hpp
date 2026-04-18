#pragma once
#include <string>
#include <nlohmann/json.hpp>

namespace ApiSchemas {
    struct DocumentInitResponse {
        std::string uuid;
        std::string name;

        NLOHMANN_DEFINE_TYPE_INTRUSIVE(DocumentInitResponse, uuid, name);
    };

    struct DocumentInitRequest {
        std::string name;
        std::string name2;
        NLOHMANN_DEFINE_TYPE_INTRUSIVE(DocumentInitRequest, name, name2);
    };
}
