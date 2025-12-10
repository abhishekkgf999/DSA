/*
MOVE ZEROES

LINK:- https://leetcode.com/problems/move-zeroes/description/
*/

#include<bits/stdc++.h>
using namespace std;

//#Love babbar approach (METHOD-0)  
void moveZeroes(vector<int>& nums) {
        int i=0;
        for(int j=0; j<nums.size(); j++){
            if(nums[j]!=0){
                swap(nums[j], nums[i]);
                i++;
            }
        }
    }

//#snowball method (METHOD-1) 
void moveZeroes1(vector<int>& nums) {
    int snowBall = 0;
    for(int i=0; i<nums.size(); i++){
        if(nums[i]==0){
            snowBall++;
        }
        else if(snowBall>0){
            int temp = nums[i];
            nums[i] = 0;
            nums[i-snowBall] = temp;
        }
    }
}  

//#moving zeroes to the end (METHOD-2) --> at each iteration, only 1 zero is move at end
void moveZeroes2(vector<int>& nums) {
        int count = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==0) count++;
        }
        while(count--){
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==0 && i+1<nums.size()){
                swap(nums[i], nums[i+1]);
            }
        }
        }
    }

//#filling starting element with non-zero element, and then filling ending elements with 0 (METHOD-3)
void moveZeroes3(vector<int>& nums) {
        int j=0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]!=0){
                nums[j++] = nums[i];
            }
        }
        for(; j<nums.size(); j++){
            nums[j]=0;
        }
    }



int main(){
    vector<int> nums; 
    int m;
    cout<<"Enter the size of array 1:- ";
    cin>>m;
    cout<<"Enter the elements of array 1:- "<<endl;
    for(int i=0; i<m; i++){
        int element;
        cin>>element;
        nums.push_back(element);
    }
   

    cout<<"After moving zeroes:- ";
    moveZeroes(nums);
    for(int i : nums){
        cout<<i<<" ";
    }

    return 0;
}