/*
* CS138, W23, Assignment 1, Problem 3
* Main Function
*
* main function is a special function,
* which serves as the entry point for the program.
* 
* Try to keep it as simple as possible
* and implement the logic of your program
* in a1q3.cpp, so that you can write unit tests
* for them and make sure of their expected behavior.
*/
#include <iostream>
#include <vector>
using namespace std;

// no argc+argv because we aren't using them in A1
int main() {
    int n;
    vector<string> v{};
    string s;
    cin>>n;
    if(n <= 0){
        cerr << "Error, line length must be positive."<<endl;
        exit(1);
    }
    cin.ignore();
   // while(getline(cin, s)){
   //     v.push_back(s);
   // }        
    string line;
    string curword;
    int wordcount = 0;
    int linecount = 0;
    bool condition = true;
    while(cin>>line){
        v.push_back(line);
    }
    for(auto i:v){
        for(auto j:i){
            wordcount++;
        }
        if(wordcount > n){
            if(linecount){
                cout<<endl;
            }
            for(int j = 0; j < n; j++){
                cout<<i[j];
            }
            cout<<endl;
            linecount = 0;
            wordcount = 0;
            condition = true;
        }
        else if(wordcount + linecount>n){
            cout<<endl;
            cout<<i;
            linecount = wordcount + 1;
            wordcount = 0;
        }
        else{
            if(condition){
                cout<<i;
                condition = false; 
            }
            else{cout<<" "<<i;}        
            linecount = linecount+ wordcount;
            wordcount = 0;
            linecount++;
}

    }   

    // TODO: Solve the problem!
    cout<<endl;
    return 0;
}
// for(auto i:v){
   //     for(auto j:i){
   //         while(j != ' ')
   //         cout<<j<<endl;
   //         wordcount++;
   //        }
   //     
   //         if(wordcount > n){
   //             for(int k = 0; k < n; k++){
   //                 //cout<<i[k];
   //             }
   //             cout<<endl;
   //         }
   //         else if(wordcount+linecount > n){
   //             cout<<endl;
   //         }
   // }