/*

#SUBARRAY WITH GIVEN XOR (SIMILAR TO PREFIX SUM IN LARGEST SUBARRAY PROBLEM)

LINK:- https://www.interviewbit.com/problems/subarray-with-given-xor/

OVERVIEW:-

Given an array of integers A and an integer B.

Find the total number of subarrays having bitwise XOR of all elements equals to B.


#Input 1:
 A = [4, 2, 2, 6, 4]
 B = 6

 Output 1:
 4

 Explanation 1:

 The subarrays having XOR of their elements as 6 are:
 [4, 2], [4, 2, 2, 6, 4], [2, 2, 6], [6]

*/



#include<bits/stdc++.h>
using namespace std;

//BRUTE FORCE SOLUTION (TC :- O(N^2) & SC :- O(1))
int solve(vector<int> nums, int n, int b){
    int max_subarrays = 0;
    for(int i =0; i<n; i++){
        int Xor = nums[i];
        if(Xor == b) max_subarrays++;
        for(int j = i+1; j<n; j++){
            Xor = Xor^nums[j];
            if(Xor == b) max_subarrays++;
        }    
    }

    return max_subarrays;
}


//OPTIMAL SOLUTION (TC:- O(N) -> in best case of unordered map, and O(N^2) -> in worst case of unordered map)
//If we use just map, then TC will be O(NlogN)
//SC:- O(N)
int solve2(vector<int> nums, int n, int b){
    int max_subarrays = 0; 

    unordered_map<long long, int> mpp;
    int Xor = 0;

    for(int i =0; i<n; i++){
        Xor = Xor^nums[i];
        if(Xor == b) max_subarrays++;

        int search = Xor^b;
        if(mpp.find(search) != mpp.end()){
            max_subarrays += mpp[search];
        }

        mpp[Xor]++;
    }

    return max_subarrays;
}


int main(){
    // vector<int> nums = {4, 2, 2, 6, 4};
    vector<int> nums = {5, 6, 7, 8, 9};

    int n = nums.size();

    // int b = 6;
    int b = 5;

    cout<<solve2(nums,n,b);
    
    return 0;
}