#include<bits/stdc++.h>
using namespace std;
#define ll long long 

vector<vector<ll> > dp;
int solve(vector<vector<ll> > &v,ll i,ll prev){
 if(i == v.size()) return 0;
 if(dp[i][prev] != -1) return dp[i][prev];
  
  int val1 = -1,val2=-1,val3 = -1;
  if(prev == 0){
    val1 = max(v[i][1]+solve(v,i+1,1) ,v[i][2]+solve(v,i+1,2) );
  }
    if(prev == 1){
    val1 = max(v[i][0]+solve(v,i+1,0) ,v[i][2]+solve(v,i+1,2) );
  }
    if(prev == 2){
    val1 = max(v[i][1]+solve(v,i+1,1) ,v[i][0]+solve(v,i+1,0) );
  }
 return dp[i][prev] = max({val1,val2,val3});
}

int main(){
 ll n;
 cin>>n;
 vector<vector<ll> > v;
 for(int i = 0;i<n;i++){
 ll a,b,c;
 cin>>a>>b>>c;
 v.push_back({a,b,c});
 }
  
  dp.resize(n+1,vector<ll>(3,-1));
  cout<<max({solve(v,0,0),solve(v,0,1),solve(v,0,2)});
  
}