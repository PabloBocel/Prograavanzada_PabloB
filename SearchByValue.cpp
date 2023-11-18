#include "SearchByValue.h"
#include <iostream>
// esta parte del codigo encuentra el valor que se manda y muestra todas las llaves que contienen ese valor y la cantidad
//de estas
SearchByValue::SearchByValue(Readtxt& reader) : reader_(reader) {}

std::list<std::pair<std::string, std::vector<std::string>>> SearchByValue::searchByValue(const std::string& searchTerm) const {
    std::list<std::pair<std::string, std::vector<std::string>>> matchingPairs = sequentialSearch(reader_.getKeys(), searchTerm);

    std::cout << "Matching Hashes:" << std::endl;
    for (const auto& pair : matchingPairs) {
        std::cout << "Clave: " << pair.first << ", Valores: ";

        for (const auto& value : pair.second) {
            std::cout << value << " ";
        }

        std::cout << std::endl;
    }

    // Muestra la cantidad de los hashes encontrados con el mismo valor
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
                break;
            }
        }
    }

    return matchingPairs;
}



