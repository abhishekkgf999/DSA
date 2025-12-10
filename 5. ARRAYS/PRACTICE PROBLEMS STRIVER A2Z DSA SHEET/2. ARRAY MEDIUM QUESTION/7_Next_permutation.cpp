/*
                            ***MARK FOR REVISION***

#NEXT PERMUTATION

LINK:- https://leetcode.com/problems/next-permutation/
*/

#include<bits/stdc++.h>
using namespace std;

//SOLUTION -1 (GIVE TLE FOR ARRAY SIZE > 12)
//TIME COMPLEXITY:- N!*N ; SPACE COMPLEXITY:- O(N);
//WE ARE FINDING THE ALL PERMUTATION OF GIVEN ARRAY, AND THEN GIVING NEXT ELEMENT JUST AFTER THE OUR ARRAY
void permu(int ind, vector<int> &nums, vector<vector<int>> &ans){
    if(ind == nums.size()){
        ans.push_back(nums);
        return;
    }
    for(int i = ind; i<nums.size(); i++){
        swap(nums[ind], nums[i]);
        permu(ind+1, nums, ans);
        swap(nums[ind], nums[i]);
    }  
}
vector<vector<int>> findPermu(vector<int> &nums){
    vector<vector<int>> ans;
    permu(0, nums, ans);
    return ans;
}
void nextPermutation1(vector<int>& nums) {
    vector<vector<int>> allPermu = findPermu(nums);
    sort(allPermu.begin(), allPermu.end());
    auto it = find(allPermu.begin(), allPermu.end(), nums);
    if (it != allPermu.end() && next_permutation(nums.begin(), nums.end())) {
        nums = *find(allPermu.begin(), allPermu.end(), nums);
    }
}


//USING C++ INBUILT FUNCTION, WHICH AUTOMATICALLY CHANGES THE GIVEN ARRAY TO ITS NEXT PERMUTATION
//TIME COMPLEXITY:- O(N)
void nextPermutation2(vector<int>& nums) {
        next_permutation(nums.begin(), nums.end());
}

//OPTIMAL SOLUTION
/*
=> Find the break-point, i: Break-point means the first index i from the back of the given array where arr[i] becomes smaller than arr[i+1].
   For example, if the given array is {2,1,5,4,3,0,0}, the break-point will be index 1(0-based indexing). Here from the back of the array, 
   index 1 is the first index where arr[1] i.e. 1 is smaller than arr[i+1] i.e. 5.

=> To find the break-point, using a loop we will traverse the array backward and store the index i where arr[i] is less than the value at index (i+1) i.e. arr[i+1].

=> If such a break-point does not exist i.e. if the array is sorted in decreasing order, the given permutation is the last one in the sorted order 
   of all possible permutations. So, the next permutation must be the first i.e. the permutation in increasing order.

=> So, in this case, we will reverse the whole array and will return it as our answer.

=> If a break-point exists:
   Find the smallest number i.e. > arr[i] and in the right half of index i(i.e. from index i+1 to n-1) and swap it with arr[i].
   Reverse the entire right half(i.e. from index i+1 to n-1) of index i. And finally, return the array.
*/
//TIME COMPLEXITY:- O(N), SPACE COMPLEXITY:- O(1)
void nextPermutation3(vector<int>& nums) {
    int n = nums.size(); // size of the array.

    // Step 1: Find the break point:
    int ind = -1; // break point
    for (int i = n - 2; i >= 0; i--) {
        if (nums[i] < nums[i + 1]) {
            // index i is the break point
            ind = i;
            break;
        }
    }

    // If break point does not exist:
    if (ind == -1) {
        // reverse the whole array:
        reverse(nums.begin(), nums.end());
        return;
    }

    // Step 2: Find the next greater element
    //         and swap it with arr[ind]:

    for (int i = n - 1; i > ind; i--) {
        if (nums[i] > nums[ind]) {
            swap(nums[i], nums[ind]);
            break;
        }
    }

    // Step 3: reverse the right half:
    reverse(nums.begin() + ind + 1, nums.end());

}
int main(){
    // vector<int> nums = {1,0,0,1,0,0};
    vector<int> nums = {2,1,5,4,3,0,0};
    nextPermutation3(nums);
    for(auto i : nums){
        cout<<i<<" ";
    }
    return 0;
}