#include<bits/stdc++.h>
using namespace std;

//  dp -> (idx , head)
double dp[3000][3000];
double p[3000];

int main(){
    int n;
    cin>>n;
    for(int i = 0;i<n;i++){
        cin>>p[i];
    }
    
dp[0][0] = (1-p[0]);
dp[0][1] = p[0];
    for(int i = 1;i<n;i++){
    for(int j = 0;j<3000;j++){
        // tails
        dp[i][j] += (1-p[i])*(dp[i-1][j]);
        // head 
        if(j > 0)
        dp[i][j] += p[i]*(dp[i-1][j-1]);
    }
    }

    double ans = 0;
    for(int i = n/2+1;i<3000;i++){
        ans += dp[n-1][i];
    }
    
    cout<<setprecision(9);
    cout<<ans<<endl;
}
