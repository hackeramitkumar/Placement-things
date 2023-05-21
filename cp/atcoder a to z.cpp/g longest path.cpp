#include<bits/stdc++.h>
using namespace std;

unordered_map<int,vector<int> > mp;
vector<int> dp;
int dfs(int x){
    if(dp[x] != -1) return dp[x];
    int ans = 0;
    for(auto y : mp[x]){
        ans = max(ans,1+dfs(y));
    }
    return dp[x] = ans;
}
int main(){
    int n,m;
    cin>>n>>m;
    for(int i = 0;i<m;i++){
        int x,y;
        cin>>x>>y;
        mp[x].push_back(y);
    }
    dp.resize(n+1,-1);
    int ans = 0;
    for(int i = 1;i<= n;i++){
        ans = max(ans,dfs(i));
    }
cout<<ans<<endl;

}