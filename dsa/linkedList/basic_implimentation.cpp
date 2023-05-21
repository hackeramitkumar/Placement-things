#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int val;
    node* next;
    node(int x)
    {
        val = x;
        next = NULL;
    }
};

void insertAtHead(int x, node* &head)
{
    if(head == NULL){
        head = new node(x);
        return;
    }
    node *newHead = new node(x);
    newHead -> next = head;
    head = newHead;
}
void insertAttail(int x,node* &head){
if(head == NULL){
    head = new node(x);
}
node* temp = head;
while(temp->next != NULL) temp = temp->next;
node* n = new node(x);
temp->next = n;
}

void insertInMiddle(int x, node* prev){
     if(prev == NULL){
        
     }
     node* n = new node(x);
     node* temp = prev->next;
     prev->next = n;
     n->next = temp;
}
void insertAtKthPlace(int k,node*&head){

}

void print(node* head){
     node* temp = head;
    while(temp != NULL){
        cout<<temp->val<<" ";
        temp = temp->next;
    }
    cout<<"\n";
}
int main()
{

    node *head = NULL;
    insertAtHead(6,head);
    insertAtHead(8,head);
    insertAtHead(5,head);
    insertAtHead(3,head);
    print(head);
    insertAttail(8,head);
    print(head);
    insertInMiddle(10,head->next->next);
    print(head);


   
    return 0;

}