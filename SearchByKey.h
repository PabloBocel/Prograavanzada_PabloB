#ifndef SEARCHBYKEY_H
#define SEARCHBYKEY_H

#include "cmake-build-debug/Readtxt.h"
#include <list>
#include <utility>

class SearchByKey {
public:
    explicit SearchByKey(Readtxt& reader);
    std::list<std::pair<std::string, std::string>> searchByKeyPrefix(const std::string& searchTerm) const;

private:
    Readtxt& reader_;
    std::list<std::pair<std::string, std::string>> binarySearch(const std::string& key) const;
};

#endif
