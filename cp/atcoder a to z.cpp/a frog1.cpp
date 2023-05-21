#include <bits/stdc++.h>
using namespace std;

vector<int> dp;
int solve(vector<int> &v, int i, int K)
{
    if (i >= v.size() - 1)
        return 0;
    if (dp[i] != -1)
        return dp[i];
    int ans = INT_MAX;

    for (int j = 1; j <= K; j++)
    {
        if (i + j < v.size())
        {
            ans = min(ans, abs(v[i] - v[i + j]) + solve(v, j + i, K));
        }
    }
    return dp[i] = ans;
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    dp.resize(n + 1, -1);
    cout << solve(v, 0, k) << endl;
}