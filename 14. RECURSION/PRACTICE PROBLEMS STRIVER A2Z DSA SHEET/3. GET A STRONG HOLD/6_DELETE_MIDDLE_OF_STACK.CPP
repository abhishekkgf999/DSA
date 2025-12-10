/*
#DELETE MIDDLE ELEMENT OF STACK

LINK:- https://www.geeksforgeeks.org/problems/delete-middle-element-of-a-stack/1

Given a stack s, delete the middle element of the stack without using any additional data structure.

Middle element:- floor((size_of_stack+1)/2) (1-based indexing) from the bottom of the stack.

Note: The output shown by the compiler is the stack from top to bottom.

Examples:

Input: s = [10, 20, 30, 40, 50]
Output: [50, 40, 20, 10]
Explanation: The bottom-most element will be 10 and the top-most element will be 50. Middle element will be element at index 3 from bottom, which is 30. Deleting 30, stack will look like {10 20 40 50}.

Input: s = [10, 20, 30, 40]
Output: [40, 30, 10]
Explanation: The bottom-most element will be 10 and the top-most element will be 40. Middle element will be element at index 2 from bottom, which is 20. Deleting 20, stack will look like {10 30 40}.

Input: s = [5, 8, 6, 7, 6, 6, 5, 10, 12, 9]
Output: [9, 12, 10, 5, 6, 7, 6, 8, 5]

*/


#include<bits/stdc++.h>
using namespace std;

void solve(stack<int> &s, int mid){
    //BASE CONDITION, IF WE REACH OUR MID, JUST POP IT OUT
    if(mid == 1){
        s.pop();
        return;
    } 

    //INDUCTION
    int temp = s.top();
    s.pop();

    solve(s, mid-1);    //HYPOTHESIS :- WE WILL ASSUME THAT, THIS FUNCTION WILL GIVE US REMAINING STACK, AFTER REMOVING MIDDLE 

    s.push(temp);   //AFTER GETTING OUR STACK(AFTER REMOVING MIDDLE), WE JUST INSERT OUR TOP ELEMENT BACK TO ITS PLACE
}

void deleteMid(stack<int>& s) {
    int n = s.size();
    if(n == 0)return;
    int mid = (n/2)+1;
        
    solve(s, mid);
}

int main(){
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    deleteMid(s);

    cout << "Stack after deleting middle element: ";
    while(!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }

    return 0;
}