#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1e9 + 7

void amitrix()
{
    ll n;
    cin>>n;
string str;
cin>>str;
    set<char> even;
    set<char> odd;
    for(int i = 0;i<n;i++){
        if(i%2 == 0){
          char ch = str[i];
          if(odd.count(ch) > 0){
            cout<<"NO"<<endl;
            return;
          }
          even.insert(ch);
        }else{
            char ch = str[i];
            if(even.count(ch) > 0){
                cout<<"NO"<<endl;
                return;
            }
            odd.insert(ch);
        }
    }
    cout<<"YES"<<endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        amitrix();
    }
    return 0;
}