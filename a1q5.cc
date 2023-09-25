/*
* CS138, W23, Assignment 1, Problem 5
* Main Function
*
* main function is a special function,
* which serves as the entry point for the program.
* 
* Try to keep it as simple as possible
* and implement the logic of your program
* in a1q5.cpp, so that you can write unit tests
* for them and make sure of their expected behavior.
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// no argc+argv because we aren't using them in A1


void rightLeft(){

}

void raggedLeft(){

}

void center(){

}

void raggedRight(){

}


int main() {
    int n;

    string c1;
    string c2;

    vector<string> v{};
    vector<string> newvector{};
    string s;
    cin>>n;
    if(n <= 0){
        cerr << "Error, line length must be positive."<<endl;
        exit(1);
    }
    cin.ignore();

    cin>>c1;
    cin.ignore();
    cin>>c2;
    cin.ignore();
    if(!((c1 == "rr" || c1 == "j" || c1 == "rl" || c1=="c")&&(c2=="f"||c2=="g"||c2=="r"))){
        cerr<<"Error, command is illegal."<<endl;
    }

    string line;
    string curword;

    int wordcount = 0;
    int linecount = 0;

    bool condition = true;
    bool condition3 = true;

    while(cin>>line){
        v.push_back(line);
    }

    //add strings to vector here
    //append tokens to string, then append the string to new vector
    int startIndex = 0;
    int endIndex = v.size();

    int spacesCount = 0;
    string first;
    string second;
    //bool condition3 = false;
//cout<<v.size();
    for(int i = 0; i < v.size(); i++){

        string a = v[i];
        //cout<<wordcount<<" "<<linecount<<a<<endl;
        for(auto j:a){
            wordcount++;
        }

        if(i == v.size()-1){
            if(wordcount+linecount > n){
                newvector.push_back(first);
                first.clear();
                first.append(v[i]);
                newvector.push_back(first);
                break;
            }
            first.append(" ");
            first.append(a);
            newvector.push_back(first);
            break;
        }
        //cout<<wordcount<<endl;
        //cout<<spacesCount<<endl;
        if(wordcount > n){
            if(linecount){
                newvector.push_back(first);
                first = "";
            }
            for(int j = 0; j < n; j++){
                char e = a[j];
                first.push_back(e);
            }
            newvector.push_back(first);
            //cout<<first<<"first"<<i<<endl;
            first = "";
            linecount = 0;
            wordcount = 0;
            condition = true;
            a = "";
           //cout<<"A"<<a<<endl;
        }
        else if(wordcount + linecount>n){
            newvector.push_back(first);
            first = "";
            first.append(a);
            linecount = wordcount + 1;
            wordcount = 0;
        }
        else{
            if(condition){
                //cout<<"hi"<<i<<"a"<<a;
                first.append(a);
                condition = false; 
            }
            else{
                //cout<<"AAA"<<a<<endl;
                if(condition3)first.append(" ");
                first.append(a);
            }        
            linecount = linecount+ wordcount;
            wordcount = 0;
            linecount++;
}
//first.clear();

    }  
   //for(auto i:newvector){
   //    cout<<i<<endl;
   //    //cout<<endl;
   //}



   ////

   vector<string> finalvector{};

   if(c1 == "rr"){
    for(auto i:newvector){
        int spaces = n-i.length();
        for(int j = 0; j < spaces; j++){
            i.append(" ");
        }
        finalvector.push_back(i);
    }
   }
    int secondSpacesCount = 0;

   if(c1 == "j"){

    for(auto i:newvector){
        vector<int> spaces;
        //cout<<"hello";

        for(int j = 0; j < i.length(); j++){

            if(!i.at(j)){
                break;
            }

            if(i.at(j) == ' '){
                secondSpacesCount++;
                spaces.push_back(j);

            }
            if(i.at(j) != ' '){
                //cout<<i[j]<<"I";
                spacesCount++;
            }
        }     
       //cout<<i<<"hi"<<endl<<secondSpacesCount<<endl;
        int temp = n-spacesCount;
       // cout<<"HI"<<endl;
        int check = n-i.length();
        int timesRepeated = 0;
//cout<<i<<"hi"<<check<<secondSpacesCount<<endl;
        if(check&&secondSpacesCount&&(n-spacesCount-check)){timesRepeated =  check/ secondSpacesCount;}
      //cout<<"counts: "<<timesRepeated<<endl<<spacesCount<<endl<<secondSpacesCount<<endl<<n-spacesCount<<endl<<check<<i<<endl;

        for(int j = 0; j < timesRepeated; j++){
                 //   cout<<"HI1"<<i<<endl;

            for(int k = 0; k < secondSpacesCount; k++){
                  //      cout<<"HI2"<<endl;

                i.insert(spaces[k] + 1 + j + k," ");
                check--;
                                //        cout<<"HI2"<<endl;

            }
            //cout<<i<<"no"<<check<<endl;
        }   
        bool secondCondition = false;
        //cout<<i<<"hiagain"<<secondSpacesCount<<endl;
        if(check&&secondSpacesCount&&(n-spacesCount-check)){
            //cout<<"check"<<check<<endl;
            while(spacesCount > check){
                spacesCount = spacesCount-check;
                //timesRepeated++;
                secondCondition = true;
            }
           // cout<<"check"<<check<<endl;
            for(int j = 0; j < check; j++){
                if(j >= spaces.size()){
                    check = check -j;                    
                    j = 0;
                }
                i.insert(spaces[j]+1+timesRepeated+j, " ");
                //cout<<spaces[j]+1+timesRepeated+j<<endl<<i<<endl;
            }
        }
        else{        //cout<<i<<"yes"<<check<<endl;

            for(int j = 0; j < check;j++){
                i.append(" ");
            }
        }

       finalvector.push_back(i);

        spacesCount = 0;
        temp=0;
        check=0;
        secondSpacesCount=0;
        timesRepeated = 0;
        spaces.clear();
    } } // TODO: Solve the problem!  //cout<<endl;
    

    if(c1 == "rl"){

    for(auto i:newvector){
        vector<int> spaces;
        //cout<<"hello";

        for(int j = 0; j < i.length(); j++){

            if(!i.at(j)){
                break;
            }

            if(i.at(j) == ' '){
                secondSpacesCount++;
                spaces.push_back(j);

            }
            if(i.at(j) != ' '){
                //cout<<i[j]<<"I";
                spacesCount++;
            }
        }     
       //cout<<i<<"hi"<<endl<<secondSpacesCount<<endl;
        int temp = n-spacesCount;
       // cout<<"HI"<<endl;
        int check = n-i.length();
        int timesRepeated = 0;
//cout<<i<<"hi"<<check<<secondSpacesCount<<endl;
        if(check&&secondSpacesCount&&(n-spacesCount-check)){timesRepeated =  check/ secondSpacesCount;}
      //cout<<"counts: "<<timesRepeated<<endl<<spacesCount<<endl<<secondSpacesCount<<endl<<n-spacesCount<<endl<<check<<i<<endl;

        for(int j = 0; j < timesRepeated; j++){
                 //   cout<<"HI1"<<i<<endl;

            for(int k = 0; k < secondSpacesCount; k++){
                  //      cout<<"HI2"<<endl;

                i.insert(0," ");
                check--;
                                //        cout<<"HI2"<<endl;

            }
            //cout<<i<<"no"<<check<<endl;
        }   
        bool secondCondition = false;
        //cout<<i<<"hiagain"<<secondSpacesCount<<endl;
        if(check&&secondSpacesCount&&(n-spacesCount-check)){
            //cout<<"check"<<check<<endl;
            while(spacesCount > check){
                spacesCount = spacesCount-check;
                //timesRepeated++;
                secondCondition = true;
            }
           // cout<<"check"<<check<<endl;
            for(int j = 0; j < check; j++){
                if(j >= spaces.size()){
                    check = check -j;                    
                    j = 0;
                }
                i.insert(0, " ");
                //cout<<spaces[j]+1+timesRepeated+j<<endl<<i<<endl;
            }
        }
        else{        //cout<<i<<"yes"<<check<<endl;

            for(int j = 0; j < check;j++){
                i.append(" ");
            }
        }

       finalvector.push_back(i);

        spacesCount = 0;
        temp=0;
        check=0;
        secondSpacesCount=0;
        timesRepeated = 0;
        spaces.clear();
    }
    }

    bool side  = true;

    if(c1=="c"){
        
    for(auto i:newvector){
        vector<int> spaces;
        //cout<<"hello";

        for(int j = 0; j < i.length(); j++){

            if(!i.at(j)){
                break;
            }

            if(i.at(j) == ' '){
                secondSpacesCount++;
                spaces.push_back(j);

            }
            if(i.at(j) != ' '){
                //cout<<i[j]<<"I";
                spacesCount++;
            }
        }     
       //cout<<i<<"hi"<<endl<<secondSpacesCount<<endl;
        int temp = n-spacesCount;
       // cout<<"HI"<<endl;
        int check = n-i.length();
        int timesRepeated = 0;
//cout<<i<<"hi"<<check<<secondSpacesCount<<endl;
        if(check&&secondSpacesCount&&(n-spacesCount-check)){timesRepeated =  check/ secondSpacesCount;}
      //cout<<"counts: "<<timesRepeated<<endl<<spacesCount<<endl<<secondSpacesCount<<endl<<n-spacesCount<<endl<<check<<i<<endl;

        for(int j = 0; j < timesRepeated; j++){
                 //   cout<<"HI1"<<i<<endl;

            for(int k = 0; k < secondSpacesCount; k++){
                  //      cout<<"HI2"<<endl;

                if(side){
                    i.insert(0, " ");
                    side = false;
                }
                else{
                    i.insert(i.length()," ");
                    side = true;
                }
                check--;
                                //        cout<<"HI2"<<endl;

            }
            //cout<<i<<"no"<<check<<endl;
        }   
        bool secondCondition = false;
        //cout<<i<<"hiagain"<<secondSpacesCount<<endl;
        if(check&&secondSpacesCount&&(n-spacesCount-check)){
            //cout<<"check"<<check<<endl;
            while(spacesCount > check){
                spacesCount = spacesCount-check;
                //timesRepeated++;
                secondCondition = true;
            }
           // cout<<"check"<<check<<endl;
            for(int j = 0; j < check; j++){
                if(j >= spaces.size()){
                    check = check -j;                    
                    j = 0;
                }
                if(side){
                    i.insert(0, " ");
                    side = false;
                }
                else{
                    i.insert(i.length()," ");
                    side = true;
                }
                //cout<<spaces[j]+1+timesRepeated+j<<endl<<i<<endl;
            }
        }
        else{        //cout<<i<<"yes"<<check<<endl;

            for(int j = 0; j < check;j++){
                if(side){
                    i.insert(0, " ");
                    side = false;
                }
                else{
                    i.insert(i.length()," ");
                    side = true;
                }
            }
        }

        //cout<<i<<"fake"<<endl;

       finalvector.push_back(i);

        spacesCount = 0;
        temp=0;
        check=0;
        secondSpacesCount=0;
        timesRepeated = 0;
        spaces.clear();
        side = true;
    }
    }













    if(c2 == "f"){
        for(auto i:finalvector){
            cout<<i<<endl;
        }
    }   
    if(c2 == "r"){
        for(int i = finalvector.size()-1; i>=0; i--){
            cout<<finalvector[i]<<endl;
        }
    }    
    if(c2 == "g"){
        for(auto i: finalvector){
            string s = i;
            if(s.find("fnord") != std::string::npos){
                cout<<i<<endl;
            }
        }
    }
    return 0;
}
