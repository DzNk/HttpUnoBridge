#pragma once

#include <string>
#include <nlohmann/json.hpp>

namespace ApiSchemas {
    struct DocumentInitRequest {
        std::string name;
        NLOHMANN_DEFINE_TYPE_INTRUSIVE(DocumentInitRequest, name);
    };

    struct DocumentInitResponse {
        std::string uuid;
        NLOHMANN_DEFINE_TYPE_INTRUSIVE(DocumentInitResponse, uuid);
    };
}
