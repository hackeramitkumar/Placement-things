#include<bits/stdc++.h>
using namespace std;
#define ll long long
class node{
ll s;
};
 class SegmentTree{
private:
vector<node> st;
ll n;
public:
void merge(ll si){
        st[si].s = min(st[si*2].s,st[si*2+1].s);

}
void build(vector<ll> &a,ll l,ll r, ll si){
    if(l == r){
        st[si].s = a[l].s;
        return;
    }
    ll m = (l+r) >> 1;
    build(a,l,m,si*2);
    build(a,m+1,r,si*2+1);
    merge(si);
}

 };


int main() {
  int n;
  cin>>n;
  vector<int> v(n);
  for(int i = 0;i<n;i++){
    cin>>v[i];
  }
  int q;
  cin>>q;
  
  

}