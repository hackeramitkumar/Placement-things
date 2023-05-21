#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;
vector<vector<int>> choice;

int lcs(string &s1, string &s2, int i, int j)
{
    if (i == s1.length() || j == s2.length())
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    if (s1[i] == s2[j])
    {
        dp[i][j] = 1 + lcs(s1, s2, i + 1, j + 1);
    }
    else
    {
        dp[i][j] = max(lcs(s1, s2, i + 1, j), lcs(s1, s2, i, j + 1));
    }
    return dp[i][j];
}

string lcs(string &s1, string &s2)
{
    dp.resize(3000, vector<int>(3000, 0));
    choice.resize(3000, vector<int>(3000, 0));
int n = s1.length(),m = s2.length();
    dp[0][0] = 0;
    if (s1[0] == s2[0])
    {
        dp[0][0] = 1;
        choice[0][0] = 2;
    }

    for (int i = 0; i <n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i > 0)
            {
                dp[i][j] = dp[i - 1][j];
                choice[i][j] = 0;
            }

            if (j > 0)
            {
                if (dp[i][j - 1] > dp[i][j])
                {
                    dp[i][j] = dp[i][j - 1];
                    choice[i][j] = 1;
                }
            }

            if (s1[i] == s2[j])
            {
                int ans = 1;
                if (i > 0 and j > 0)
                {
                    ans = 1 + dp[i - 1][j - 1];
                }
                if (ans > dp[i][j])
                {
                    dp[i][j] = ans;
                    choice[i][j] = 2;
                }
            }
        }
    }
    // return dp[s1.length()-1][s2.length()-1];
    string str;
    int i = s1.length() - 1, j = s2.length() - 1;
    while (i >= 0 and j >= 0)
    {
        if (choice[i][j] == 0)
        {
            i--;
        }
        else if (choice[i][j] == 1)
        {
            j--;
        }
        else
        {
            str.push_back(s1[i]);
            j--;
            i--;
        }
    }
    reverse(str.begin(),str.end());
    return str;
}

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    // dp.resize(s1.length(),vector<int>(s2.length(),-1));
    // cout<<lcs(s1,s2,0,0)<<endl;
    cout << lcs(s1, s2);
}