#include<bits/stdc++.h>
using namespace std;

vector<vector<long long>> dp;
// dp[idx][idx] = val

int solve(vector<int> &v,int i, int j){
    if(i > j) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    return dp[i][j] = abs(v[i]+min(solve(v,i+2,j),solve(v,i+1,j-1)) - v[j]-min(solve(v,i+1,j-1),solve(v,i,j-2)));
}

int main(){
int n;
cin>>n;
vector<int> v(n);
dp.resize(n+1,vector<long long>(n+1,-1));

for(int i = 0;i<n;i++){
    cin>>v[i];
}

cout<<solve(v,0,n-1)<<endl;


}