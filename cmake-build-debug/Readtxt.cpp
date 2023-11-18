#include "Readtxt.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

Readtxt::Readtxt() : head(nullptr), tail(nullptr) {}

Readtxt::Readtxt(std::string filename) : filename_(std::move(filename)), head(nullptr), tail(nullptr) {
    loadFromFile();
}

std::list<std::pair<std::string, std::string>> Readtxt::getKeys() const {
    std::list<std::pair<std::string, std::string>> keys;
    Node* current = head;
    while (current) {
        keys.emplace_back(current->key, current->linea);
        current = current->next;
    }
    return keys;
}

void Readtxt::loadFromFile() {
    std::ifstream file(filename_);
    if (!file.is_open()) {
        std::cerr << "Error: No se pudo abrir el archivo." << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        if (!line.empty()) {
            std::vector<std::string> fields;
            std::istringstream ss(line);
            std::string field;

            for (int i = 0; std::getline(ss, field, ',') && i < 1; ++i) {
                std::string key = hashFunction(field);
                insertData(std::move(key), std::move(line));
            }
        }
    }

    file.close();
}

std::string Readtxt::hashFunction(const std::string& key) {
    size_t commaPos = key.find(',');
    std::string substringBeforeComma = key.substr(0, commaPos);

    std::hash<std::string> hasher;
    size_t hashValue = hasher(substringBeforeComma);

    return std::to_string(hashValue).substr(0, 10);
}

void Readtxt::insertData(std::string&& key, std::string&& linea) {
    Node* newNode = new Node(std::move(key), std::move(linea));
    if (!head) {
        head = newNode;
        tail = newNode;
    } else {
        Node* current = head;
        while (current && current->key < newNode->key) {
            current = current->next;
        }

        if (!current) {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        } else {
            if (current->prev) {
                current->prev->next = newNode;
                newNode->prev = current->prev;
            } else {
                head = newNode;
            }

            newNode->next = current;
            current->prev = newNode;
        }
    }
}

void Readtxt::sortList() {
}



