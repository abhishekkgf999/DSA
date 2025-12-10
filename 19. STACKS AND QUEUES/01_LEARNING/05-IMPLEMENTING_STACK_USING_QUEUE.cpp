/*
#IMPLEMENT STACK USING QUEUE

LINK:- https://leetcode.com/problems/implement-stack-using-queues/description/
*/

#include<bits/stdc++.h>
using namespace std;

/*
Step-by-step process:
1. Put new element in q2 (it becomes the "top")
2. Transfer all old elements from q1 to q2 (preserves order)
3. Swap queues so q1 is main queue again
*/

class MyStack {
public:
    queue<int> q1;
    queue<int> q2;
    MyStack() {}

    void push(int x) {          //TC:- O(N)
        q2.push(x);
        while (!q1.empty()) {
            int ele = q1.front();
            q2.push(ele);
            q1.pop();
        }
        swap(q1, q2);
    }

    int pop() {
        if (q1.empty()) return -1;
        int ele = q1.front();
        q1.pop();
        return ele;
    }

    int top() {
        if (q1.empty()) return -1;
        return q1.front();
    }

    bool empty() { return q1.empty(); }
};

int main() {
    MyStack myStack;

    cout << "Is stack empty? " << (myStack.empty() ? "Yes" : "No") << endl;

    myStack.push(10);
    myStack.push(20);
    myStack.push(30);

    cout << "Pushed 10, 20, 30." << endl;
    cout << "Top element is: " << myStack.top() << endl;
    cout << "Is stack empty? " << (myStack.empty() ? "Yes" : "No") << endl;

    cout << "Popping elements: ";
    cout << myStack.pop() << " "; // Should pop 30
    cout << myStack.pop() << " "; // Should pop 20
    cout << myStack.pop() << endl; // Should pop 10

    cout << "Is stack empty? " << (myStack.empty() ? "Yes" : "No") << endl;

    myStack.push(40);
    cout << "Pushed 40." << endl;
    cout << "Top element is: " << myStack.top() << endl;

    return 0;
}