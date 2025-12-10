/*
#FIND THE NUMBER THAT APPEARS ODD NUMBER OF TIMES

LINK:- https://takeuforward.org/strivers-a2z-dsa-course/strivers-a2z-dsa-course-sheet-2/
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            ans = ans ^ nums[i];
        }
        return ans;
    }
};

int main() {
    Solution sol;

    // Test Case 1: The single number is at the beginning
    vector<int> nums1 = { 4, 1, 2, 1, 2 };
    cout << "The number that appears an odd number of times in {4, 1, 2, 1, 2} is: " << sol.singleNumber(nums1) << endl;

    // Test Case 2: The single number is in the middle
    vector<int> nums2 = { 2, 2, 1 };
    cout << "The number that appears an odd number of times in {2, 2, 1} is: " << sol.singleNumber(nums2) << endl;

    // Test Case 3: The single number is at the end
    vector<int> nums3 = { 1, 2, 2, 3, 3, 4, 4 };
    cout << "The number that appears an odd number of times in {1, 2, 2, 3, 3, 4, 4} is: " << sol.singleNumber(nums3) << endl;

    // Test Case 4: The single number is the only element
    vector<int> nums4 = { 5 };
    cout << "The number that appears an odd number of times in {5} is: " << sol.singleNumber(nums4) << endl;

    return 0;
}