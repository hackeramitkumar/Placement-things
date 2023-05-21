#include<bits/stdc++.h>
using namespace std;

int binary_search1(vector<int> &v, int s,int e,int key){
    if(s > e) return -1;
    int mid = (s+e)/2;
    if(v[mid] == key) return mid;
    else if(v[mid] > key) return binary_search1(v,s,mid-1,key);
    else return binary_search1(v,mid+1,e,key);
}
int first_occurance(vector<int> &v, int s,int e,int key){
    if(s > e) return -1;
    int mid = (s+e)/2;
    int ans = INT_MAX;
    if(v[mid] >= key) return first_occurance(v,s,mid-1,key);
    else if(v[mid] > key) return binary_search1(v,s,mid-1,key);
    else return binary_search1(v,mid+1,e,key);
}

int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i = 0;i<n;i++) cin>>v[i];
    int k;
    cin>>k;
cout<<binary_search1(v,0,n-1,k)<<endl;

}