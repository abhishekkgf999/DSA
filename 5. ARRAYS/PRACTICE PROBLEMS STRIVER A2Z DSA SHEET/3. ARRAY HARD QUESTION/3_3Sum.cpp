/*

#3SUM

LINK:- https://leetcode.com/problems/3sum/description/

-----------------------------------------------------------------------------------------

Example 1:
Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Explanation: 
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
The distinct triplets are [-1,0,1] and [-1,-1,2].

Notice that the order of the output and the order of the triplets does not matter.

Example 2:
Input: nums = [0,1,1]
Output: []
Explanation: The only possible triplet does not sum up to 0.

Example 3:
Input: nums = [0,0,0]
Output: [[0,0,0]]
Explanation: The only possible triplet sums up to 0.

*/



#include<bits/stdc++.h>
using namespace std;

//BRUTE FORCE SOLUTION (TC:- O(N^3) AND SC:- O(N^2))
/*
#Time Complexity: O(N3 * log(no. of unique triplets)), where N = size of the array.
#Reason: Here, we are mainly using 3 nested loops. And inserting triplets into the set 
         takes O(log(no. of unique triplets)) time complexity. But we are not considering 
         the time complexity of sorting as we are just sorting 3 elements every time.

#Space Complexity: O(2 * no. of the unique triplets) as we are using a set data structure 
                   and a list to store the triplets.
*/
vector<vector<int>> threeSum(int n, vector<int> &arr) {
    set<vector<int>> st;

    // check all possible triplets:
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                if (arr[i] + arr[j] + arr[k] == 0) {
                    vector<int> temp = {arr[i], arr[j], arr[k]};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
            }
        }
    }

    //store the set elements in the answer:
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}

//MY SOLUTION (TRYING TO GET O(N^2) TC, BUT CAN'T GET IT)
// vector<vector<int>> threeSum1(vector<int>& nums) {
//     map<int, pair<int,int>> mpp;
//     set<vector<int>> st;

//     for(int i = 0; i<nums.size(); i++){
//         for(int j = i+1; j<nums.size(); j++){
//             int sum = nums[i] + nums[j];
//             pair<int,int> p(nums[i],nums[j]);
//             mpp[sum] = p;
//         }
//     }

//     for(int i = 0; i<nums.size(); i++){
//         int target = -nums[i];
//         for(auto it : mpp){
//             if(it.first == target){
//                 pair<int,int> p(it.second);
//                 vector<int> temp = {nums[i], p.first, p.second};
//                 sort(temp.begin(), temp.end());
//                 st.insert(temp);
//             }
//         }
//     }

//     for(auto it:mpp){
//         pair<int, int> p(it.second);
//         cout<<"Sum :- "<<it.first<<" "<<"Value:- "<<p.first<<" "<<p.second<<endl;
//     }

//     vector<vector<int>> ans(st.begin(), st.end());
//     return ans;

// }


//BETTER SOLUTION (TC :- O(N^2 * LOG(no. of unique triplets)) & SC :- O(2*N) + O(N))
/*
#Time Complexity: O(N2 * log(no. of unique triplets)), where N = size of the array.
#Reason: Here, we are mainly using 3 nested loops. And inserting triplets into the set 
         takes O(log(no. of unique triplets)) time complexity. But we are not considering 
         the time complexity of sorting as we are just sorting 3 elements every time.

#Space Complexity: O(2 * no. of the unique triplets) + O(N) as we are using a set data 
                   structure and a list to store the triplets and extra O(N) for storing 
                   the array elements in another set.
*/
/*
#The steps are as follows:

-> First, we will declare a set data structure as we want unique triplets.

-> Then we will use the first loop(say i) that will run from 0 to n-1.

-> Inside it, there will be the second loop(say j) that will run from i+1 to n-1.

-> Before the second loop, we will declare another HashSet to store the array elements as we 
   intend to search for the third element using this HashSet.

-> Inside the second loop, we will calculate the value of the third element i.e. -(arr[i]+arr[j]).

-> If the third element exists in the HashSet, we will sort these 3 values i.e. arr[i], arr[j], 
   and the third element, and insert it in the set data structure declared in step 1.

-> After that, we will insert the j-th element i.e. arr[j] in the HashSet as we only want to insert 
   those array elements that are in between indices i and j.

-> Finally, we will return a list of triplets stored in the set data structure.

# Why we are not inserting all the array elements in the HashSet and then searching for the third element:

=>  Let’s understand this intuition using an example. Assume the given array is {1, 2, -1, -2, 4, 0, -1} and 
    the target = 0. Now, we will notice a situation like the following:


=>  Here, arr[i] = -2 and arr[j] = 4.
=>  Therefore, arr[k] = -(arr[i]+arr[j]) = -(-2+4) = -2

=>  If all the elements were in the set data structure while searching for -2, we would again pick the 
    element at index 3, that is currently pointed by i.

=>  Hence, the triplet will be [arr[i], arr[j], arr[i]]. And this is an invalid triplet. That is why we 
    cannot insert all the elements into the set data structure.
*/
vector<vector<int>> threeSum1(vector<int>& nums) {

        set<vector<int>> st;

        for(int i = 0; i<nums.size(); i++){
            set<int> hashset;
            for(int j = i+1; j<nums.size(); j++){
                int k = -(nums[i] + nums[j]);
                if(hashset.find(k) != hashset.end()){
                    vector<int> temp = {nums[i], nums[j], k};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
                else{
                    hashset.insert(nums[j]);
                }
            }
        }

        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
}

//OPTIMAL SOLUTION (Time Complexity: O(NlogN)+O(N^2) & Space Complexity: O(no. of quadruplets) We are not using any extra space to   solve this problem. So, from that perspective, space complexity can be written as O(1).)
/*
# In this approach, we intend to get rid of two things i.e. the HashSet we were 
  using for the look-up operation and the set data structure used to store the unique triplets.

# So, We will first sort the array. Then, we will fix a pointer i, and the rest 2 pointers j and k will be moving. 

# Now, we need to first understand what the HashSet and the set were doing to make our algorithm 
  work without them. So, the set data structure was basically storing the unique triplets in sorted 
  order and the HashSet was used to search for the third element.

# That is why, we will first sort the entire array, and then to get the unique triplets, we will simply 
  skip the duplicate numbers while moving the pointers.

# How to skip duplicate numbers:
-> As the entire array is sorted, the duplicate numbers will be in consecutive places. So, while moving a pointer, 
   we will check the current element and the adjacent element. Until they become different, we will move the pointer 
   by 1 place. We will follow this process for all 3 pointers. Thus, we can easily skip the duplicate elements while 
   moving the pointers.

# Now, we can also remove the HashSet as we have two moving pointers i.e. j and k that will find the appropriate 
  value of arr[j] and arr[k]. So, we do not need that HashSet anymore for the look-up operations.
*/
vector<vector<int>> threeSum2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;

        for(int i = 0; i<nums.size(); i++){
            if(i>0 && nums[i] == nums[i-1]) continue;
            int j = i + 1, k = nums.size()-1;
            while(j<k){
                int sum = nums[i] + nums[j] + nums[k];
                if(sum == 0){
                    vector<int> temp = {nums[i] , nums[j] , nums[k]};
                    ans.push_back(temp);
                    j++;
                    k--;
                    while(j<k && nums[j] == nums[j-1]) j++;
                    while(j<k && nums[k] == nums[k+1]) k--;
                }
                else if(sum < 0){
                    j++;
                }
                else{
                    k--;
                }
            }
        }

        return ans;       
}

int main(){
    
    // vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<int> nums = {-2,0,1,1,2};

    int n = nums.size();

    vector<vector<int>> ans = threeSum2(nums);

    for(int i = 0; i<ans.size(); i++){
        for(int j = 0; j<ans[0].size(); j++){
            cout<<ans[i][j]<<", ";
        }cout<<endl;
    }

    return 0;
}