#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1e9 + 7

void amitrix()
{
    ll n, q;
    cin >> n >> q;
    vector<ll> v(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    vector<ll> pref(n + 1);
    pref[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        pref[i] = pref[i - 1] + v[i - 1];
    }

    // for(int i = 0;i<n;i++) cout<<v[i]<<" ";
    // cout<<endl;

    // for(int i = 0;i<=n;i++) cout<<pref[i]<<" ";
    // cout<<endl;
    for (int i = 0; i < q; i++)
    {
        ll l, r, k;
        cin >> l >> r >> k;
        ll final_ans = pref[n] - (pref[r] - pref[l - 1]) + (r-l + 1) * k;
        // cout<<(l - r + 1) * k <<endl;
        // cout<<l<<" "<<r<<" "<<k<<"-->"<<final_ans<<endl;
        if (final_ans % 2 == 1)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        amitrix();
    }
    return 0;
}