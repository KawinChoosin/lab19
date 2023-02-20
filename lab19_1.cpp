#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<cstdlib>
#include<cstring>
using namespace std;

char score2grade(int score){
    if(score >= 80) return 'A';
    if(score >= 70) return 'B';
    if(score >= 60) return 'C';
    if(score >= 50) return 'D';
    else return 'F';
}

string toUpperStr(string x){
    string y = x;
    for(unsigned i = 0; i < x.size();i++) y[i] = toupper(x[i]);
    return y;
}

void importDataFromFile(string f,vector<string> &n, vector<int> &s,vector<char> &g){
    string textline;
    char format[] = "%[^:]: %d %d %d";
    ifstream source;
    source.open (f);
    int a,b,c;
    char name[100];
    while(getline(source,textline)){
        sscanf(textline.c_str(),format,name,&a,&b,&c);
        n.push_back(name);
        s.push_back(a+b+c);
        g.push_back(score2grade(a+b+c));
        }
}

void getCommand(string &command,string &key){
        string t;
        cout<<"Please input your command: ";
        getline(cin,t);
        int start =0;
        int end=t.find_first_of(" ");
        command=t.substr(start,end-start);
        start=end+1;
        key=t.substr(start,t.find_last_of(" ",start)-start);
}

void searchName(vector<string> n, vector<int> s,vector<char> g,string key){
            int count=0;
            cout << "---------------------------------\n";
            for(unsigned int i=0;i<n.size();i++){
                if(toUpperStr(n[i])==key){
                cout<<n[i]<<"'s score = "<<s[i]<<endl;
                cout<<n[i]<<"'s grade = "<<g[i]<<endl;
                count++;
                }
            }
            if(count==0){
                    cout<<"Cannot found."<<endl;
                }

            cout << "---------------------------------\n";
}

void searchGrade(vector<string> n, vector<int> s,vector<char> g,string key){
            int count=0;
            cout << "---------------------------------\n";
            for(unsigned int i=0;i<n.size();i++){
                if(g[i] == *key.c_str()){
                     cout<<n[i]<<" ("<<s[i]<<") \n";
                     count ++;
                }
            }
            if(count==0){
                    cout<<"Cannot found.";
                }
            cout << "---------------------------------\n";
}


int main(){
    string filename = "name_score.txt";
    vector<string> names;
    vector<int> scores;
    vector<char> grades; 
    importDataFromFile(filename, names, scores, grades);
    
    do{
        string command, key;
        getCommand(command,key);
        command = toUpperStr(command);
        key = toUpperStr(key);
        if(command == "EXIT") break;
        else if(command == "GRADE") searchGrade(names, scores, grades, key);
        else if(command == "NAME") searchName(names, scores, grades, key);
        else{
            cout << "---------------------------------\n";
            cout << "Invalid command.\n";
            cout << "---------------------------------\n";
        }
    }while(true);
    
    return 0;
}