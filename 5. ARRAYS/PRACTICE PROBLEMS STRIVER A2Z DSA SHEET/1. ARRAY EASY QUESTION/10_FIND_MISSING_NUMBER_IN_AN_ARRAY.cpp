/*
#FIND MISSING NUMBER IN AN ARRAY
LINK:- https://leetcode.com/problems/missing-number/description/
*/

#include <bits/stdc++.h>
using namespace std;

// TIME COMPLEXITY:- O(n)
int missingNumber1(vector<int> &nums){
    int ans = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        ans = ans ^ nums[i];
    }

    for (int i = 0; i <= nums.size(); i++)
    {
        ans = ans ^ i;
    }
    return ans;
}

// TIME COMPLEXITY:- O(n log n)
int missingNumber2(vector<int> &nums){
    int n = nums.size();
    sort(nums.begin(), nums.end());
    for (int i = 0; i < n; i++)
    {
        if (i != nums[i])
            return i;
    }
    return n;
}

int main(){
    vector<int> arr = {1, 2};
    cout << "Missing number in given array is:- " << missingNumber1(arr);
    return 0;
}