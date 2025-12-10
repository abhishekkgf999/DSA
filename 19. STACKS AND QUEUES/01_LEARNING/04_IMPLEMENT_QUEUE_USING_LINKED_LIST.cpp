/*
#IMPLEMENTATION OF QUEUE USING LINKED LIST
*/

#include <bits/stdc++.h>
using namespace std;

// Node structure
class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};

// Queue class
class Queue {
    Node* front;  // points to front element
    Node* rear;   // points to last element
    int size;

public:
    Queue() {
        front = rear = nullptr;
        size = 0;
    }

    // Insert element at the end
    void enqueue(int x) {
        Node* newNode = new Node(x);
        if (rear == nullptr) { // queue is empty
            front = rear = newNode;
        }
        else {
            rear->next = newNode;
            rear = newNode;
        }
        size++;
    }

    // Remove element from front
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue underflow!!" << endl;
            return;
        }
        Node* temp = front;
        front = front->next;

        if (front == nullptr) { // queue became empty
            rear = nullptr;
        }

        delete temp;
        size--;
    }

    // Get front element
    int getFront() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return front->data;
    }

    // Get rear element
    int getRear() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return rear->data;
    }

    bool isEmpty() {
        return front == nullptr;
    }

    int getSize() {
        return size;
    }
};

// Driver code
int main() {
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Front: " << q.getFront() << endl; // 10
    cout << "Rear: " << q.getRear() << endl;   // 30
    cout << "Size: " << q.getSize() << endl;   // 3

    q.dequeue();
    cout << "Front after dequeue: " << q.getFront() << endl; // 20
    cout << "Size after dequeue: " << q.getSize() << endl;   // 2

    return 0;
}
