/*
#Check if the array is sorted

link:- https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/description/

*/

#include<bits/stdc++.h>
using namespace std;

//TIME COMPLEXITY WILL BE:- O(N), SPACE COMPLEXITY WILL BE:- O(1)
bool check(vector<int>& nums) {
        int count = 0;
        for(int i=1; i<nums.size(); i++){
            if(nums[i-1]>nums[i]){
                count++;
            }
        }
        if(nums[nums.size()-1] > nums[0]) count++;
        return count<=1;
    }

int main(){
     vector<int> arr;
    cout<<"Enter the size of array:- ";
    int size;
    cin>>size;
    cout<<"Enter the elements in array:- ";
    for(int i=0; i<size; i++){
        int element;
        cin>>element;
        arr.push_back(element);
    }
    if(check(arr)){
        cout<<"Either array is sorted or rotated";
    }
    else{
        cout<<"Array is sorted and rotated both";
    }
    return 0;
}