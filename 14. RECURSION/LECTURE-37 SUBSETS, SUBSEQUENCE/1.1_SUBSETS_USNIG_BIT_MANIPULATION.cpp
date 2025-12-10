/*
#SUBSETS    (USING BIT MANIPULATION)

LINK:- https://leetcode.com/problems/subsets/

*/

/*
1. Each number in the array can either be **included** or **not included** in a subset, which corresponds to a binary decision (0 or 1). This means that for an array of size `n`, there are \(2^n\) subsets.

2. Think of the binary representation of numbers from `0` to (2^n - 1). Each binary number can represent a subset:
   - If the `i`th bit of a binary number is `1`, include the element at index `i` in the subset.
   - If the `i`th bit is `0`, exclude the element at index `i`.

For example:
- For input `[1, 2, 3]`:
  - Binary `000` → subset: `[]`
  - Binary `001` → subset: `[3]`
  - Binary `010` → subset: `[2]`
  - Binary `011` → subset: `[2, 3]`
  - Binary `100` → subset: `[1]`
  - Binary `101` → subset: `[1, 3]`
  - Binary `110` → subset: `[1, 2]`
  - Binary `111` → subset: `[1, 2, 3]`

*/

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> subsets(vector<int>& nums) {
    int n = nums.size();
    int start = 0, end = pow(2, n)-1;
    vector<vector<int>> ans;
    for(int i = start; i<=end; i++){
        int num = i;
        if(num == 0) ans.push_back({});
        else{
            int count = n-1;
            vector<int> temp;
            while(num){
                if(num&1){
                    temp.push_back(nums[count]);
                }
                count--;
                num = num>>1;
            }
            reverse(temp.begin(), temp.end());
            ans.push_back(temp);
        } 
    } 

    return ans;
}


int main(){
    vector<int> nums = {1,2,3};
    vector<vector<int>> ans = subsets(nums);
    for(auto i : ans){
        for(auto j : i){
            cout<<j<<" ";
        }cout<<endl;
    }
    return 0;
}