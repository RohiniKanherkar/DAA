//Linked list Operations
#include <iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;
    
    node(int val)
    {
        data=val;
        next=NULL;
    }
};

void insertAtHead(node *&head, int val)
{
    node* n = new node(val);
    n->next=head;
    head=n;
}

void insertAtTail(node *&head, int val)
{
    node* n = new node(val);
    if(head==NULL)
    {
        head=n;
        return;
    }
    node *temp=head;
    while(temp->next != NULL)
    {
        temp=temp->next;
    }
    temp->next=n;
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

void search(node* &head, int val)
{
    if(head==NULL)
    {
        return;
    }
    node* temp=head;
    int count=0;
    while(temp!=NULL)
    {
        if(temp->data == val)
        {
            break;
        }
        temp=temp->next; 
        count++;
    }
    cout<<"\nElement "<<val<<" Found at index "<<count<<endl;
}

void deletion(node* &head, int val)
{
    node* temp=head;
    while(temp!=NULL)
    {
        if(temp->next->data == val)
        {
            break;
        }
        temp=temp->next; 
    }
    node* todelete=temp->next;
    temp->next=temp->next->next;
    cout<<"\nElement "<<val<<" is deleted"<<endl;
    delete todelete;
}

void deleteathead(node* &head)
{
    cout<<"\nElement "<<head->data;
    node* todelete=head;
    head=head->next;
    cout<<" is deleted"<<endl;
    delete todelete;
}

//Iterative
node* reverse(node* &head)
{
    node* prev=NULL;
    node* curr=head;
    node* next;
    
    while(curr != NULL)
    {
        next=curr->next;   
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;
}
//recursive
node* reverseRec(node* &head)
{
    if(head==NULL || head->next==NULL)
    {
        return head;
    }
    node* n=reverseRec(head->next);
    head->next->next=head;
    head->next=NULL;
    return n;
}

void makeCycle(node* &head,int position)
{
    node* temp=head;
    node* t;
    int count=1;
    
    while(temp->next != NULL)
    {
        if(count==position)
        {
            t=temp;
        }
        temp=temp->next;
        count++;
    }
    temp->next=t;
}

bool detectCycle(node* &head)
{
    node *slow=head;
    node *fast=head;
    
    while(fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
        
        if(slow==fast)
        {
            return true;
        }
    }
    return false;
}

//Remove cycle

node* removeCycle(node* &head)
{
    node *slow=head;
    node *fast=head;
    
    do
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    while(slow!=fast);
    
    fast=head;
    while(slow->next != fast->next)
    {
        slow=slow->next;
        fast=fast->next;
    }
    slow->next=NULL;
    fast=head;
    return fast;
}
int main() 
{
    node* head=NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtHead(head,3);
    insertAtHead(head,4);
    insertAtTail(head,5);
    display(head);
    
    search(head,4);
    
    deletion(head,3);
    display(head);
    
    deleteathead(head);
    display(head);
    
    cout<<"\n\nReverse : ";
    node* newhead1=reverse(head);
    display(newhead1);

    cout<<"\n\nReverse Rec: ";
    node* newhead2=reverseRec(newhead1);
    display(newhead2);
    
    insertAtTail(head,6);
    insertAtTail(head,7);
    cout<<"\nLinkedlist =>"<<endl;
    display(head);
    //Make cycle-just for understanding
    makeCycle(head,3);
    // display(head); // ...cycle goes on
    //detect cycle
    // Hare & Tortoise Algorithm
    cout<<"\nCycle detect-1 OR Cycle not detect-0 ======>"<<detectCycle(head);
    
    //Remove cycle
    removeCycle(head);
    cout<<"\nCycle removed.."<<endl;
    cout<<"\nLinkedlist =>";
    display(head);
    return 0;
}

+-------------------------------------------------------------------------------------------------+

OUTPUT:

4 3 1 2 5 
Element 4 Found at index 0

Element 3 is deleted
4 1 2 5 

Element 4 is deleted
1 2 5 

Reverse : 5 2 1 
Reverse Rec: 1 2 5 
    
Linkedlist =>
1 2 5 6 7 
    
Cycle detect-1 OR Cycle not detect-0 ======>1
Cycle removed..

Linkedlist =>1 2 5 6 7 

    
+-------------------------------------------------------------------------------------------------+
