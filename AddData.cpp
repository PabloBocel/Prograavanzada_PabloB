
#include "AddData.h"
#include "cmake-build-debug/Readtxt.h"
#include <fstream>
#include <iostream>

AddData::AddData(Readtxt& reader) : reader_(reader) {
}

void AddData::addDataFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cout << "Error: No se pudo abrir el archivo." << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        if (!line.empty()) {
            std::string hash_key = reader_.hashFunction(line);
            reader_.insertData(std::move(hash_key), std::move(line));

        }
    }

    file.close();

    reader_.sortList();
}
