/*
#UNBOUNDED KNAPSACK PROBLEM

LINK:- https://www.geeksforgeeks.org/problems/knapsack-with-duplicate-items4201/1

*/

/*
#INTUITION
<!--Describe your first thoughts on how to solve this problem. -->

#APPROACH
<!-- Describe your approach to solving the problem -->

#COMPLEXITY
<!-- Time complexity -->
<!-- Space complexity -->

#CODE
<!--
    ....
    ....
    ....
-->

*/

#include<bits/stdc++.h>
using namespace std;

//TIME COMPEXITY :- EXPONENTIAL
//SPACE COMPLEXITY :- O(N);

//APPROACH - 1 
int solve1(vector<int>& val, vector<int>& wt, int capacity, int n) {
    if (n == 0 || capacity == 0) {
        return 0;
    }

    if (wt[n - 1] <= capacity) {
        
        // int value = max(val[n - 1] + solve(val, wt, capacity - wt[n - 1], n - 1), val[n - 1] + solve(val, wt, capacity - wt[n - 1], n));
            
        return max(val[n - 1] + solve1(val, wt, capacity - wt[n - 1], n), solve1(val, wt, capacity, n - 1));
    } 
    else {
        return solve1(val, wt, capacity, n - 1);
    }
}

int knapSack1(vector<int>& val, vector<int>& wt, int capacity) {
    // code here
    int n = wt.size();
    return solve1(val, wt, capacity, n);
}

//APPROACH - 2
//At each step, for item i and remaining capacity W:

// You can either:

// Pick the item (if its weight ≤ current capacity) → stay on the same item (since it’s unbounded).

// Not pick the item → move to the next item.

int solve2(vector<int> &val, vector<int> &wt, int capacity, int n){
    /*
    
    🔹 Situation:
    You're at index 0 — meaning you can only use the first item (0th index) to fill the knapsack of capacity W.

    And since it’s unbounded, you can take the first item as many times as you want, as long as the total weight doesn’t exceed W.

    🔹 Why is this needed?
    When you're only allowed to use 1 item:

    You can't go to index - 1, so you must solve the problem directly.

    You use the full capacity W by taking this item multiple times.

    This avoids going into negative index and gives a meaningful, optimal base result.
*/
    if(n == 1){
        return (capacity/wt[n-1])*val[n-1];
    }

    int take = 0;
    if(wt[n-1]<= capacity){
        take += val[n-1] + solve2(val, wt, capacity-wt[n-1], n);
    }

    int not_take = solve2(val, wt, capacity, n-1);

    return max(take, not_take);
}

int knapSack2(vector<int> &val, vector<int> &wt, int capacity){
    int n = wt.size();
    return solve2(val, wt, capacity, n);
}

int main(){
    vector<int> val = {6, 1, 7, 7};
    vector<int> wt = {1, 3, 4, 5};

    int capacity = 8;

    // cout<<knapSack1(val, wt, capacity);
    cout<<knapSack2(val, wt, capacity);

    return 0;
}