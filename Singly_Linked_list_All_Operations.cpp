//Singly Linked list Operations
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
    return 0;
}
