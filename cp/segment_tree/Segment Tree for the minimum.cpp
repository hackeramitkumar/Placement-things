#include <bits/stdc++.h>
using namespace std;
#define ll long long

class SegmentTree
{
    int size;
    vector<ll> minimums;
public:
    void init(int n)
    {
        size = 1;
        while (size < n)
            size *= 2;
        minimums.assign(2*size, 0LL);
    }
    
    void set(int i, int v, int x, int lx, int rx){
        if(rx-lx == 1) {
            minimums[x] = v;
            return;
        }

        int m = (lx + rx) / 2;
        if( i < m){
              set(i,v,2*x+1,lx,m);
        }else{
              set(i,v,2*x+2,m,rx);
        }
        minimums[x] = min(minimums[2*x+1],minimums[2*x+2]);
    }

    void set(int i,int v){
        set(i,v,0,0,size);
    }

    ll minmum(int l,int r,int x,int lx,int rx){
        if(lx >= r || l >= rx) return INT_MAX;
        if(lx >= l && r >= rx) return minimums[x];
        int m = (lx+rx)/2;
        ll s1 = minmum(l,r,2*x+1,lx,m);
        ll s2 = minmum(l,r,2*x+2,m,rx);
        return min(s1,s2);
    }

    ll minmum(int l,int r){
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
             cout<<sg.minmum(l,r)<<endl;
        }
    }
}