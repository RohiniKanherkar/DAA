// Doubly linked list
#include <iostream>
using namespace std;

class node
{
    public:
    int data;
    node* prev;
    node* next;
    
    node(int val)
    {
        data=val;
        prev=NULL;
        next=NULL;
    }
};

void insertAtHead(node* &head,int val)
{
    node* n=new node(val);
    n->next=head;
    if(head != NULL)
    {
        head->prev=n;
    }
    head=n;
}

void insertAtTail(node* &head,int val)
{
    if(head==NULL)    
    {
        insertAtHead(head,val);
        return;
    }
    node* temp=head;
    node* n=new node(val);
    
    while(temp->next != NULL)
    {
        temp=temp->next;
    }
    temp->next=n;
    n->prev=temp;
    
}


void display(node* &head)
{
    if(head==NULL)    
    {
        return;
    }
    node* temp=head;
    while(temp != NULL)
    {
        cout<<temp->data<< " ";
        temp=temp->next;
    }
}

void deleteAtHead(node* &head)
{
    node* todelete=head;
    head=head->next;
    head->prev=NULL;
    
    delete todelete;
}

void deletion(node* &head,int pos)
{
    if(pos==1)
    {
        deleteAtHead(head);
        return;
    }
    int count=1;
    node* temp=head;
    
    while(temp != NULL && count!=pos)
    {
        temp=temp->next;
        count++;
    }
    temp->prev->next=temp->next;
    if(temp->next != NULL)
    {
        temp->next->prev=temp->prev;       
    }
    delete temp;
}

int main() {
    // Write C++ code here
    node* head=NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,4);
    display(head);cout<<endl;
    
    insertAtHead(head,5);
    insertAtHead(head,6);
    display(head);
    
    deletion(head,4);cout<<endl;//at middle
    display(head);
    
    deletion(head,1);cout<<endl;//at start
    display(head);
    
    deletion(head,4);cout<<endl;//at end
    display(head);
    return 0;
}




OUTPUT:

1 2 3 4 
6 5 1 2 3 4 
6 5 1 3 4 
5 1 3 4 
5 1 3 
