#include <string>
#include "a6p2.h"

using namespace std;

// TODO - Implement the SmartHashTable class
SmartHashTable::SmartHashTable(): HashTable{}{}
SmartHashTable::SmartHashTable(int k): HashTable{k}{}
SmartHashTable::~SmartHashTable(){}
int SmartHashTable::hash(string key)const{
long sum = 0, mul = 1;
    unsigned int hash = 0;

    for (size_t i = 0; i < key.length(); i++)
    {
        hash += static_cast<unsigned char>(key[i]);
        hash += (hash << 10);
        hash ^= (hash >> 6);
    }

    hash += (hash << 3);
    hash ^= (hash >> 11);
    hash += (hash << 15);

    return hash % this->getTableSize();

    //https://en.wikipedia.org/wiki/Jenkins_hash_function
    //Source for has function, Jenkins hash function with small changes for implementing with string and set table size (uses mod at the end)
    }
