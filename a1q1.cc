/*
* CS138, W23, Assignment 1, Problem 1
* Main Function
*
* main function is a special function,
* which serves as the entry point for the program.
* 
* Try to keep it as simple as possible
* and implement the logic of your program
* in a1q1.cpp, so that you can write unit tests
* for them and make sure of their expected behavior.
*/
#include <iostream>
#include <vector>
using namespace std;

// no argc+argv because we aren't using them in A1
int main() {
    int i;
    cin >> i;
    if(i <= 0){
        cerr << "Error, line length must be positive."<<endl;
        exit(1);
    }
    cin.ignore();       
    string s;
    while(getline(cin, s)){
        if(cin.fail()){
            break;
        }
        else{
            cout<<s.substr(0,i)<<endl;
            s.clear(); 
        }
        
    }
    return 0;
}
