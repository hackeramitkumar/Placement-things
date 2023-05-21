#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll> dp;
ll solve(vector<ll> &v,ll i,ll c){
 if(i >= v.size()){
  return 0; 
 }
  if(dp[i] != -1 ) return dp[i];
  ll ans = 1e18;
  for(int j = i+1;j<v.size();j++){
   ll val =  (v[i] - v[j])*(v[i] - v[j]) + c + solve(v,j,c); 
//    cout<<val<<"--->"<<ans<<endl;
    if(val < ans)  ans = val;
  }

  return dp[i] = (ans==1e18 ? 0:ans);
  
}

int main(){
 ll n,c;
  cin>>n>>c;
  vector<ll> v(n);
  for(int i = 0;i<n;i++){
   cin>>v[i]; 
  }
  dp.resize(n+1,-1);
  cout<<solve(v,0,c)<<endl;
  
}