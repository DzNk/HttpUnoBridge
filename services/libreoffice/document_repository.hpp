#pragma once
#include <memory>
#include <mutex>
#include <unordered_map>

#include "document.hpp"


class LibreOfficeDocumentRepository {
    mutable std::mutex mutex_;
    std::unordered_map<std::string, std::unique_ptr<LibreOfficeDocument> > documents;

protected:
    LibreOfficeDocumentRepository() = default;

public:
    LibreOfficeDocumentRepository(LibreOfficeDocumentRepository &other) = delete;

    void operator=(const LibreOfficeDocumentRepository &) = delete;

    static LibreOfficeDocumentRepository &getInstance();

    std::string registerDocument(const std::string &name);
};
