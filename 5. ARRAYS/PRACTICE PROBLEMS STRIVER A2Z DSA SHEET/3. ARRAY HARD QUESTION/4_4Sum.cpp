/*

# 4_SUM


LINK:- https://leetcode.com/problems/4sum/description/


Example 1:
Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]

Example 2:
Input: nums = [2,2,2,2,2], target = 8
Output: [[2,2,2,2]]
*/


#include<bits/stdc++.h>
using namespace std;

//BRUTE FORCE (TC:- O(N^4 & SC:- O(2*no. of the quadruplets)))
vector<vector<int>> fourSum(vector<int>& nums, int target) {
        set<vector<int>> st;

        for(int i= 0; i<nums.size(); i++){
            for(int j = i+1; j<nums.size(); j++){
                for(int k = j+1; k<nums.size(); k++){
                    for(int l = k+1; l<nums.size(); l++){
                        if(nums[i] + nums[j] + nums[k] + nums[l] == target){
                            vector<int> temp = {nums[i] , nums[j] , nums[k] , nums[l]};
                            sort(temp.begin(), temp.end());
                            st.insert(temp);
                        }
                    }
                }
            }
        }

        vector<vector<int>> ans(st.begin(), st.end());

        return ans;
    }


//BETTER SOLUTION 
//Time Complexity: O(N^3*log(M)), where N = size of the array, M = no. of elements in the set.
//Space Complexity: O(2 * no. of the quadruplets)+O(N)
vector<vector<int>> fourSum1(vector<int>& nums, int target) {
        set<vector<int>> st;

        for(int i =0; i<nums.size(); i++){
            for(int j = i+1; j<nums.size(); j++){
                set<long long> hashset;
                for(int k = j+1; k<nums.size(); k++){
                long long sum = nums[i] + nums[j];
                sum += nums[k];
                long long fourth = target - sum;
                if(hashset.find(fourth) != hashset.end()){
                        vector<int> temp = {nums[i], nums[j], nums[k], (int)(fourth)};
                        sort(temp.begin(), temp.end());
                        st.insert(temp);
                    }
                    else{
                        hashset.insert(nums[k]);
                    }
                }
            }
        }
        
        vector<vector<int>> ans(st.begin(), st.end());

        return ans;
    }


//OPTIMAL SOLUTION
/*
# Time Complexity: O(N^3), where N = size of the array.
Reason: Each of the pointers i and j, is running for approximately N times. And both 
the pointers k and l combined can run for approximately N times including the operation of 
skipping duplicates. So the total time complexity will be O(N^3). 

# Space Complexity: O(no. of quadruplets), This space is only used to store the answer. 
We are not using any extra space to solve this problem. So, from that perspective, 
space complexity can be written as O(1).
*/
vector<vector<int>> fourSum2(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;

        for(int i = 0; i<nums.size(); i++){
            if(i>0 && nums[i] == nums[i-1]) continue;
            for(int j = i+1; j<nums.size(); j++){
                if(j>i+1 && nums[j] == nums[j-1]) continue;
                int k = j+1, l = nums.size()-1;
                while(k<l){
                    long long sum = nums[i] + nums[j];
                    sum += nums[k] + nums[l];
                    if(sum == target){
                        vector<int> temp ={nums[i], nums[j], nums[k], nums[l]};
                        ans.push_back(temp);
                        k++;
                        l--; 
                        while(k<l && nums[k] == nums[k-1]) k++;
                        while(k<l && nums[l] == nums[l+1]) l--;
                    }
                    else if(sum < target){
                        k++;
                    }
                    else{
                        l--;
                    }
                }
            }
        }

        return ans;
}


int main(){
    
    // vector<int> nums = {1,0,-1,0,-2,2};
    // int target = 0;

    vector<int> nums = {2,1,0,-1};
    int target = 2;

    // vector<int> nums = {1000000000,1000000000,1000000000,1000000000};
    // int target = 0;



    vector<vector<int>> ans = fourSum2(nums, target);

    for(auto i : ans){
        for(auto j : i){
            cout<<j<<", ";
        }cout<<endl;
    }

    return 0;
}