#ifndef SEARCHBYKEY_H
#define SEARCHBYKEY_H

#include <list>
#include <utility>
#include "cmake-build-debug/Readtxt.h"

class SearchByKey {
public:
    SearchByKey(Readtxt& reader);

    std::list<std::pair<std::string, std::vector<std::string>>> binarySearch(const std::string& key) const;
    std::list<std::pair<std::string, std::vector<std::string>>> searchByKeyPrefix(const std::string& searchTerm) const;

private:
    Readtxt& reader_;
};

#endif  // SEARCHBYKEY_H

