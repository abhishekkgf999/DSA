/*
#CHECK IF ARRAY IS SORTED AND ROTATED

LINK:- https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/description/
*/

#include<bits/stdc++.h>
using namespace std;

bool check(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        for(int i=1; i<n; i++){
            if(nums[i-1]>nums[i]){
                count++;
            }
        }
        if(nums[n-1]>nums[0]) count++;

        return count<=1;
    }


int main(){
    vector<int> nums;
    int n;
    cout<<"Enter the size of nums array:- "<<endl;
    cin>>n;
    cout<<"ENter the elements of nums array:- "<<endl;
    for(int i = 0; i<n; i++){
        int element;
        cin>>element;
        nums.push_back(element);
    }cout<<endl;

    if(check(nums)) {
        cout<<"True";
    }
    else cout<<"false";
    return 0;
}