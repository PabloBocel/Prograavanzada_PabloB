
#ifndef READTXT_H
#define READTXT_H

#include <string>
#include <list>
#include <utility>

class SearchByKey;
class SearchByValue;

class Readtxt {
public:
    Readtxt();
    explicit Readtxt(std::string filename);
    void insertData(std::string&& key, std::string&& linea);

    void sortList();
    void loadFromFile();
    std::list<std::pair<std::string, std::string>> getKeys() const;
    static std::string hashFunction(const std::string& key);


private:
    std::string filename_;

    struct Node {
        std::string key;
        std::string linea;
        Node* prev;
        Node* next;
        Node(std::string k, std::string l) : key(std::move(k)), linea(std::move(l)), next(nullptr), prev(nullptr) {}
    };

    Node* head;
    Node* tail;

    friend class SearchByKey;
    friend class SearchByValue;
};

#endif