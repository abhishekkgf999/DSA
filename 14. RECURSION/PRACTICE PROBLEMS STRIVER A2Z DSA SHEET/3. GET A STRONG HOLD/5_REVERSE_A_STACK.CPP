/*
#REVERSE A STACK

LINK:- https://www.geeksforgeeks.org/problems/reverse-a-stack/1

*/


#include<bits/stdc++.h>
using namespace std;

//THIS IS INDUCTION PROCESS FOR REVERSE FUNCTION
void insert(stack<int> &s, int ele){
        //BASE CONDITION :- WHEN STACK IS EMPTY, JUST PUSH THE ELEMENT
        if(s.empty()){
            s.push(ele);
            return;
        }
        
        //INDUCTION FOR INSERT FUNCTION:- 
        int temp = s.top();
        s.pop();
        
        //HYPOTHESIS
        insert(s, ele);
        
        // Restore the temporarily removed top element
        s.push(temp);
    }
    void Reverse(stack<int> &s){
        // Base case: If the stack contains only one element, it is already reversed
        if(s.size()==1)return;
        
        // Induction step: Remove the top element and store it
        int store = s.top();
        s.pop();
        
        // Recursive call to reverse the remaining stack
        Reverse(s);
        // Insert the removed element at the bottom of the reversed stack
        insert(s, store);
    }

int main(){
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    //STACK BEFORE :- 5(TOP), 4, 3, 2, 1
    Reverse(s);
    //STACK AFTER :- 1(TOP), 2, 3, 4, 5

    cout << "Stack after reversing: ";
    while(!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }

    return 0;
}