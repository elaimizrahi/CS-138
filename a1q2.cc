/*
* CS138, W23, Assignment 1, Problem 2
* Main Function
*
* main function is a special function,
* which serves as the entry point for the program.
* 
* Try to keep it as simple as possible
* and implement the logic of your program
* in a1q2.cpp, so that you can write unit tests
* for them and make sure of their expected behavior.
*/
#include <iostream>
#include <vector>
using namespace std;
// no argc+argv because we aren't using them in A1
int main() {
    int i;
    cin >> i;
    if(i < 0){
        cerr << "Error, line length must be positive."<<endl;
        return 0;
    }
    cin.ignore();       
    string s;
    char g;
    cin>>g;    
    vector<string> v{};
    if(g=='f'){
        while(getline(cin, s)){
            for(int j = 0; j < i; j++){ 
                if(s[j]){
                    cout << s[j];
                }
                else{break;}            

            }if(s != "")cout<<endl;
        }
    }    
    else if(g=='r'){
        while(getline(cin, s)){
            v.push_back(s);
        }
       for(int k = 0; k < v.size()+k; k++){
           string l = v.back();
            for(int j = 0; j < i; j++){
                if(l[j]){
                    cout<<l[j];
                }
                else{break;}
            }           
            if(k+1 == v.size()+k){ 
                break;
            }
            cout<<endl;
           v.pop_back();
       }
    }
    else if(g=='g'){
        while(getline(cin, s)){
            if(s.find("fnord") != std::string::npos){
                for(int j = 0; j < i; j++){
                    if(s[j]){
                        cout<<s[j];
                    }
                }
                cout<<endl;
            }
        }
    }
    else{
        cerr<<"Error, command is illegal."<<endl;
    }
    cin.clear();
    // TODO: Solve the problem!
    return 0;
}
