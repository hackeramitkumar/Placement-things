#include<bits/stdc++.h>
using namespace std;

int dp[100005];
int main(){
 int n,k;
  cin>>n>>k;
  vector<int> v(n);
  for(int i = 0;i<n;i++) cin>>v[i];
  
  dp[0] = 0;
  for(int i = 1;i<=k;i++){
   dp[i] = 0; 
    for(auto x : v){
     if(i >= x and dp[i-x] == 0){
      dp[i] = 1;
       break;
     }
      
    }
    
  }
  if(dp[k] == 0) cout<<"Second"<<endl;
  else cout<<"First"<<endl;
  
  
  
  
}