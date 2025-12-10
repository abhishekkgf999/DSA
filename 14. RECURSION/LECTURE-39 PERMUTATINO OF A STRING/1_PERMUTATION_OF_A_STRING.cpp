/*
#PERMUTATIONS

LINK:- https://leetcode.com/problems/permutations/

*/

/*
Intuition:

At each position index, we try placing every possible number (from index to end).

We recursively fix the next position after choosing one.

Use backtracking to undo the changes and try other possibilities.

Approach:

Use recursion to generate all permutations.

Use swapping to place different numbers at each position.

When a complete permutation is formed (index == nums.size()), add it to the result.

Backtrack to try other possibilities by undoing the swap.
*/

#include<bits/stdc++.h>
using namespace std;

void solve(vector<int> nums, vector<vector<int>> &ans, int index){
    // BASE CASE: If we've fixed all positions, store the permutation
    if(index >= nums.size()){
        ans.push_back(nums);
        return;
    }

    // RECURSIVE CASE: Fix the current index by trying all possible elements
    for(int j = index; j < nums.size(); j++){
        // Swap current element with the j-th element to fix it at 'index'
        swap(nums[index], nums[j]);

        // Recurse to fix the next index
        solve(nums, ans, index + 1);

        // BACKTRACK: Swap back to restore the original configuration
        swap(nums[index], nums[j]);
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> ans; 
    int index = 0;           
    solve(nums, ans, index); 
    return ans;              
}

int main(){
    
    return 0;
}