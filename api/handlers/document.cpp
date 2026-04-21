#include "document.hpp"

#include <nlohmann/json.hpp>
#include <uuid.h>

#include "schemas/api.hpp"

crow::response DocumentApiHandler::documentInit(const crow::request &req) {
    ApiSchemas::DocumentInitResponse documentInitResponse;

    auto inputJson = nlohmann::json::parse(req.body);
    auto documentInitRequest = inputJson.get<ApiSchemas::DocumentInitRequest>();
    documentInitResponse.name = documentInitRequest.name;

    uuids::uuid_system_generator gen;
    auto uuid_ = gen();
    documentInitResponse.uuid = uuids::to_string(uuid_);

    crow::response response;
    response.set_header("Content-Type", crow::mime_types.at("json"));

    nlohmann::json j = documentInitResponse;
    response.body = j.dump();
    return crow::response(crow::status::CREATED);
}
