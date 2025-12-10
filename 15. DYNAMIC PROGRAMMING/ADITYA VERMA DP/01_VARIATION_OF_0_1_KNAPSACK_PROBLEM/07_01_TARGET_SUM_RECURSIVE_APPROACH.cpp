/*
#TARGET SUM

LINK:- https://leetcode.com/problems/target-sum/

*/

#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>& nums, int target, int n) {
    if (n == 0) {
        if (target == 0)
            return 1;
        return 0;
    }

    return solve(nums, target + nums[n - 1], n - 1) + solve(nums, target - (nums[n - 1]), n - 1);
}
int findTargetSumWays(vector<int>& nums, int target) {
    int n = nums.size();
    return solve(nums, target, n);
}

/*
***THIS PROBLEM IS ALSO DEDUCED INTO THE PREVIOUS PROBLEM OF :- COUNT THE NUMBER OF SUBSETS WITH GIVEN DIFFERENCE***

FOR EXAMPLE :- NUMS = [1,1,1,1,1], TARGET = 3

ONE OF ITS SOLUTION IS :- -1 + 1 + 1 + 1 + 1 = 3;

IN THE ABOVE SOLUTION, WE CAN DIVIDE THOSE NUMBER INTO 2 SETS, +(1, 1, 1, 1) AND -(1) {+GROUP, AND -GROUP}

=> AND WE HAVE TO JUST DO SET1 - SET2 = TARGET

=> 4-1 = 3 (== TARGET)
 */

int solve2(vector<int> &arr, int start, int sum, int required){
    if(start == arr.size()){
        if(sum == required)return 1;
        return 0;
    }

    return solve2(arr, start+1, sum+arr[start], required) + solve2(arr, start+1, sum, required);
}

int findTargetSumWays2(vector<int>& arr, int target) {
    int total_sum = accumulate(arr.begin(), arr.end(), 0);
    int required = (target + total_sum)/2;
    return solve2(arr, 0, 0, required);
}

int main(){
    vector<int> nums = {1,1,1,1,1};
    int target = 3;
    cout<<findTargetSumWays(nums, target);

    return 0;
}