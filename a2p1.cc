
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int main(int argc, char *argv[])
{
    // fstream my_file;
    // my_file.open(argv[1], ios::out);
    // if (!my_file) {
    // 	cout << "File not created!";
    // }
    // else {
    // 	cout << "File created successfully!";
    // 	my_file << "Guru99";
    // 	my_file.close();
    // }
    bool side = true;

    fstream my_file;
    int n;
    cin >> n;
    if (n <= 0)
    {
        cerr << "Error, line length must be positive." << endl;
        exit(1);
    }

    // string line;
    string curword;
    cin.ignore();

    string path;
    cin >> path;
    my_file.open(path);
    if (my_file.fail()){
        cerr << "Error, cannot open specified text file." << endl;
    }
    string line;

    // while(my_file>>line){
    //     cout<<line<<endl;
    // }
    cin.ignore();

    vector<string> v{};
    string s;

    int wordcount = 0;
    int linecount = 0;
    bool condition = true;

    while (my_file >> line)
    {
        //   if(!((line == "rr" || line == "j" || line == "rl" || line=="c"||line=="f"||line=="p"||line=="r"||line=="p"||line=="k"||line=="s"||line=="q"))){
        //       break;
        //   }
        v.push_back(line);
    }

    // add strings to vector here
    // append tokens to string, then append the string to new vector
    int startIndex = 0;
    int endIndex = v.size();
    vector<string> newvector{};

    int spacesCount = 0;
    string first;
    string second;
    // cout<<v.size();
    for (int i = 0; i < v.size(); i++)
    {

        string a = v[i];
        // cout<<wordcount<<" "<<linecount<<a<<endl;
        for (auto j : a)
        {
            wordcount++;
        }

        if (i == v.size() - 1)
        {
            if (wordcount + linecount > n)
            {
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
        // cout<<wordcount<<endl;
        // cout<<spacesCount<<endl;
        if (wordcount > n)
        {
            if (linecount)
            {
                newvector.push_back(first);
                first = "";
            }
            for (int j = 0; j < n; j++)
            {
                char e = a[j];
                first.push_back(e);
            }
            newvector.push_back(first);
            first = "";
            linecount = 0;
            wordcount = 0;
            condition = true;
        }
        else if (wordcount + linecount > n)
        {
            newvector.push_back(first);
            first = "";
            first.append(a);
            linecount = wordcount + 1;
            wordcount = 0;
        }
        else
        {
            if (condition)
            {
                first.append(a);
                condition = false;
            }
            else
            {
                first.append(" ");
                first.append(a);
            }
            linecount = linecount + wordcount;
            wordcount = 0;
            linecount++;
        }
    }
    //cout << "newvector" << endl;
    //for (auto i : newvector)
    //{
    //    cout << i << endl;
    //    // cout<<endl;
    //}
    int secondSpacesCount = 0;
    vector<string> finalvector{};
    vector<string> rrvector{};
    vector<string> rlvector{};
    vector<string> cvector{};
    vector<string> jvector{};

    // rrvector = newvector;

    //out << "rrvector" << endl;
    for (auto i : newvector)
    {
        int spaces = n - i.length();
        for (int j = 0; j < spaces; j++)
        {
            i.append(" ");
        }
        rrvector.push_back(i);
    }

    //for (auto i : rrvector)
    //{
    //    cout << i << endl;
    //}

    for (auto i : newvector)
    {
        vector<int> spaces;
        // cout<<"hello";

        for (int j = 0; j < i.length(); j++)
        {
            if (i.at(j) == ' ')
            {
                secondSpacesCount++;
                spaces.push_back(j);
            }
            if (i.at(j) != ' ')
            {
                // cout<<i[j]<<"I";
                spacesCount++;
            }
        }
        // cout<<i<<"hi"<<endl<<secondSpacesCount<<endl;
        int temp = n - spacesCount;
        // cout<<"HI"<<endl;
        int check = n - i.length();
        int timesRepeated = 0;
        // cout<<i<<"hi"<<check<<secondSpacesCount<<endl;
        if (check && secondSpacesCount && (n - spacesCount - check))
        {
            timesRepeated = check / secondSpacesCount;
        }
        // cout<<"counts: "<<timesRepeated<<endl<<spacesCount<<endl<<secondSpacesCount<<endl<<n-spacesCount<<endl<<check<<i<<endl;

        for (int j = 0; j < timesRepeated; j++)
        {
            //   cout<<"HI1"<<i<<endl;

            for (int k = 0; k < secondSpacesCount; k++)
            {
                //      cout<<"HI2"<<endl;

                if (side)
                {
                    i.insert(0, " ");
                    side = false;
                }
                else
                {
                    i.insert(i.length(), " ");
                    side = true;
                }
                check--;
                //        cout<<"HI2"<<endl;
            }
            // cout<<i<<"no"<<check<<endl;
        }
        bool secondCondition = false;
        // cout<<i<<"hiagain"<<secondSpacesCount<<endl;
        if (check && secondSpacesCount && (n - spacesCount - check))
        {
            // cout<<"check"<<check<<endl;
            while (spacesCount > check)
            {
                spacesCount = spacesCount - check;
                // timesRepeated++;
                secondCondition = true;
            }
            // cout<<"check"<<check<<endl;
            for (int j = 0; j < check; j++)
            {
                if (side)
                {
                    i.insert(0, " ");
                    side = false;
                }
                else
                {
                    i.insert(i.length(), " ");
                    side = true;
                }
                // cout<<spaces[j]+1+timesRepeated+j<<endl<<i<<endl;
            }
        }
        else
        { // cout<<i<<"yes"<<check<<endl;

            for (int j = 0; j < check; j++)
            {
                if (side)
                {
                    i.insert(0, " ");
                    side = false;
                }
                else
                {
                    i.insert(i.length(), " ");
                    side = true;
                }
            }
        }

        // cout<<i<<"fake"<<endl;

        cvector.push_back(i);

        spacesCount = 0;
        temp = 0;
        check = 0;
        secondSpacesCount = 0;
        timesRepeated = 0;
        spaces.clear();
        side = true;
    }

    // cout<<"rlvector"<<endl;
    //
    // for(auto i:rlvector){
    //     cout<<i<<endl;
    // }
    //cout << "cvector" << endl;
    //for (auto i : cvector)
    //{
    //    cout << i << endl;
    //}
    // cout<<"jvector"<<endl;
    //
    // for(auto i:jvector){
    //     cout<<i<<endl;
    // }

    for (auto i : newvector)
    {
        vector<int> spaces;
        // cout<<"hello";

        for (int j = 0; j < i.length(); j++)
        {
            if (i.at(j) == ' ')
            {
                secondSpacesCount++;
                spaces.push_back(j);
            }
            if (i.at(j) != ' ')
            {
                // cout<<i[j]<<"I";
                spacesCount++;
            }
        }
        // cout<<i<<"hi"<<endl<<secondSpacesCount<<endl;
        int temp = n - spacesCount;
        // cout<<"HI"<<endl;
        int check = n - i.length();
        int timesRepeated = 0;
        // cout<<i<<"hi"<<check<<secondSpacesCount<<endl;
        if (check && secondSpacesCount && (n - spacesCount - check))
        {
            timesRepeated = check / secondSpacesCount;
        }
        // cout<<"counts: "<<timesRepeated<<endl<<spacesCount<<endl<<secondSpacesCount<<endl<<n-spacesCount<<endl<<check<<i<<endl;

        for (int j = 0; j < timesRepeated; j++)
        {
            //   cout<<"HI1"<<i<<endl;

            for (int k = 0; k < secondSpacesCount; k++)
            {
                //      cout<<"HI2"<<endl;

                i.insert(spaces[k] + 1 + j + k, " ");
                check--;
                //        cout<<"HI2"<<endl;
            }
            // cout<<i<<"no"<<check<<endl;
        }
        bool secondCondition = false;
        // cout<<i<<"hiagain"<<secondSpacesCount<<endl;
        if (check && secondSpacesCount && (n - spacesCount - check))
        {
            // cout<<"check"<<check<<endl;
            while (spacesCount > check)
            {
                spacesCount = spacesCount - check;
                // timesRepeated++;
                secondCondition = true;
            }
            // cout<<"check"<<check<<endl;
            for (int j = 0; j < check; j++)
            {
                i.insert(spaces[j] + 1 + timesRepeated + j, " ");
                // cout<<spaces[j]+1+timesRepeated+j<<endl<<i<<endl;
            }
        }
        else
        { // cout<<i<<"yes"<<check<<endl;

            for (int j = 0; j < check; j++)
            {
                i.append(" ");
            }
        }

        jvector.push_back(i);

        spacesCount = 0;
        temp = 0;
        check = 0;
        secondSpacesCount = 0;
        timesRepeated = 0;
        spaces.clear();
    }

    //cout << "jvector" << endl;
    //for (auto i : jvector)
    //{
    //    cout << i << endl;
    //}

    for (auto i : newvector)
    {
        vector<int> spaces;
        // cout<<"hello";

        for (int j = 0; j < i.length(); j++)
        {
            if (i.at(j) == ' ')
            {
                secondSpacesCount++;
                spaces.push_back(j);
            }
            if (i.at(j) != ' ')
            {
                // cout<<i[j]<<"I";
                spacesCount++;
            }
        }
        // cout<<i<<"hi"<<endl<<secondSpacesCount<<endl;
        int temp = n - spacesCount;
        // cout<<"HI"<<endl;
        int check = n - i.length();
        int timesRepeated = 0;
        // cout<<i<<"hi"<<check<<secondSpacesCount<<endl;
        if (check && secondSpacesCount && (n - spacesCount - check))
        {
            timesRepeated = check / secondSpacesCount;
        }
        // cout<<"counts: "<<timesRepeated<<endl<<spacesCount<<endl<<secondSpacesCount<<endl<<n-spacesCount<<endl<<check<<i<<endl;

        for (int j = 0; j < timesRepeated; j++)
        {
            //   cout<<"HI1"<<i<<endl;

            for (int k = 0; k < secondSpacesCount; k++)
            {
                //      cout<<"HI2"<<endl;

                i.insert(0, " ");
                check--;
                //        cout<<"HI2"<<endl;
            }
            // cout<<i<<"no"<<check<<endl;
        }
        bool secondCondition = false;
        // cout<<i<<"hiagain"<<secondSpacesCount<<endl;
        if (check && secondSpacesCount && (n - spacesCount - check))
        {
            // cout<<"check"<<check<<endl;
            while (spacesCount > check)
            {
                spacesCount = spacesCount - check;
                // timesRepeated++;
                secondCondition = true;
            }
            // cout<<"check"<<check<<endl;
            for (int j = 0; j < check; j++)
            {
                i.insert(0, " ");
                // cout<<spaces[j]+1+timesRepeated+j<<endl<<i<<endl;
            }
        }

        rlvector.push_back(i);

        spacesCount = 0;
        temp = 0;
        check = 0;
        secondSpacesCount = 0;
        timesRepeated = 0;
        spaces.clear();
    }

    //cout << "rlvector" << endl;
    //for (auto i : rlvector)
    //{
    //    cout << i << endl;
    //}

    int firstIndex = 0;
    vector<string> lastvector = rrvector;
    // false == forward, true == reverse CHANGE INDICES HERE    
    int lastIndex = lastvector.size() - 1;
    //for(auto i:lastvector){
    //    cout<<i<<endl;
    //}

    while (cin >> line)
    {
        // cout << line << endl;
        if (line == "f")
        {
            firstIndex = 0;
            lastIndex = lastvector.size() - 1;
        }
        else if (line == "r")
        {
            firstIndex = lastvector.size() - 1;
            lastIndex = 0;
        }
        else if (line == "rr")
        {
            lastvector = rrvector;
        }
        else if (line == "rl")
        {
            lastvector = rlvector;
        }
        else if (line == "j")
        {
            lastvector = jvector;

        } 
        else if (line == "c")
        {
            lastvector = cvector;
        }
        else if(line == "p"){
            if(lastIndex){
                for(int j = firstIndex; j <= lastIndex; j++){
                    cout<<lastvector[j]<<endl;
                }
            }
            else{
                for(int j = firstIndex; j >= lastIndex; j--){
                    cout<<lastvector[j]<<endl;
                }                
            }
        }        
        else if(line == "s"){                
            string input;
            cin>>input;
            for(auto i: lastvector){
                if(i.find(input) != std::string::npos){
                    cout<<i<<endl;
                }
        }
        }        
        else if(line == "k"){
            cin.ignore();
            int a;
            cin>>a;
            if(a < lastvector.size()){
                cout<<lastvector[a]<<endl;
            }
        }
        else if(line == "q"){
            break;
        }
        else{
            cerr<< "Error, command is illegal."<<endl;
            break;
        }
    }
    my_file.close();
    return 0;
}
