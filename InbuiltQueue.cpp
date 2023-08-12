#include <iostream>
#include <queue>
using namespace std;

void display(queue<int>& q)
{
    queue<int> newq=q;
    while(!newq.empty())
    {
        cout<<newq.front()<<" ";
        newq.pop();
    }
}

int main() {
   
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    cout<<"\nSize of queue : "<<q.size()<<endl;
    cout << "\nQueue elements: ";
    display(q);
    cout << "\nFront element: " << q.front()<<endl;
    q.pop();
    cout << "Front element: " << q.front()<<endl;
    cout << "\nQueue elements: ";
    display(q);cout<<endl;
    cout<<q.empty();
    
    return 0;
}


OUTPUT:
Size of queue : 5
Queue elements: 1 2 3 4 5 
Front element: 1
Front element: 2
Queue elements: 2 3 4 5 
0
