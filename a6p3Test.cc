#include <string>
#include "gtest/gtest.h"
#include "a6p3.h"

using namespace std;

// By default this file contains copies of the Marmoset tests in a6p3c.
// Currently they get 70% coverage on our solution. To pass the a6p3t coverage
// test you will need to augment them so that they get full coverage (100%
// lines executed).

// Note: The provided powerset and addChar functions were moved to another file
// in the solution on Marmoset, so you don't have to worry about covering them
// in a6p3t. Just focus on the two scabbleValue overloads and bestScrabbleWord

TEST(scrabbleValueCharPub, testAFewChars) {
    EXPECT_EQ(scrabbleValue('a'), 1);
    EXPECT_EQ(scrabbleValue('b'), 3);
    EXPECT_EQ(scrabbleValue('c'), 3);
}

TEST(scrabbleValueCharPub, testNonLetterCharacterGivesCorrectDeath) {
    EXPECT_DEATH(scrabbleValue('1'), "Error: Recieved non-alphabetical character \'1\'");
}

TEST(scrabbleValueStringPub, testEmptyStringHasValueZero) {
    EXPECT_EQ(scrabbleValue(""), 0);
}

TEST(scrabbleValueStringPub, testNonLetterCharacterGivesCorrectDeath) {
    EXPECT_DEATH(scrabbleValue("2"), "Error: Recieved non-alphabetical character \'2\'");
}

TEST(bestScrabbleWordPub, bestWordThatCanBeMadeFromNothingIsNothing) {
    EXPECT_EQ(bestScrabbleWord(""), "");
}

TEST(bestScrabbleWordPub, testNonLetterCharacterGivesCorrectDeath) {
    EXPECT_DEATH(bestScrabbleWord("3"), "Error: Recieved non-alphabetical character \'3\'");
}
TEST(bestScrabbleWordPub, testNonLetterCharacterGivesCorrectDeath2) {
    EXPECT_EQ(bestScrabbleWord("scsduhds"), "schuss");
}

TEST(bestScrabbleWordPub, testNonLetterCharacterGivesCorrectDeath3) {
    EXPECT_EQ(bestScrabbleWord("scsduhds"), "schuss");
}
TEST(bestScrabbleWordPub, testNonLetterCharacterGivesCorrectDeath4) {
    EXPECT_EQ(bestScrabbleWord("dsAfde"), "fAded");
}

TEST(bestScrabbleWordPub, testNonLetterCharacterGivesCorrectDeath5) {
    EXPECT_EQ(bestScrabbleWord("lOjbAw"), "jOwl");
}
TEST(bestScrabbleWordPub, testNonLetterCharacterGivesCorrectDeath6) {
        cout << bestScrabbleWord("dog") << endl;
    cout << bestScrabbleWord("Dog") << endl;
    cout << bestScrabbleWord("apple") << endl;
    cout << bestScrabbleWord("aPple") << endl;
    cout << bestScrabbleWord("apPle") << endl;
    cout << bestScrabbleWord("APPLE") << endl;
    cout << bestScrabbleWord("race") << endl;
    cout << bestScrabbleWord("care") << endl;
}