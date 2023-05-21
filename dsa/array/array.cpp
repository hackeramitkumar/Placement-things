#include<bits/stdc++.h>
using namespace std;


bool compare(int c, int d){
    return c > d;
}

void bubble_sort(int *a,int n,bool &myCompare(int c, int d)){

for(int i = n;i >= 1;i--){
    
    for(int j = 0;j<i;j++){
        if(myCompare(a[j],a[j+1])){
            swap(a[j],a[j+1]);
        }
    }
}
}
void selection_sort(int *a, int n){
    for(int i = 0;i<n-1;i++){
        int curr = i;
        for(int j = i+1;j<n;j++){
           if(a[j] < a[curr]){
            curr = j;
           }
        }
        swap(a[i],a[curr]);
    }
}

void insertion_sort(int *a, int n){
    for(int i = 1;i<n;i++){
        int pick = a[i];
        int j;
        for(j = i-1;j>= 0 and a[j] > pick;j--){
                a[j+1] = a[j];
        }
        a[j + 1] = pick;
    }
}



int main() {
    int n;
    cin >> n;

    int a[n];
    for(int i = 0;i<n;i++){
        cin>>a[i];
    }

    // bubble_sort(a,n);
    bubble_sort(a,n,compare);
    for(int i = 0;i<n;i++)
        cout<<a[i]<<" ";
}