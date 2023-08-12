#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> st;

    // Push elements onto the stack
    st.push(10);
    st.push(20);
    st.push(30);

    // Check if the stack is empty
    if (st.empty()) {
        cout << "Stack is empty" << endl;
    } else {
        cout << "Stack is not empty" << endl;
    }

    // Access the top element
    cout << "Top element: " << st.top() << endl;

    // Pop elements from the stack
    st.pop();

    cout << "New top element: " << st.top() << endl;

    // Get the size of the stack
    cout << "Size of stack: " << st.size() << endl;
    
    cout<<"All elements in stack : "<<endl;
    while(!st.empty())
    {
        cout<<st.top()<<endl;
        st.pop();
    }
    

    return 0;
}


Output:

Stack is not empty
Top element: 30
New top element: 20
Size of stack: 2
All elements in stack : 
20
10
