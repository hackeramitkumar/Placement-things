#include<stdio.h>

template<typename T>
class vector1 {
    int cs;
    int ms;
    T* arr;

    vector(){
        ms = 1;
        cs = 0;
        arr = new T[ms];
    }

    void push_back(T d){
        if(cs == ms){
            T* oldArr = arr;
            T* arr = new T[2*ms];
            ms = 2*ms;
            for(int i = 0;i<cs;i++) arr[i] = oldArr[i];
            delete oldArr[];
        }
         arr[cs] = d;
        cs++;
    }


void pop_back(){  cs--; }
void front() const {return arr[0]; }
void back() const {return arr[cs-1]; }
bool empty(){ return cs==0; }
int capacity(){ return ms;}
T at(const int i) { return arr[i]; }
T operator[](const int i){ return arr[i]; }
       
};
