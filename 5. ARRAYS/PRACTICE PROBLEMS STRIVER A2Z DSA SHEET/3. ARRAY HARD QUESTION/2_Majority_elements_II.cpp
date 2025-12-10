/*

#MAJORITY ELEMENTS II

LINK:- https://leetcode.com/problems/majority-element-ii/description/

#OVERVIEW:-

Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

Example 1:
Input: nums = [3,2,3]
Output: [3]

Example 2:
Input: nums = [1]
Output: [1]

Example 3:
Input: nums = [1,2]
Output: [1,2]
*/


#include<bits/stdc++.h>
using namespace std;

// BRUTE FORCE (TC :- O(N^2) & SC :- O(N))
vector<int> majorityElement(vector<int>& nums) {

        set<int> temp;
        int k = nums.size()/3;

        for(int i = 0; i<nums.size(); i++){
            int ele = nums[i];
            int count = 0;
            for(int j = i; j<nums.size(); j++){
                if(ele == nums[j]){
                    count++;
                }
            }
            if(count>k) temp.insert(ele);
        }

        vector<int> ans(temp.begin(), temp.end());
        return ans;
}

//LITTLE OPTIMIZATION (TC :- O(N) & SC :- O(N))
vector<int> majorityElement1(vector<int>& nums) {
        int k = nums.size()/3;
        vector<int> ans;

        unordered_map<int, int> mpp;

        for(auto i : nums){
            mpp[i]++;
        }

        for(auto it : mpp){
            if(it.second > k){
                ans.push_back(it.first);
            }
        }

        return ans;
}

//USING SORTED ARRAY (TC:- O(NlogN) AND SC :- O(1))
vector<int> majorityElement2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> ans;
        int k = nums.size()/3;
        int count = 1;
        int i = 1;
        for( ; i<nums.size(); i++){
            if(nums[i] == nums[i-1]){
                count++;
            }
            else{
                if(count>k){
                    ans.push_back(nums[i-1]);
                }
                count = 1;
            }
        }

        if(count>k){
            ans.push_back(nums[i-1]);
        }

        return ans;
}

//HASHING OPTIMISED SOLUTION (TC:- O(N) & SC :- O(N) -> in worst case)
/*
=> Use a hashmap and store the elements as <key, value> pairs. 
   (Can also use frequency array based on the size of nums).

   Here the key will be the element of the array and the value will be 
   the number of times it occurs. 


=> Traverse the whole array and update the occurrence of each element. 
=> After that, check the map if the value for any element is greater than the floor of N/3. 
    -> If yes, include it in the list. 
    -> Else iterate forward.

Finally, return the list.
*/
vector<int> majorityElement3(vector<int> &nums){
    int n = nums.size();

    vector<int> ans;

    unordered_map<int, int> mpp;

    int mini = int(n/3) + 1;

    for(int i = 0; i<n; i++){
        mpp[nums[i]]++;

        if(mpp[nums[i]] == mini){
            ans.push_back(nums[i]);
        }

        if(ans.size() == 2) break;
    }

    return ans;
}

//OPTIMIZED SOLUTION  (TC :- O(N) & SC :- O(1))
//BOYER-MOORE'S VOTING ALGORITHM
/*
#Intuition: If the array contains the majority of elements, their occurrence must be 
            greater than the floor(N/3). Now, we can say that the count of minority 
            elements and majority elements is equal up to a certain point in the array. 
            So when we traverse through the array we try to keep track of the counts of 
            elements and the elements themselves for which we are tracking the counts. 

After traversing the whole array, we will check the elements stored in the variables. 
Then we need to check if the stored elements are the majority elements or not by manually 
checking their counts.

#Edge Case: Why we are adding extra checks like el2 != v[i] and el1 != v[i] in the first if statements?

So, to avoid this edge case, we are checking if the current element is already included in our elements, 
and if it is, we will not again include it in another variable.

-------------------------------------------------------------------------------------------------------

#Approach:

1. Initialize 4 variables:
    -> cnt1 & cnt2 –  for tracking the counts of elements
    -> el1 & el2 – for storing the majority of elements.

2. Traverse through the given array.
    -> If cnt1 is 0 and the current element is not el2 then store the current element of 
       the array as el1 along with increasing the cnt1 value by 1.
    -> If cnt2 is 0 and the current element is not el1 then store the current element of 
       the array as el2 along with increasing the cnt2 value by 1.
    -> If the current element and el1 are the same increase the cnt1 by 1.
    -> If the current element and el2 are the same increase the cnt2 by 1.
    -> Other than all the above cases: decrease cnt1 and cnt2 by 1.

3. The integers present in el1 & el2 should be the result we are expecting. So, using another 
   loop, we will manually check their counts if they are greater than the floor(N/3).


***THINK LIKE:- Rahul and Modi as ele1 and ele2, and whenever we encounter different element
                it will decrease popularity of both (Rahul and Modi).

                If any of there popularity becomes zero, we choose the new candidate (nums[i])

                But we ensure that past candidates doesn't take new candidate position, it must be unique

                At last, when we got our candidates, then we just check a pass, whether any of them make 
                there government or not (by having count > n/3)

                If yes, then we select that candidate as our answer

                There can be 2 or less than 2 candidates only.

*/

vector<int> majorityElement4(vector<int> &nums){
    vector<int> ans;

    int cnt1 = 0, ele1 = INT32_MIN;
    int cnt2 = 0, ele2 = INT32_MIN;

    for(int i = 0; i<nums.size(); i++){
        if(cnt1 == 0 && nums[i] != ele2){
            ele1 = nums[i];
            cnt1 = 1;
        }
        else if(cnt2 == 0 && nums[i] != ele1){
            ele2 = nums[i];
            cnt2 = 1;
        }
        else if(nums[i] == ele1) cnt1++;
        else if(nums[i] == ele2) cnt2++;
        else{
            cnt1--;
            cnt2--;
        }
    }

    cnt1 = 0 , cnt2 = 0;
    for(int i = 0; i<nums.size(); i++){
        if(nums[i] == ele1) cnt1++;
        if(nums[i] == ele2) cnt2++;
    }

    int n = nums.size();

    int mini = int(n/3) +1;
    if(cnt1 >= mini) ans.push_back(ele1);
    if(cnt2 >= mini) ans.push_back(ele2);

    return ans;
}

int main(){
    // vector<int> nums = {2,2};

    // vector<int> nums = {3,1,3};
    // vector<int> nums = {3,3,1};
    // vector<int> nums = {1,2,3};
    // vector<int> nums = {4,1,3,1,3,3,1,2,3,2,4,2,1,4,4,4,4,4};
    // vector<int> nums = {2,2};
    vector<int> nums = {3,3,4};

    vector<int> ans = majorityElement3(nums);

    for(auto it : ans){
        cout<<it<<" ";
    }

    return 0;
}