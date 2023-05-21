#include<bits/stdc++.h>
using namespace std;

void insert_at_Bottom(stack<int> &st,int x){
    if(st.empty()){
        st.push(x);
    }
    int data = st.top();
    st.pop();
    insert_at_Bottom(st,x);
    st.push(data);
}

void reverse(stack<int> &st){
    if(st.empty()) return;
    int x = st.top();
    st.pop();
    reverse(st);
    insert_at_Bottom(st,x);
}

int main() {
    stack<char> st;
    

}