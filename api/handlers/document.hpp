#pragma once
#include <crow.h>


class DocumentApiHandler {
public:
    DocumentApiHandler() = default;

    static crow::response documentInit(const crow::request &req);
};
