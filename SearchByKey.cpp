#include "SearchByKey.h"
#include "cmake-build-debug/Readtxt.h"
#include <iostream>

SearchByKey::SearchByKey(Readtxt& reader) : reader_(reader) {}

std::list<std::pair<std::string, std::vector<std::string>>> SearchByKey::binarySearch(const std::string& key) const {
    std::list<std::pair<std::string, std::vector<std::string>>> matchingSets;
    auto keys = reader_.getKeys();

    keys.sort([](const std::pair<std::string, std::vector<std::string>>& lhs, const std::pair<std::string, std::vector<std::string>>& rhs) {
        return lhs.first < rhs.first;
    });

    auto begin = keys.begin();
    auto end = keys.end();

    std::cout << "Searching for key: " << key << std::endl;

    while (begin != end) {
        auto mid = std::next(begin, std::distance(begin, end) / 2);

        if (mid->first == key) {
            matchingSets.push_back(*mid);

            auto temp = mid;
            while (temp != begin && (--temp)->first == key) {
                matchingSets.push_front(*temp);
            }
            temp = mid;
            while (++temp != end && temp->first == key) {
                matchingSets.push_back(*temp);
            }

            return matchingSets;
        } else if (mid->first < key) {
            begin = std::next(mid);
        } else {
            end = mid;
        }
    }

    return matchingSets;
}

std::list<std::pair<std::string, std::vector<std::string>>> SearchByKey::searchByKeyPrefix(const std::string& searchTerm) const {
    std::string hashedSearchTerm = Readtxt::hashFunction(searchTerm);

    return binarySearch(hashedSearchTerm);
}