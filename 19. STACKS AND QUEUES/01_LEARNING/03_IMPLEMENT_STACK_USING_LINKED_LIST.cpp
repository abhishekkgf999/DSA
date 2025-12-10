/*
#IMPLEMENTING STACK USING LINKED LIST
*/

#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int x) {
        data = x;
        next = nullptr;
    }
};

class Stack {

    Node* top;
    int size;
public:

    Stack() {
        top = nullptr;
        size = 0;
    }

    void push(int x) {
        Node* newNode = new Node(x);
        newNode->next = top;
        top = newNode;
        size++;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack underflow!!" << endl;
            return;
        }
        Node* temp = top;
        top = top->next;
        delete temp;
        size--;
    }

    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return -1;
        }

        return top->data;
    }

    bool isEmpty() {
        return top == nullptr;
    }

    int getSize() {
        return size;
    }
};

int main() {
    Stack s;
    s.push(10);
    s.push(20);
    cout << s.peek() << endl; // 20
    s.pop();
    cout << s.peek() << endl; // 10
    cout << s.getSize() << endl; // 1
}
