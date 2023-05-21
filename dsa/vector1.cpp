#include<iostream>

using namespace std;

int main(){
int n;
cin>>n;
bool isFound = false;
long long mask = 1 << 30;
while(mask != 0){
    if(mask&n == 0 and !isFound){
        mask = mask >> 1;
        continue;
    }else{
        isFound = true;
if(mask&n ) cout<<"1";
else cout<<"0";

        mask = mask >> 1;
    }
}
cout<<endl;
}