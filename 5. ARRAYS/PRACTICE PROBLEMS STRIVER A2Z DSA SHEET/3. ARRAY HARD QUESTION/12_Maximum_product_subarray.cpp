/*

#MAXIMUM PRODUCT SUBARRAY

LINK:- https://leetcode.com/problems/maximum-product-subarray/description/

------------------------------------------------------------------------------------------

Given an integer array nums, find a subarray that has the largest product, and return the product.

The test cases are generated so that the answer will fit in a 32-bit integer.

nums = [2,3,-2,4]
Expected
6


nums = [-2,0,-1]
Expected
0

nums = [-3,-1,-1]
Expected
3

nums = [0,2]
Expected
2

nums = [3,-1,4]
Expected
4

*/



#include<bits/stdc++.h>
using namespace std;

//BRUTE FORCE SOLUTION (TC:- O(N^2) & SC:- O(1))
int maxProduct(vector<int>& nums) {
        int maxProduct = -9999;

        for(int i = 0; i<nums.size(); i++){
            int prod = nums[i];
            maxProduct = max(maxProduct, prod);
            for(int j = i+1; j<nums.size(); j++){
                prod *= nums[j];
                maxProduct = max(maxProduct, prod);
            }
        }

        return maxProduct;
    }

//OPTIMAL SOLUTION (TC:- O(N) & SC:- O(1))

/*

#Example:- nums = [3, 2, -1, 4, -6, 3, -2, 6]

=> In the given example, there is odd numbers of negatives, we have to remove one such that, prod comes to be max.

#POSSIBLE WAYS TO REMOVE ONE NEGATIVE NUMBER

CASE 1:- [3,2] -1 [4, -6, 3, -2, 6]
           ^            ^
           |            |
  prod:-   6           864


CASE 2:- [3, 2, -1, 4] -6 [3, -2, 6]
               ^              ^
               |              |
  prod:-      -24            -36

CASE 3:- [3, 2, -1, 4, -6, 3] -2 [6]
               ^                  ^
               |                  |
  prod:-      432                 6


As we can see, in case 1, we get the max. prod.

=> But how can we divide the array in two halves!

=> we dont need to divide the array into two halves, 

=> We have to simply calculate prod. from start to end (in forward direction), and end to start (in backward direction)
   we will definitely visit our disired array (having max prod.) either it is present from start or end.

=> In case of occurance of 0, we simply make our prod = 1, and move.

------------------------------------------------------------------------------------------------------------

=> Upon observation, we notice that each chosen negative number divides the array into two parts.

=> The answer will either be the prefix or the suffix of that negative number.

=> To find the answer, we will check all possible prefix subarrays (starting from index 0) and all 
   possible suffix subarrays (starting from index n-1).

=> The maximum product obtained from these prefix and suffix subarrays will be our final answer.

# If the array contains 0’s as well: We should never consider 0’s in our answer(as considering 0 will always result in 0) 
  and we want to obtain the maximum possible product. So, we will divide the given array based on the location of the 0’s and 
  apply the logic of case 3 for each subarray.

    => For example, the given array is: {-2, 3, 4, -1, 0, -2, 3, 1, 4, 0, 4, 6, -1, 4}.

    => In this case, we will divide the array into 3 different subarrays based on the 0’s locations. 
       So, the subarrays will be {-2, 3, 4, -1}, {-2, 3, 1, 4}, and {4, 6, -1, 4}.

    => In these 3 subarrays, we will apply the logic discussed in case 3. We will get 3 different answers for 3 different subarrays.

    => The maximum one among those 3 answers will be the final answer.

*/
int maxProduct1(vector<int>& nums) {
    int n = nums.size(); 

    int pre = 1, suff = 1;
    int ans = INT_MIN;
    for (int i = 0; i < n; i++) {
        if (pre == 0) pre = 1;
        if (suff == 0) suff = 1;
        pre *= nums[i];
        suff *= nums[n - i - 1];
        ans = max(ans, max(pre, suff));
    }
    return ans;

}

//MODIFIED KADANE'S ALGORITHM
//OPTIMAL SOLUTION 2 :- (TC:- O(N) & SC:- O(1))
int maxProduct2(vector<int> &nums){
     int prod1 = nums[0],prod2 = nums[0],result = nums[0];
    
    for(int i=1;i<nums.size();i++) {
        int temp = max({nums[i],prod1*nums[i],prod2*nums[i]});
        prod2 = min({nums[i],prod1*nums[i],prod2*nums[i]});
        prod1 = temp;
        
        result = max(result,prod1);
    }
    
    return result;
}

int main(){
    
    vector<int> nums = {3, -1, 4};

    cout<<maxProduct1(nums);

    return 0;
}