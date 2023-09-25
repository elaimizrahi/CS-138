#include <iostream>
#include <cctype>
using namespace std;

string lcLetters(string s){
    string result = "";
    if(s.length() > 0){
        const char c = s.at(0);
        if(isalpha(c)){
            result = tolower(c);
        }
        result += lcLetters(s.substr(0));
    }
    return result;
}


int main() {
    string a = lcLetters("flurble, Eh!");
    cout<<a<<endl;

}
