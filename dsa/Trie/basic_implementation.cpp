
#include<bits/stdc++.h>
using namespace std;

class node{
public:
char data;
unordered_map<char,node*> child;
bool terminal;
node(char d){
    data = d;
    terminal = false;
}
};

class Trie{
    node* root;
    int cnt;
    public:
    Trie(){
        root = new node('\0');
        cnt = 0;
    }

    void insert(string str){
        node* temp = root;
        for(int i = 0;i<str.length();i++){
            char ch = str[i];
            if(temp->child.count(ch)){
                temp = temp->child[ch];
            }else{
                node* n = new node(ch);
                temp->child[ch] = n;
                temp = n;
            }
        }
        temp->terminal = true;
    }

    bool find(string str){
        node* temp = root;
        for(int i = 0;i<str.length();i++){
            char ch  = str[i];
            if(temp->child.count(ch) == 0){
                return false;

            }else{
                temp = temp->child[ch];

            }
        }
        return temp->terminal;
    }
};

int main(){
     vector<string> v;
     int n;
     cin>>n;
     Trie t;
     for(int i = 0;i<n;i++){
        string str;
        cin>>str;
        v.push_back(str);
t.insert(str);
     }

     cout<<t.find("amit");
     cout<<t.find("sumit");
     cout<<t.find("Radha");
     cout<<t.find("Awadhesh");
     cout<<t.find("manish");


     
}

