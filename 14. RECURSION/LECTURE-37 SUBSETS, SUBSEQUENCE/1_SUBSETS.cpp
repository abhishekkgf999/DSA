/*
#SUBSETS    (USING RECURSION)

LINK:- https://leetcode.com/problems/subsets/

*/

#include<bits/stdc++.h>
using namespace std;

void solve(vector<int> nums, vector<int> output, int index, vector<vector<int>> &ans) {
    // BASE CASE: If the index has reached or exceeded the size of the input vector,
    // it means we have formed a subset and should store it in the result.
    if(index >= nums.size()){
        ans.push_back(output); // Add the current subset (output) to the final answer.
        return;                // Terminate this recursion branch.
    }

    // RECURSIVE CASE 1: Exclude the current element.
    // Do not add nums[index] to the subset and move to the next index.
    solve(nums, output, index+1, ans);

    // RECURSIVE CASE 2: Include the current element.
    // Add nums[index] to the subset and move to the next index.
    output.push_back(nums[index]); // Include the element in the subset.
    solve(nums, output, index+1, ans); // Proceed with the next index after inclusion.
}

vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> ans;  // This will store all subsets of the input vector.
    vector<int> output;       // Temporary vector to hold the current subset.
    int index = 0;            // Start processing elements from the first index.
    
    // Begin the recursive process to generate all subsets.
    solve(nums, output, index, ans);

    return ans;               // Return the complete list of subsets.
}


int main(){
    
    return 0;
}