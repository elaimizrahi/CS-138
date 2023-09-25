#include <string>
#include <vector>
#include <cctype>
#include <fstream>
#include <iostream>
#include <algorithm>
#include "HashTable.h"
#include "a6p1.h"
#include "a6p2.h"
#include "a6p3.h"

using namespace std;

const string errCantOpenFile = "Error: Couldn't open the given file";

// Ancillary function for powerset.  It adds a character onto the beginning
// of each string in a vector.
vector<string> addChar(const vector<string>& v, char c) {
    vector<string> ans;
    for (int i=0; i<(int)v.size() ; i++) {
		    ans.push_back(c + v.at(i));
    }
    return ans;
}

// Note that I wrote this in Scheme first!  Programming "shell game"
// recursion puzzles is easier with weak typing.
// This takes a string and returns the power(multi)set of its characters
// as a vector.  For example, powerset of "aab" would be the vector with
// elements (in no particular order): "aab" "ab" "aa" "a" "ab" "a" "b".
// Assume we don't care about eliminating duplicates for now.
vector<string> powerset(string s) {
    vector<string> ans;
    if (s.size() == 0) {
		    ans.push_back("");
    } else {
        char c = s.at(0);
        string rest = s.substr(1);
        vector<string> psetRest = powerset (rest);
        ans = addChar (psetRest, c);
        ans.insert(ans.end(), psetRest.begin(), psetRest.end());
    }
    return ans;
}

// TODO - Implement the two overloads of scrabbleValue()
int scrabbleValue(char c) {
    

    //cout<<c<<endl;
    if(c == 'e' || c == 'a' || c == 'i' || c == 'o' || c == 'n' || c == 'r' || c == 't' || c == 'l' || c == 's' || c == 'u' ){
        return 1;
    }
    else if(c == 'd' || c == 'g'){
        return 2;
    }
    else if(c == 'b' || c == 'c' || c == 'm' || c == 'p'){
        return 3;
    }    
    else if(c == 'f' || c == 'h' || c == 'v' || c == 'w' || c == 'y'){
        return 4;
    }
    else if(c == 'k'){
        return 5;
    }    
    else if(c == 'j'|| c == 'x' ){
        return 8;
    }
    else if(c == 'q'|| c == 'z' ){
        return 10;
    }
    else{
        cerr<<"Error: Recieved non-alphabetical character \'"<<c<<"\'"<<endl;
        assert(false);
    }
    
}

int scrabbleValue(string s) {
    int val = 0;
    for(auto i : s){
        val += scrabbleValue(tolower(i));
    }
    return val;
    // ...
}

// TODO - Put it all together and implement bestScrabbleWord
string bestScrabbleWord(string letters) {
    if(letters.size() == 0){
        return "";
    }
    int temp = scrabbleValue(letters);
    //transform(letters.begin(), letters.end(), letters.begin(), ::tolower);
    //cout<<letters<<endl;

    vector<string> set = powerset(letters);
    SmartHashTable ht{100000};
    ifstream dictionary{"twl-words.txt"};
    ht.insert(dictionary);
    //ht.report();
    int maxvalue = 0;
    string final = "";
    //int test = scrabbleValue(letters);
    for(auto i : set){
        string s = i;

        sort(s.begin(), s.end());
        //cout<<s<<endl;
        do{
            string lower = "";
            for(auto i : s){
               lower.push_back(tolower(i));
            }
            if(ht.lookup(lower)){
                int a = scrabbleValue(lower);
                //cout<<a<<s<<endl;
                if(a > maxvalue){
                    maxvalue = a;
                    final = s;
                }
            }
        }while(next_permutation (s.begin(), s.end()));

    }

    //cout<<"final"<<final<<endl;

    return final;

}
