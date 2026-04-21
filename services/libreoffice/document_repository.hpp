#pragma once
#include <memory>
#include <mutex>
#include <unordered_map>

#include "document.hpp"


class LibreOfficeDocumentRepository {
    static std::mutex mutex_;
    static std::unordered_map<std::string, std::unique_ptr<LibreOfficeDocument> > documents;

protected:
    LibreOfficeDocumentRepository() = default;

    static LibreOfficeDocumentRepository *libre_office_document_repository_;

public:
    LibreOfficeDocumentRepository(LibreOfficeDocumentRepository &other) = delete;

    void operator=(const LibreOfficeDocumentRepository &) = delete;

    static LibreOfficeDocumentRepository *GetInstance();

    // void ();
};
