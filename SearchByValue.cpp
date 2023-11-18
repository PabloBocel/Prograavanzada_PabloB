#include "SearchByValue.h"
#include <iostream>

SearchByValue::SearchByValue(Readtxt& reader) : reader_(reader) {}

std::list<std::pair<std::string, std::vector<std::string>>> SearchByValue::searchByValue(const std::string& searchTerm) const {
    std::list<std::pair<std::string, std::vector<std::string>>> matchingPairs = sequentialSearch(reader_.getKeys(), searchTerm);

    // Output all matching pairs
    std::cout << "Matching Hashes:" << std::endl;
    for (const auto& pair : matchingPairs) {
        std::cout << "Clave: " << pair.first << ", Valores: ";

        // Iterar a través de los valores del vector e imprimir cada uno
        for (const auto& value : pair.second) {
            std::cout << value << " ";
        }

        std::cout << std::endl;
    }

    // Output the number of matching pairs
    std::cout << "Numero de Hashes encontrados: " << matchingPairs.size() << std::endl;

    return matchingPairs;
}

std::list<std::pair<std::string, std::vector<std::string>>> SearchByValue::sequentialSearch(
        const std::list<std::pair<std::string, std::vector<std::string>>>& keys, const std::string& searchTerm) {
    std::list<std::pair<std::string, std::vector<std::string>>> matchingPairs;

    for (const auto& pair : keys) {
        for (const auto& value : pair.second) {
            if (value.find(searchTerm) != std::string::npos) {
                matchingPairs.push_back(pair);
                break;  // Break out of the inner loop once a match is found
            }
        }
    }

    return matchingPairs;
}



