#ifndef READTXT_H
#define READTXT_H

#include <string>
#include <list>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>

class AddData;

class Readtxt {
public:
    // Estructura para almacenar datos
    struct KeyData {
        std::string key;
        std::vector<std::string> values;
    };

    // Estructura del nodo
    struct Node {
        KeyData data;
        Node* prev;
        Node* next;
        Node() : next(nullptr), prev(nullptr) {}
    };

    // Constructor y destructor
    Readtxt();
    explicit Readtxt(std::string filename);
    ~Readtxt();

    // Métodos públicos
    void insertData(const KeyData& data);
    void loadFromFile();
    std::list<std::pair<std::string, std::vector<std::string>>> getKeys() const;
    static std::string hashFunction(const std::string& key);
    void display();

private:
    // Miembros privados
    std::string filename_;
    Node* head;
    Node* tail;

    // Métodos privados
    void clearMemory();
    friend class AddData;
};

#endif  // READTXT_H

