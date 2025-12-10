/*
#Move zeroes to the end

link:- https://leetcode.com/problems/move-zeroes/description/
*/

#include<bits/stdc++.h>
using namespace std;

//TIME COMPLEXITY :- O(N^2), SPACE COMPLEXITY:- O(1)
//FIRST COUNTING THE NUMBER OF ZEROES, AND THEN PERFORMING REQUIRED SWAPS
void moveZeroes1(vector<int>& nums) {
    int count =0;
    for(auto i : nums){
        if(i == 0) count++;
    }

    while(count--){
        for(int i=0; i<nums.size()-1;i++){
            if(nums[i] == 0){
                swap(nums[i], nums[i+1]);
            }
        }
    }    
}

//TIME COMPLEXITY :- O(N), SPACE COMPLEXITY:- O(1)
//FIRST POINTING TO OUR FIRST ZERO IN ARRAY, AND THEN SWAPPING IT WITH NON-ZERO ELEMENTS
void moveZeroes2(vector<int>& nums) {
    int i=0;
    // for(int j=0; j<nums.size(); j++){
    //     if(nums[j] == 0){
    //         i = j;
    //         break;            
    //     }
    // }
    for(;nums[i]!=0; i++);

    for(int j=i+1; j<nums.size(); j++){
        if(nums[j]!= 0){
            swap(nums[i++], nums[j]);
        }
    }       
}

//TIME COMPLEXITY:- O(N), SPACE COMPLEXITY:- O(1)
//FIRST FILLING WITH NON-ZERO ELEMETNS, AND REST WITH ZEROES
void moveZeroes3(vector<int> &nums){
    int i=0;
    for(int j=0; j<nums.size(); j++){
        if(nums[j]!=0){
            nums[i++] = nums[j]; 
        }
    }

    while(i<nums.size()){
        nums[i++] = 0;
    }

}


int main(){
     vector<int> arr = {1,0,0,3,12};
    moveZeroes3(arr);
    for(auto i : arr){
        cout<<i<<" ";
    }
    return 0;
}