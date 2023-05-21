#include<bits/stdc++.h>
using namespace std;

template<class ForwardIterator, class T>
ForwardIterator Search(ForwardIterator start,ForwardIterator end,T key){
    while(start != end){
        auto p = *start;
        if(p.first == key){
            return start;
        }
        start++;
    }
    return end;
}

int main() {
    unordered_map<int,int> mp;
    mp[1] = 2;
    mp[3] = 8;
    mp[0] = 120;
    mp[10] = 6;
    // auto it = Search(v.begin(),v.end(),5);
    auto mt = Search(mp.begin(),mp.end(),3);
    auto p = *mt;
    cout<<p.first<<" "<<p.second<<endl;

}
