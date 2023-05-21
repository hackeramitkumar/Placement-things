#include <bits/stdc++.h>
using namespace std;
#define ll long long

typedef int item;

class SegmentTree
{
    int size;
    vector<item> values;
     item NEUTRAL_ELEMENT = 0;

     item merge(item a,item b) { return max(a,b); }
     item single(int v) { return v; }

public:

    void init(int n)
    {
        size = 1;
        while (size < n)
            size *= 2;
        values.resize(2*size);
    }

 void build(vector<int> &a,int x,int lx, int rx) {
    if(rx - lx == 1){
        if(lx < (int)a.size()) values[x] = single(a[lx]);
        return;
    }

    int m = (lx+rx)/2;
    build(a,2*x+1,lx,m);
    build(a,2*x+2,m,rx);
    values[x] = merge(values[2*x+1],values[2*x+2]);
 }
 
 void build(vector<int> &a){
    build(a,0,0,size);
 }

    void set(int i, int v,int x, int lx, int rx)
    {
        if (rx - lx == 1)
        {
            values[x] = single(v);
            return;
        }

        int m = (lx + rx) / 2;
        if (i < m)
        {
            set(i, v,2 * x + 1, lx, m);
        }
        else
        {
            set(i,v, 2 * x + 2, m, rx);
        }
        values[x] = merge(values[2 * x + 1] , values[2 * x + 2]);
    }

    void set(int i,int v)
    {
        set(i,v, 0, 0, size);
    }

    ll find(int k, int x, int lx, int rx)
    {
        if(values[x] < k) return -1;
        if (rx - lx == 1)  return lx;

        int m = (lx + rx) / 2;
            int res =  find(k, 2 * x + 1, lx, m);
            if(res == -1)
            res = find(k, 2 * x + 2, m, rx);

            return res;
    }

    ll find(int k)
    {
        return find(k, 0, 0, size);
    }

     ll find2(int k, int x,int l, int lx, int rx)
    {
        if(values[x] < k) return -1;
if(rx <= l) return -1;

        if (rx - lx == 1)  return lx;
        int m = (lx + rx) / 2;
            int res =  find2(k, 2 * x + 1,l, lx, m);
            if(res == -1)
            res = find2(k, 2 * x + 2,l, m, rx);

            return res;
    }

    ll find2(int k,int l)
    {
        return find2(k, 0,l, 0, size);
    }

    
};

int main()
{
    int n, m;
    cin >> n >> m;
    SegmentTree sg;
    sg.init(n);
    vector<int> a;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        a.push_back(x);
    }

sg.build(a);

    while (m--)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            int x,i;
            cin >>i >> x;
            sg.set(i,x);
        }
        else
        {
            int k,l;
            cin >> k>>l;
            cout << sg.find2(k,l) << endl;
        }
    }
}