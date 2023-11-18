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
            Readtxt::KeyData data;
            std::stringstream ss(line);
            std::string item;

            std::getline(ss, item, ',');
            data.key = reader_.hashFunction(item);

            while (std::getline(ss, item, ',')) {
                data.values.push_back(item);
            }

            reader_.insertData(data);
        }
    }

    file.close();

}

