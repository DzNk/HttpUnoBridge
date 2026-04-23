#include "document_repository.hpp"

#include <nlohmann/json.hpp>
#include <uuid.h>


LibreOfficeDocumentRepository &LibreOfficeDocumentRepository::getInstance() {
    static LibreOfficeDocumentRepository instance;
    return instance;
}

std::string LibreOfficeDocumentRepository::registerDocument(const std::string &name) {
    std::random_device rd;
    auto seed_data = std::array<int, std::mt19937::state_size> {};

    std::ranges::generate(seed_data, std::ref(rd));
    std::seed_seq seq(std::begin(seed_data), std::end(seed_data));
    std::mt19937 generator(seq);
    uuids::uuid_random_generator gen{generator};

    const auto uuid_ = uuids::to_string(gen());
    std::lock_guard lock_guard(mutex_);
    documents[uuid_] = std::make_unique<LibreOfficeDocument>(name);
    return uuid_;
}
