/*
# 0/1 KNAPSACK PROBLEM

LINK:- https://www.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1

APPROACH:- 

Knapsack Selection Strategy

- Check Weight Constraint
    Before adding an object to the knapsack, ensure its weight does not exceed the total capacity.

- If the Object’s Weight is Within Capacity:
    - We have two choices:
        a) Add the object to the knapsack and count its profit.
        b) Skip the object and explore other selections.

- If the Object’s Weight Exceeds Capacity:
    - The object must be skipped, as it cannot fit in the knapsack

*/

#include <bits/stdc++.h>
using namespace std;

int ks(int W, vector<int> &val, vector<int> &wt, int n){

    //AT SMALLEST, THEIR IS NO OBJECT PRESENT, SO N == 0, AND AT SMALLEST THE CAPACITY OF KNAPSACK IS 0, SO W == 0
    if (n == 0 || W == 0){
        return 0;
    }

    //If the Object’s Weight is Within Capacity:
    if (wt[n - 1] <= W){
        return max(val[n - 1] + ks(W - wt[n - 1], val, wt, n - 1), ks(W, val, wt, n - 1));
    }
    // If the Object’s Weight Exceeds Capacity:
    else if (wt[n - 1] > W){
        return ks(W, val, wt, n - 1);
    }
}

int knapsack(int W, vector<int> &val, vector<int> &wt){
    // code here
    int n = val.size();

    return ks(W, val, wt, n);
}

int main(){
    vector<int> val = {1,2,3};
    vector<int> wt = {4,5,1};
    int W = 4;
    cout<<knapsack(W, val, wt);
    return 0;
}