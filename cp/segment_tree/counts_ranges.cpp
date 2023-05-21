#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int cnt = 0,sum = 0;
};
class ST{
    public:
    vector<Node*> sums;
    int size;

    void init(int n){
        size = 1;
        while(size < n){
            size = 2*size;
        }
        sums.resize(2*size,new Node());
    }
    
void set(int idx,int val,int x,int low,int up,int lx,int rx){
    if(rx - lx == 1){
        sums[x]->sum = val;
        if(sums[x]->sum >= low and sums[x]->sum <= up){
            sums[x]->cnt = 1;
        }
        return;
    }
    int m = (lx+rx) / 2;
    if(idx < m){
        set(idx,val,2*x+1,low,up,lx,m);
    }else{
        set(idx,val,2*x+2,low,up,m,rx);
    }
    sums[x]->cnt = sums[2*x+1]->cnt + sums[2*x+2]->cnt;
    sums[x]->sum = sums[2*x+1]->sum + sums[2*x+2]->sum;
}
    void set(int idx,int val,int low,int up){
        set(idx,val,0,low,up,0,size);
    }

    int rangeCnt(){
        return sums[0]->cnt;
    }
}
int main(){

}