#include <bits/stdc++.h>
using namespace std;
#define ll long long
class Node
{
public:
ll sum,pref,suf,seg;
};

class SegmentTree
{
    int size;
    vector<Node*> sums;
public:
    void init(int n)
    {
        size = 1;
        while (size < n)
            size *= 2;
        sums.assign(2*size,new Node());
    }
    
    void set(int i, int v, int x, int lx, int rx){
        Node* n = new Node();
        if(rx-lx == 1) {
            n->sum = n->pref = n->suf = n->seg = v;
            sums[x] = n;
            return;
        }

        int m = (lx + rx) / 2;

        if( i < m){
              set(i,v,2*x+1,lx,m);
        }else{
              set(i,v,2*x+2,m,rx);
        }

        n->seg = max({sums[2*x+1]->seg,sums[2*x+2]->seg,sums[2*x+1]->suf + sums[2*x+2]->pref});
        n->pref = max(sums[2*x+1]->pref,sums[2*x+1]->sum+sums[2*x+2]->pref);
        n->suf = max(sums[2*x+2]->suf,sums[2*x+2]->sum+sums[2*x+1]->suf);
        n->sum = sums[2*x+1]->sum + sums[2*x+2] -> sum;
        sums[x] = n;
        
    }

    void set(int i,int v){
        set(i,v,0,0,size);
    }

    ll sum(){
        return sums[0]->seg > 0 ? sums[0]-> seg:0;
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
        scanf("%d",&x);
        sg.set(i,x);
    }
            printf("%lld \n",sg.sum());
    while(m--){
            int i,v;
        scanf("%d %d",&i,&v);
            sg.set(i,v);

            printf("%lld \n",sg.sum());
            
    }

    return 0;
}