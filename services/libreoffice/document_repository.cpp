#include "document_repository.hpp"

LibreOfficeDocumentRepository *LibreOfficeDocumentRepository::libre_office_document_repository_ = nullptr;

LibreOfficeDocumentRepository *LibreOfficeDocumentRepository::GetInstance() {
    std::lock_guard lock(mutex_);
    if (libre_office_document_repository_ == nullptr) {
        libre_office_document_repository_ = new LibreOfficeDocumentRepository();
    }
    return libre_office_document_repository_;
}
