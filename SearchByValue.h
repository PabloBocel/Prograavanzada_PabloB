#ifndef SEARCHBYVALUE_H
#define SEARCHBYVALUE_H

#include <list>
#include <utility>
#include "cmake-build-debug/Readtxt.h"

class SearchByValue {
public:
    SearchByValue(Readtxt& reader);

    std::list<std::pair<std::string, std::vector<std::string>>> searchByValue(const std::string& searchTerm) const;

private:
    Readtxt& reader_;

    static std::list<std::pair<std::string, std::vector<std::string>>> sequentialSearch(
            const std::list<std::pair<std::string, std::vector<std::string>>>& keys, const std::string& searchTerm) ;
};

#endif  // SEARCHBYVALUE_H



