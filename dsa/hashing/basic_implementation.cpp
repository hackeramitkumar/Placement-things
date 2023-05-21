#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Node
{
    Node<T> *next;
    string key;
    T val;
    Node(string key, T val)
    {
        this->key = key;
        this->val = val;
        next = NULL;
    }
    ~Node()
    {
        if (next != NULL)
            delete next;
    }
};

template <typename T>
class HashTable
{
    Node<T> **hashTable;
    int currSize;
    int tableSize;

    void rehash()
    {
        Node<T> **oldTable = hashTable;
        int oldTableSize = tableSize;
        tableSize = 2 * tableSize;
        hashTable = new Node<T> *[tableSize];
        for (int i = 0; i < tableSize; i++)
            hashTable[i] = NULL;
        currSize = 0;
        for (int i = 0; i < oldTableSize; i++)
        {
            Node<T> *temp = oldTable[i];
            while (temp != NULL)
            {
                insert(temp->key, temp->val);
                temp = temp->next;
                currSize++;
            }
            if (oldTable[i] != NULL)
            {
                delete oldTable[i];
            }
        }
        delete oldTable;
    }

public:
    HashTable(int ts = 7)
    {
        currSize = 7;
        hashTable = new Node<T> *[tableSize];
        currSize = 0;
        for (int i = 0; i < tableSize; i++)
            hashTable[i] = NULL;
    }

    int HashFn(string key)
    {
        int idx = 0;
        int p = 1;
        for (int i = 0; key[i] != '\0'; i++)
        {
            idx = idx + (key[i] * p) % tableSize;
            idx = idx % tableSize;
            p = (p * 27) % tableSize;
        }
        return idx;
    }

    void insert(string key, T value)
    {
        float loadFactor = curr_size / (1.0*table_size) ;
        if(loadFactor > .7) rehash();
        int idx = hashFn(key);
        Node<T> *n = new Node<T>(key, value);
        n->next = hashTable[idx];
        hashTable[idx] = n;
        currSize++;
    }

    T search(string key) {
        int idx = HashFn(key);
        Node<T>* temp = hashTable[idx];
        while(temp != NULL) {
            if(temp->key == key) return temp->val;
            temp = temp->next;
        }
        return NULL;
    }
};
int main()
{
}