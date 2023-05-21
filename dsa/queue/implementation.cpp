#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Queue
{
    int arr *;
    int cs, ms, f, r;
    Queue(int ds = 5)
    {
        arr = new int[5];
        cs = 0;
        ms = ds;
        f = 0;
        r = ms - 1;
    }

    bool full()
    {
        return cs == ms;
    }

    void push(int data)
    {
        if (!full())
        {
            r = (r + 1) % ms;
            arr[r] = data;
            cs++;
        }
    }
    void pop()
    {
        if (full())
            return;
        f = (f + 1) % ms;
        cs--;
    }
    int front()
    {
        return arr[f];
    }
    ~Queue()
    {
        if (arr != NULL)
        {
            delete[] arr;
            arr = NULL;
        }
    }
};

int main()
{
}

/*

        1 2 3 0 0 0
        f f f f f

*/