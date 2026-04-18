# pragma once
#include <string>
#include <utility>

class LibreOfficeDocument {
    std::string name_;

public:
    explicit LibreOfficeDocument(std::string name) : name_(std::move(name)) {
    }
};
