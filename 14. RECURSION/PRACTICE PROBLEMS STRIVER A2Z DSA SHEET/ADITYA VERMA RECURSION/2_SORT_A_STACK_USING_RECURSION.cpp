/*
#SORT A STACK USING RECURSION

LINK:- https://www.naukri.com/code360/problems/sort-a-stack_985275

You’re given a stack consisting of 'N' integers. Your task is to sort this stack in descending order using recursion.

We can only use the following functions on this stack S.

is_empty(S) : Tests whether stack is empty or not.
push(S) : Adds a new element to the stack.
pop(S) : Removes top element from the stack.
top(S) : Returns value of the top element. Note that this function does not remove elements from the stack.
Note :
1) Use of any loop constructs like while, for..etc is not allowed. 
2) The stack may contain duplicate integers.
3) The stack may contain any integer i.e it may either be negative, positive or zero.

*/


#include<bits/stdc++.h>
using namespace std;

// Recursive function to insert an element into the sorted stack
void insert(stack<int> &stack, int temp){

    // Base condition: If stack is empty or the top element is smaller than or equal to 'temp'
    if(stack.empty() || stack.top() <= temp){
        stack.push(temp); // Insert the element directly
        return;
    }

    //INDUCTION PROCESS
    // Store the top element and remove it from the stack
    int value = stack.top();
    stack.pop();

    //HYPOTHESIS
    // Recursively call 'insert' to find the correct position for 'temp'
    insert(stack, temp);

    // Push back the stored element after placing 'temp' in its correct position
    stack.push(value);

    return;
}

// Recursive function to sort the stack
void sortStack(stack<int> &stack)
{
    // Base condition: If the stack is empty, there's nothing to sort
    if(stack.empty()){
        return;
    }

    //HYPOTHESIS
    // Store the top element and remove it from the stack
    int temp = stack.top();
    stack.pop();

    // Recursively sort the remaining stack
    sortStack(stack);


    //INDUCTION PROCESS
    // Insert the removed element back into the sorted stack
    insert(stack, temp);
}

int main(){
    // Initialize the stack with some unsorted elements
    stack<int> s;
    s.push(30);
    s.push(-5);
    s.push(18);
    s.push(14);
    s.push(-3);

    // Function call to sort the stack
    sortStack(s);

    // Print the sorted stack (smallest element on top)
    while(!s.empty()){
        cout << s.top() << " "; // Access the top element
        s.pop(); // Remove the top element
    }

    return 0;
}