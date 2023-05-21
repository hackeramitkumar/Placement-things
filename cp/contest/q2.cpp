#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1e9 + 7

void amitrix()
{
    int n;
    cin>>n;
    vector<int> v(n,0);
    for(int i = 0;i<n;i++){
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    ll val1 = (ll)v[0]*v[1];
    ll val2 = (ll)v[n-1]*v[n-2];
    cout<<max(val1,val2)<<endl;
    
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