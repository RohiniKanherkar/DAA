#include <iostream>
using namespace std;

#define n 100

class stack{
    int *arr;
    int top;

public:
    stack() {
        arr = new int[n];
        top = -1;
    }

    void push(int x) {
        if (top == n - 1) {
            cout << "\nStack is full" << endl;
            return;
        }
        top++;
        arr[top] = x;
    }

    void pop() {
        if (top == -1) {
            cout << "\nStack is underflow. No element to be deleted" << endl;
            return;
        }
        top = (top - 1 + n) % n; // Circular decrement
    }

    int Top() {
        if (top == -1) {
            cout << "No Element" << endl;
            return -1;
        }
        return arr[top];
    }

    bool empty() {
        return (top == -1);
    }
};

int main() {
    stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.pop();
    cout << "Top element: " << st.Top() << endl;
    cout << "Is stack empty? " << (st.empty() ? "Yes" : "No") << endl;

    return 0;
}




OUTPUT :

Top element: 2
Is stack empty? No
