// C++ Code to implement Hash Table via seperate chaining

#include <iostream>
#include <list>
#include <stdc++.h>

using namespace std;

class HashTable {
    private:
        static const int hashGroups = 10;
        list<pair<int, string>> table[hashGroups]; // List 1, index 0; List2, index 1;....
    
    public:
        bool isEmpty() const;
        int hashFunction(int key);
        void insertItem(int key, string value);
        void removeItem(int key);
        string searchTable(int key);
        void printTable();
};

bool HashTable::isEmpty() const {
    int sum{};
    for (int i{}; i < hashGroups; i++) {
        sum += table[i].size();
    }

    if (!sum) return false;
    
    return true;
}

int HashTable::hashFunction(int key) {
    return key % hashGroups; // If key  is 905, in return, this function will give 5
}

void HasTable::insertItem(int key, string value) {
    int hashValue = hashFunction(key);
    auto& cell = table[hashValue];
    auto bItr = begin(cell);
    bool keyExists = false;

    for (; bItr != end(cell); bItr++) {
        if (bItr->first == key) {
            keyExists = true;
            bItr->second = value;
            cout << "[WARNING] Key exists. Value replaced." << endl;
            break;
        }
    }
    if (!keyExists) {
        cell.emplace_back(key, value);
    }

    return;
}

void HashTable::removeItem(int key) {
    int hashValue = hashFunction(key);
    auto& cell = table[hashValue];
    auto bItr = begin(cell);
    bool keyExists = false;

    for (; bItr != end(cell); bItr++) {
        if (bItr->first == key) {
            keyExists = true;
            bItr = cell.erase(bItr);
            cout << "[INFO] Pair Removed" << endl;
            break;
        }
    }

    if (!keyExists) {
        cout << "[WARNING] Key not found. Pair not removed." << endl;
    }

    return;
}

void HashTable::printTable() {
    for (int i{}; i < hashGroups; i++) {
        if (table[i].size() == 0) continue;

        auto bItr = table[i].begin();
        for (; bItr != table[i].end(); bItr++) {
            cout << "[INFO] Key " << bItr->first << " Value: " << bItr->second << endl;
        }
    }

    return;
}


int main() {
    HashTable HT;

    if (!HT.isEmpty()) {
        cout << "[INFO] The HashTable is empty." << endl;
    }
    else {
        cout << "[INFO] HashTable is not empty." << endl;
    }

    HT.insertItem(905, "Nik");
    HT.insertItem(101, "Jay");
    HT.insertItem(444, "Rob");
    HT.insertItem(309, "Van");
    HT.insertItem(477, "Sal");
    HT.insertItem(906, "Murr");
    HT.insertItem(906, "Q");

    HT.printTable();

    HT.removeItem(444);
    HT.removeItem(100);

    if (!HT.isEmpty()) {
        cout << "[INFO] The HashTable is empty." << endl;
    }
    else {
        cout << "[INFO] HashTable is not empty." << endl;
    }

    return 0;
}