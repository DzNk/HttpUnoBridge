#include "document.hpp"

#include <utility>

LibreOfficeDocument::LibreOfficeDocument(std::string name) : name_(std::move(name)) {
}
