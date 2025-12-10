/*
#MIN STACK

LINK:- https://leetcode.com/problems/min-stack/description/
*/

#include<bits/stdc++.h>
using namespace std;

//TC:- O(1) FOR ALL OPERATION, SC:- O(N)
class MinStack1 {
public:
    stack<int> s1;
    stack<int> s2;
    MinStack1() {
        
    }
    
    void push(int val) {
        s1.push(val);
        if(s2.empty() || s2.top() >= val) s2.push(val);
    }
    
    void pop() {
        int ele = s1.top();
        s1.pop();
        if(ele == s2.top())s2.pop();
    }
    
    int top() {
        return s1.top();
    }
    
    int getMin() {
        return s2.top();
    }
};

//TC:- O(1) FOR EVERY OPERATION, SC:- ONLY SINGLE STACK
class MinStack2 {
public:
    stack<pair<int, int>> s1;
    int mini = INT_MAX;
    MinStack2() {
        
    }
    
    void push(int val) {
        if(s1.empty()) s1.push({val, val});
        else s1.push({val, min(val, s1.top().second)});
    }
    
    void pop() {
        s1.pop();
    }
    
    int top() {
        return s1.top().first;
    }
    
    int getMin() {
        return s1.top().second;
    }
};

int main(){
    
    return 0;
}