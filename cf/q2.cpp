#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1e9 + 7

void amitrix()
{
    ll n;
    cin>>n;
    vector<ll> v;
    ll ev = 0;
    ll odd = 0;
    for(int i = 0;i<n;i++){
        int x;
        cin>>x;
        if(x%2 == 1){
            odd += x;
        }else{
            ev += x;
        }
    }
    if(ev > odd) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    
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