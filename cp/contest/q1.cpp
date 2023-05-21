#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1e9 + 7

void amitrix()
{
    int n,T;
    cin>>n>>T;
    vector<int> t(n,0);
    vector<int> v(n,0);
    for(int i = 0;i<n;i++){
        cin>>t[i];
    }
int max_idx = -2;
int max_val = 0;
    for(int i = 0;i<n;i++){
        cin>>v[i];
        if(t[i]+i <= T){
            if(v[i] > max_val){
                max_val = v[i];
                max_idx = i;
            }
        }
    }

    cout<<max_idx+1<<endl;

    
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