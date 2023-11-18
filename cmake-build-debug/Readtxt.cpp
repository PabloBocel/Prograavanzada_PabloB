#include "Readtxt.h"
#include <fstream>
#include <iostream>
#include <sstream>

Readtxt::Readtxt() : head(nullptr), tail(nullptr) {}

Readtxt::Readtxt(std::string filename) : filename_(std::move(filename)), head(nullptr), tail(nullptr) {
    loadFromFile();
} //la primera accion que realiza desde el main

Readtxt::~Readtxt() {
    clearMemory();
}

std::list<std::pair<std::string, std::vector<std::string>>> Readtxt::getKeys() const {
    std::list<std::pair<std::string, std::vector<std::string>>> keys;
    Node* current = head;
    while (current) {
        keys.emplace_back(current->data.key, current->data.values);
        current = current->next;
    }
    return keys;
}

void Readtxt::loadFromFile() { //lee el archivo y crea el hash y lo mete a la lista de una vez
    std::ifstream file(filename_);
    if (!file.is_open()) {
        std::cerr << "Error: No se pudo abrir el archivo." << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        if (!line.empty()) {
            KeyData data;
            std::stringstream ss(line);
            std::string item;

            std::getline(ss, item, ',');
            data.key = hashFunction(item);

            while (std::getline(ss, item, ',')) {
                data.values.push_back(item);
            }

            insertData(data);
        }
    }

    file.close();
}

std::string Readtxt::hashFunction(const std::string& key) { // funcion hash con numeros
    size_t commaPos = key.find(',');
    std::string substringBeforeComma = key.substr(0, commaPos);

    std::hash<std::string> hasher;
    size_t hashValue = hasher(substringBeforeComma);

    return std::to_string(hashValue).substr(0, 10);
}

void Readtxt::insertData(const KeyData& data) { //lista doblemente enlazada
    try {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = nullptr;
        newNode->prev = tail;

        if (tail != nullptr) {
            tail->next = newNode;
        }
        tail = newNode;
        if (head == nullptr) {
            head = newNode;
        }
    } catch (const std::bad_alloc& e) {
        clearMemory();
        exit(EXIT_FAILURE);
    }
}

void Readtxt::clearMemory() { //limpiar memoria para potimizar el codigo
    Node* current = head;
    while (current != nullptr) {
        Node* temp = current->next;
        delete current;
        current = temp;
    }
    head = tail = nullptr;
}

void Readtxt::display() {
    Node* temp = head;
    while (temp != nullptr) {
        std::cout << temp->data.key << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}






