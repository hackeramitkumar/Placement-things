#include<bits/stdc++.h>
using namespace std;;
class Stack{
queue<int> q1;
queue<int> q2;

public:
void push(int x){
    while(!q1.empty()){
        q2.push(q1.front());
        q1.pop();
    }
    q1.push(x);
while(!q2.empty()){
    q1.push(q2.front());
    q2.pop();
}
}
void pop(){
    q1.pop();
}
int top(){
    return q1.front();
}
int size(){
    return q1.size()+q2.size();
}
bool empty(){
    return q1.size()+q2.size() == 0;
}

};
int main(){
Stack st;
st.push(3);
st.push(4);
st.push(5);
st.push(6);
while(!st.empty()){
    cout<<st.top()<<" ";
    st.pop();
}

}
