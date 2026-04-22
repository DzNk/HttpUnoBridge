#include "document.hpp"

#include <nlohmann/json.hpp>

#include "schemas/api.hpp"
#include "services/libreoffice/document_repository.hpp"

crow::response DocumentApiHandler::documentInit(const crow::request &req) {
    auto inputJson = nlohmann::json::parse(req.body);
    auto documentInitRequest = inputJson.get<ApiSchemas::DocumentInitRequest>();

    auto &document_repository = LibreOfficeDocumentRepository::getInstance();
    const auto uuid_ = document_repository.registerDocument(documentInitRequest.name);

    ApiSchemas::DocumentInitResponse documentInitResponse(uuid_);

    crow::response response;
    response.set_header("Content-Type", crow::mime_types.at("json"));
    nlohmann::json jsonObject = documentInitResponse;
    response.body = jsonObject.dump();
    response.code = crow::status::CREATED;
    return response;
}
