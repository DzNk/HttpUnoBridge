#include "document_repository.hpp"

#include <nlohmann/json.hpp>
#include <uuid.h>


LibreOfficeDocumentRepository &LibreOfficeDocumentRepository::getInstance() {
    static LibreOfficeDocumentRepository instance;
    return instance;
}

std::string LibreOfficeDocumentRepository::registerDocument(const std::string &name) {
    uuids::uuid_system_generator gen;
    const auto uuid_ = uuids::to_string(gen());
    std::lock_guard lock_guard(mutex_);
    documents[uuid_] = std::make_unique<LibreOfficeDocument>(name);
    return uuid_;
}
