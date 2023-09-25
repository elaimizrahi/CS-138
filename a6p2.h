#ifndef A6P2_H
#define A6P2_H
#include <string>
#include "gtest/gtest.h"
#include "HashTable.h"

class SmartHashTable : public HashTable {
    public:
	    SmartHashTable();
	    SmartHashTable(int k) ;
	    virtual ~SmartHashTable();
    private:
	    int hash(std::string key) const;
	
	// Friend tests:
	FRIEND_TEST(SmartHashTablePub, testConstructorsPub);
	FRIEND_TEST(SmartHashTablePub, testThatTheHashFunctionWorks);
FRIEND_TEST(bestScrabbleWordPub, testNonLetterCharacterGivesCorrectDeath2);
FRIEND_TEST(bestScrabbleWordPub, bestWordThatCanBeMadeFromNothingIsNothing);
FRIEND_TEST(bestScrabbleWordPub, testNonLetterCharacterGivesCorrectDeath);
FRIEND_TEST(bestScrabbleWordPub, testNonLetterCharacterGivesCorrectDeath4);
FRIEND_TEST(bestScrabbleWordPub, testNonLetterCharacterGivesCorrectDeath5);
FRIEND_TEST(bestScrabbleWordPub, testNonLetterCharacterGivesCorrectDeath6);
    // FRIEND_TEST(..., ...) <- Your tests here
};

#endif
