#ifndef SEARCHBYVALUE_H
#define SEARCHBYVALUE_H

#include "cmake-build-debug/Readtxt.h"
#include <list>
#include <utility>

class SearchByValue {
public:
    explicit SearchByValue(Readtxt& reader);
    std::list<std::pair<std::string, std::string>> searchByValue(const std::string& searchTerm) const;

private:
    Readtxt& reader_;
    static std::list<std::pair<std::string, std::string>> sequentialSearch(const std::list<std::pair<std::string, std::string>>& keys, const std::string& searchTerm);
};

#endif


