#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
vector<vector<int>> dp;
int dfs(vector<vector<char>> &g, int i, int j, int m, int n)
{
    if (i < 0 || j < 0 || i >= m || j >= n || g[i][j] == '#')
        return 0;
    if (i == m - 1 and j == n - 1)
        return 1;
    if (dp[i][j] != -1)
        return dp[i][j];
    dp[i][j] = ((dfs(g, i + 1, j, m, n) % mod ) + (dfs(g, i, j + 1, m, n) % mod )) % mod;
    return dp[i][j] % mod;
}

int main()
{
    int m, n;
    cin >> m >> n;
    vector<vector<char>> g(m, vector<char>(n));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> g[i][j];
        }
    }

    dp.resize(m, vector<int>(n, -1));
    cout << dfs(g, 0, 0, m, n) << endl;
}