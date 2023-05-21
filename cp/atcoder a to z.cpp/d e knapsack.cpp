#include<bits/stdc++.h>
using namespace std;
#define ll long long 

unordered_map<string,ll> dp;
ll max(ll a,ll b){
    if( a > b) return a;
    return b;
}

// dp states are index , weight
ll solve(vector<vector<ll> > &v,ll i,ll curr,ll w){
 if(i == v.size() || curr == w) return 0;
 
 string key = to_string(i)+'*'+to_string(curr);
 if(dp.find(key) != dp.end()) return dp[key];
  
  if(curr+v[i][0] <= w){
    dp[key] = max(v[i][1]+solve(v,i+1,curr+v[i][0],w) , solve(v,i+1,curr,w) );
  }else{
    dp[key] = solve(v,i+1,curr,w);
  }
  return dp[key];
}

ll solve_(vector<vector<ll> > &v,ll w){
     vector<vector<ll> > dpi(v.size()+1,vector<ll>(w+1,0));
dpi[0][0] = 0;
dpi[0][v[0][0]] = v[0][1];
     for(int i = 1;i<v.size();i++){
        dpi[i][0] = 0;
        for(int j = 1;j <= w;j++){
        dpi[i][j] = dpi[i-1][j];
            if( j >= v[i][0] )
            dpi[i][j] = max(dpi[i][j] , v[i][1]+dpi[i-1][j - v[i][0]]);
        }
     }
     return dpi[v.size()-1][w];
}

const long long inf = 1e18;
ll knapsack_2(vector<vector<ll> > &v,ll w){
    int n = v.size();
     vector<vector<ll> > dpi(n+1,vector<ll>(100001,inf));
     dpi[0][0] = 0;
     dpi[0][v[0][1]] = v[0][0];
     for(int i = 1;i<n;i++){
        dpi[i][0] = 0;
        for(int j = 1;j <= 100000;j++){
        dpi[i][j] = dpi[i-1][j];
            if( j >= v[i][1] )
            dpi[i][j] = min(dpi[i][j] , v[i][0]+dpi[i-1][j - v[i][1]]);
        }
     }

     ll ans = 1e18;
     for(int i = 100000;i>=0;i--){
        if(dpi[n-1][i] <= w){
            ans = i;
            break;
        }
     }
     return ans;

     
}


int main(){
 ll n,w;
 cin>>n>>w;
 vector<vector<ll> > v;
 for(ll i = 0;i<n;i++){
 ll a,b;
 cin>>a>>b;
 v.push_back({a,b});
 }

  cout<<knapsack_2(v,w)<<endl;
  
}