#include <bits/stdc++.h>
using namespace std;
#define ll long long

class SegmentTree
{
    int size;
    vector<pair<ll,ll>> minimums;

public:
    void init(int n)
    {
        size = 1;
        while (size < n)
            size *= 2;
        minimums.assign(2*size, {0LL,0LL});
    }
    
    void set(int i, ll v, int x, int lx, int rx){
        if(rx-lx == 1) {
            minimums[x] = {v,1};
            return;
        }

        int m = (lx + rx) / 2;
        if( i < m){
              set(i,v,2*x+1,lx,m);
        }else{
              set(i,v,2*x+2,m,rx);
        }
        if(minimums[2*x + 1].first == minimums[2*x+2].first){
           minimums[x] = {minimums[2*x+2].first,minimums[2*x+2].second+minimums[2*x+1].second};
        }else if(minimums[2*x + 1].first < minimums[2*x+2].first){
          minimums[x] = minimums[2*x + 1];
        }else{
          minimums[x] = minimums[2*x + 2];
        }
    }

    void set(int i,ll v){
        set(i,v,0,0,size);
    }

    pair<ll,ll> minmum(int l,int r,int x,int lx,int rx){
        if(lx >= r || l >= rx) return {INT_MAX,1};
        if(lx >= l && r >= rx) return minimums[x];
        int m = (lx+rx)/2;
        auto s1 = minmum(l,r,2*x+1,lx,m);
        auto s2 = minmum(l,r,2*x+2,m,rx);
        if(s1.first == s2.first){
           return {s1.first,s1.second+s2.second};
        }else if(s1.first > s2.first){
             return s2;
        }else{
             return s1;
        }
    }

    pair<ll,ll> minmum(int l,int r){
           return minmum(l,r,0,0,size);
    }

};


int main()
{
    int n,m;
    cin>>n>>m;

    SegmentTree sg;
    sg.init(n);

    for(int i = 0;i<n;i++){
        ll x;
        cin>>x;
        sg.set(i,x);
    }

    while(m--){
        int op;
        cin>>op;
        if(op == 1){
            int i,v;
            cin>>i>>v;
            sg.set(i,v);
        }else{
            int l,r;
            cin>>l>>r;
            auto p = sg.minmum(l,r);
             cout<<p.first<<" "<<p.second<<endl;
        }
    }
}

