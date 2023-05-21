#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1e9 + 9;

int main()
{
           string s;
    ll k;
    string patt;
    cin >> s >> patt >> k;
    unordered_map<char, int> mp;
    int n = s.size();

    for (int i = 0; i < 26; i++)
    {
        mp[i + 'a'] = 1-(patt[i]-'0');
    }

    vector<ll> pre(n + 1, 0);
    pre[0] = 0;
    for (int i = 0; i < n; i++)
    {
        pre[i+1] = pre[i] + mp[s[i]];
    }

    const int p = 31;
    const int m = 1e9 + 9;
    vector<long long> p_pow(n);
    p_pow[0] = 1;
    for (int i = 1; i < n; i++)
        p_pow[i] = (p_pow[i - 1] * p) % m;

    vector<long long> h(n + 1, 0);
    for (int i = 0; i < n; i++)
        h[i + 1] = (h[i] + (s[i] - 'a' + 1) * p_pow[i]) % m;

    int cnt = 0;
    // for(auto x  : pre) cout<<x<<" ";
    // cout<<endl;
    for (int l = 1; l <= n; l++)
    {
        set<long long> hs;
        for (int i = 0; i <= n - l; i++)
        {
            if (pre[i + l] - pre[i] <= k) {
                // cout<<i<<"---"<<i+l<<endl;
            long long cur_h = (h[i + l] + m - h[i]) % m;
            cur_h = (cur_h * p_pow[n - i - 1]) % m;
            hs.insert(cur_h);
            }
        }
        cnt += hs.size();
    }
    cout<<cnt;
}


