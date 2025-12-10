/*
#IMPLEMENT QUEUE USING ARRAYS

LINK:- https://www.geeksforgeeks.org/problems/implement-queue-using-array/1
*/

#include<bits/stdc++.h>
using namespace std;

class MyQueue{
    int capacity;
    int *arr;
    int start;
    int end;
    int curr_size = 0;
    public:
        MyQueue(int x){
            capacity = x;
            arr = new int[capacity];
            start = 0, end = 0;
        }

        void push(int x){
            if(curr_size == capacity) return;
            if(curr_size == 0){
                start = 0, end = 0;
            }
            else{
                end = (end+1)%capacity;
            }

            arr[end] = x;
            curr_size++;
        }

        int pop(){
            if(curr_size == 0)return -1;

            int ele = arr[start];

            if(curr_size == 1){
                start = end = -1;
            }
            else{
                start = (start+1)%capacity;
            }

            curr_size--;
            return ele;
        }

        int peek(){
            if(curr_size == 0)return -1;
            return arr[start];
        }

        bool isEmpty(){
            return curr_size == 0;
        }

        bool isFull(){
            return curr_size == capacity;
        }
}; 

int main(){ 
    MyQueue q(5); 
    cout << "Is queue empty? " << (q.isEmpty() ? "Yes" : "No") << endl; 
    cout << "Is queue full? " << (q.isFull() ? "Yes" : "No") << endl; 
    q.push(10); 
    q.push(20); 
    q.push(30); 
    q.push(40); 
    q.push(50); 
    cout << "Pushed 5 elements." << endl; 
    cout << "Is queue empty? " << (q.isEmpty() ? "Yes" : "No") << endl; 
    cout << "Is queue full? " << (q.isFull() ? "Yes" : "No") << endl; 
    cout << "Front element is: " << q.peek() << endl; cout << "Popping elements: "; 
    cout << q.pop() << " "; 
    cout << q.pop() << " "; 
    cout << q.pop() << " "; 
    cout << q.pop() << " "; 
    cout << q.pop() << endl; 
    cout << "Is queue empty? " << (q.isEmpty() ? "Yes" : "No") << endl; 
    // Test circular behavior 
    q.push(60); 
    q.push(70); 
    cout << "Pushed 60 and 70." << endl; 
    cout << "Front element is: " << q.peek() << endl; 
    cout << "Popping: " << q.pop() << endl; 
    cout << "Front element is: " << q.peek() << endl; 
    return 0; 
} 