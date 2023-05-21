#include <bits/stdc++.h>
using namespace std;
#define ll long long

class SegmentTree
{
    int size;
    vector<ll> sums;
public:
    void init(int n)
    {
        size = 1;
        while (size < n)
            size *= 2;
        sums.assign(2*size, 0LL);
    }
    
    void set(int i, int v, int x, int lx, int rx){
        if(rx-lx == 1) {
            sums[x] = v;
            return;
        }
        int m = (lx + rx) / 2;
        if( i < m){
              set(i,v,2*x+1,lx,m);
        }else{
              set(i,v,2*x+2,m,rx);
        }
        sums[x] = sums[2*x+1]+sums[2*x+2];
    }

    void set(int i,int v){
        set(i,v,0,0,size);
    }

    ll sum(int l,int r,int x,int lx,int rx){
        if(lx >= r || l >= rx) return 0;
        if(lx >= l && r >= rx) return sums[x];
        int m = (lx+rx)/2;
        ll s1 = sum(l,r,2*x+1,lx,m);
        ll s2 = sum(l,r,2*x+2,m,rx);
        return s1+s2;
    }
    ll sum(int l,int r){
           return sum(l,r,0,0,size);
    }
    

};

int main()
{
    int n,m;
    cin>>n>>m;

    SegmentTree sg;
    sg.init(n);

    for(int i = 0;i<n;i++){
        int x;
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
             cout<<sg.sum(l,r+1)<<endl;
        }
    }
}