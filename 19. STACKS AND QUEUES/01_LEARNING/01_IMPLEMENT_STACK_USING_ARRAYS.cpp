/*
#IMPLEMENT STACK USING ARRAYS

LINK:- https://www.geeksforgeeks.org/problems/implement-stack-using-array/1
*/

#include<bits/stdc++.h>
using namespace std;

class myStack {
    int* arr;
    int capacity;
    int top;
public:
    myStack(int cap) {
        capacity = cap;
        arr = new int[capacity];
        top = -1;
    }

    void push(int x) {      //TC :- O(1)
        if (top == capacity - 1) {
            cout << "Stack Overflow";
            return;
        }
        arr[++top] = x;
    }

    int pop() {     //TC :- O(1)
        if (top == -1) {
            cout << "Stack Underflow";
            return -1;
        }
        return arr[top--];
    }

    int peek() {        //TC :- O(1)
        if (top == -1) {
            cout << "Stack is Empty";
            return -1;
        }
        return arr[top];
    }

    bool isEmpty() {    //TC :- O(1)
        return top == -1;
    }

    bool isFull() {     //TC :- O(1)
        return top == capacity - 1;
    }
};

int main() {
    myStack st(4);

    // pushing elements
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);

    // popping one element
    cout << "Popped: " << st.pop() << "\n";

    // checking top element
    cout << "Top element: " << st.peek() << "\n";

    // checking if stack is empty
    cout << "Is stack empty: " << (st.isEmpty() ? "Yes" : "No") << "\n";

    // checking if stack is full
    cout << "Is stack full: " << (st.isFull() ? "Yes" : "No") << "\n";

    return 0;
}