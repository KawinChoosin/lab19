#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<cstdlib>

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

void importDataFromFile(string f,vector<string> n, vector<int> s,vector<char> g){
    char format[]=" %s %d %s";
    string textline;
    ifstream source;
    source.open (f);
    for(int i=0;getline(source,textline);i++){
        sscanf(textline,format,n,&s,g)
        n[i]=n;
        s[i]=s;
        g[i]=g;
    }
}

void getCommand(string command,string key){
    cout<<"Please input your command: ";
    cin>>command>>key;
}

void searchName(vector<string> n, vector<int> s,vector<char> g,string key){
     cout << "---------------------------------\n";
    for(int i=0;toUpperStr(n[i])==key;i++){
        cout<<n[i]<<" 's score = "<<s[i];
        cout<<n[i]<<" 's grade = "<<g[i];
    }
     cout << "---------------------------------\n";
}

void searchGrade(vector<string> n, vector<int> s,vector<char> g,string key){
     cout << "---------------------------------\n";
    for(int i=0;toUpperStr(g[i])==key;i++){
        cout<<n[i]<<" ("<<i<<") \n";
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
