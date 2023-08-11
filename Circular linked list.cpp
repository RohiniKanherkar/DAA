//Circular list
#include<iostream>
using namespace std;

class node
{
    public:
    int data;
    node* next;
    
    node(int val)
    {
        data=val;
        next=NULL;
    }
};

void insertAtHead(node* &head, int val)
{
    node* n=new node(val);
    node* temp=head;
    
    if(head==NULL)
    {
        n->next=n;
        head=n;
        return;
    }
    while(temp->next!=head)
    {
        temp=temp->next;
    }
    temp->next=n;
    n->next=head;
    head=n;
}

void insertAtTail(node* &head, int val)
{
    if(head==NULL)
    {
        insertAtHead(head,val);
        return;
    }
    node* n=new node(val);
    node* temp=head;
    while(temp->next!=head)
    {
        temp=temp->next;
    }
    temp->next=n;
    n->next=head;
}


void display(node* &head)
{
    node* temp=head;
    do
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    while(temp!=head);
    cout<<endl;
    // cout<<head->data<<endl;
}

void deleteAtHead(node* &head)
{
    node* temp=head;
    while(temp->next!=head)
    {
        temp=temp->next;
    }
    node* todelete=head;
    temp->next=head->next;
    head=head->next;
    
    delete todelete;
}

void deletion(node* &head, int pos)
{
    if(pos==1)
    {
        deleteAtHead(head);
        return;
    }
    node* temp=head;
    int count=1;
    
    while(count!=pos-1)
    {
        temp=temp->next;
        count++;
    }
    node* todelete=temp->next;
    temp->next=temp->next->next;
    delete todelete;
}


int main()
{
    node* head =NULL;
    //insertion
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,4);
    display(head);
    insertAtHead(head,5);
    insertAtHead(head,6);
    display(head);
    
    //deletion
    deletion(head,1);//delete head node
    display(head);
    
    deletion(head,3);//delete in between node
    display(head);
    
    deletion(head,4);//delete last node
    display(head);
    
    return 0;
}


// OUTPUT :
// 1 2 3 4 
// 6 5 1 2 3 4 
// 5 1 2 3 4 
// 5 1 3 4 
// 5 1 3 
