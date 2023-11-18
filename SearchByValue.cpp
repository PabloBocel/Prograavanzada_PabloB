
#include "SearchByValue.h"
#include "iostream"

SearchByValue::SearchByValue(Readtxt& reader) : reader_(reader) {}

std::list<std::pair<std::string, std::string>> SearchByValue::searchByValue(const std::string& searchTerm) const {
    std::list<std::pair<std::string, std::string>> matchingPairs = sequentialSearch(reader_.getKeys(), searchTerm);

    // Output all matching pairs
    std::cout << "Matching Hashes:" << std::endl;
    for (const auto& pair : matchingPairs) {
        std::cout << "Clave: " << pair.first << ", Valor: " << pair.second << std::endl;
    }

    // Output the number of matching pairs
    std::cout << "Numero de Hashes encontrados: " << matchingPairs.size() << std::endl;

    return matchingPairs;
}

std::list<std::pair<std::string, std::string>> SearchByValue::sequentialSearch(const std::list<std::pair<std::string, std::string>>& keys, const std::string& searchTerm) {
    std::list<std::pair<std::string, std::string>> matchingPairs;

    for (const auto& pair : keys) {
        if (pair.second.find(searchTerm) != std::string::npos) {
            matchingPairs.push_back(pair);
        }
    }

    return matchingPairs;
}


