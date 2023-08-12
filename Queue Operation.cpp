#include <iostream>
using namespace std;

class Queue
{
    int* arr;
    int front;
    int rear;
    int n; // Size of the queue
    
    public:
        Queue(int size)
        {
            n = size;
            arr = new int[n];
            front = -1;
            rear = -1;
        }
    
    void push(int x)
    {
        if (rear == n - 1)
        {
            cout << "\nQueue is full!" << endl;
            return;
        }
        rear++;
        arr[rear] = x;
        if (front == -1)
        {
            front++;
        }
    }
    
    void pop()
    {
        if (front == -1 || front > rear)
        {
            cout << "\nQueue is already empty!" << endl;
            return;
        }
        front++;
    }
    
    int peek()
    {
        if (front == -1 || front > rear)
        {
            cout << "\nQueue is empty!" << endl;
            return -1;
        }
        return arr[front];
    }
    
    bool empty()
    {
        if (front == -1 || front > rear)
        {
            return true;
        }
        return false;
    }
};

int main()
{
    Queue q(5);
    q.push(1);
    q.push(2);
    q.push(2);
    q.push(4);
    q.push(1);
    
    cout << "Front element: " << q.peek() << endl;
    q.pop();
    cout << "Front element after pop: " << q.peek() << endl;
    
    return 0;
}




OUTPUT:
Front element: 1
Front element after pop: 2
