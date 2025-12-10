/*
#IMPLEMENT QUEUE USING STACKS

LINK:- https://leetcode.com/problems/implement-queue-using-stacks/description/
*/

#include<bits/stdc++.h>
using namespace std;

class MyQueue {
public:
    stack<int> s1;
    stack<int> s2;
    MyQueue() {

    }

    void push(int x) {
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }

        s2.push(x);

        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
    }

    int pop() {
        if (s1.empty()) return -1;

        int ele = s1.top();
        s1.pop();
        return ele;
    }

    int peek() {
        if (s1.empty()) return -1;
        return s1.top();
    }

    bool empty() {
        return s1.empty();
    }
};

int main() {
    MyQueue myQueue;

    cout << "Is queue empty? " << (myQueue.empty() ? "Yes" : "No") << endl;

    myQueue.push(10);
    myQueue.push(20);
    myQueue.push(30);

    cout << "Pushed 10, 20, 30." << endl;
    cout << "Front element is: " << myQueue.peek() << endl; // Should be 10
    cout << "Is queue empty? " << (myQueue.empty() ? "Yes" : "No") << endl;

    cout << "Popping elements: ";
    cout << myQueue.pop() << " "; // Should pop 10
    cout << myQueue.pop() << " "; // Should pop 20
    cout << myQueue.pop() << endl; // Should pop 30

    cout << "Is queue empty? " << (myQueue.empty() ? "Yes" : "No") << endl;

    myQueue.push(40);
    cout << "Pushed 40." << endl;
    cout << "Front element is: " << myQueue.peek() << endl; // Should be 40

    return 0;
}