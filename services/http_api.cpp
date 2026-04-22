#include  "http_api.hpp"

void HttpApiService::register_routes() {
    CROW_ROUTE(app, "/init").methods(crow::HTTPMethod::POST)
    ([](const crow::request &req) {
        return DocumentApiHandler::documentInit(req);
    });
}

void HttpApiService::run() {
    app.port(18080).run();
}
