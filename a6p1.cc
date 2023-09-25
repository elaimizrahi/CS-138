#include <string>
#include <fstream>
#include "HashTable.h"
#include "a6p1.h"

using namespace std;

// TODO - Implement the SimpleHashTable class
SimpleHashTable::SimpleHashTable() : HashTable{}{}
SimpleHashTable::SimpleHashTable(int k) : HashTable{k}{}
SimpleHashTable::~SimpleHashTable(){
}
int SimpleHashTable::hash (string key) const{
    int hash = 0;
    for(auto i : key){
        hash += i;
    }
    return hash % this->getTableSize();
}

// TODO - Finsh off the implementation of the HashTable class
void HashTable::remove(string word) {
    Node *node = this->table[hash(word)];
    if(node == nullptr){
        return;
    }
    Node *prev = node;
    while(node->word != word){
        prev = node;
        node = node->next;
    }
    if(prev->word == node->word){
        delete node;
        this->table[hash(word)] = nullptr;
    }
    else{
        prev->next = node->next;
        delete node;
    }
}

void HashTable::insert(ifstream& file) {
    string s;
    while(getline(file, s)){
        Node* node = new Node{};
        node->word = s;
        Node* list = this->table[hash(s)];
        node->next = list;
        this->table[hash(s)] = node;
    }
}
