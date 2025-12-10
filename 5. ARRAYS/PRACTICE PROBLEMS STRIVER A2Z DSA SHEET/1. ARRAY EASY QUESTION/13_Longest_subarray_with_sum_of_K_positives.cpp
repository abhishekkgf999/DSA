/*
                        ***Mark for revision***

#Longest subarray with given sum K(POSITIVE & NEGATIVE)

#IMPORTANT QUESTION
READ THIS:- https://takeuforward.org/data-structure/longest-subarray-with-given-sum-k/

Link:- https://www.codingninjas.com/studio/problems/longest-subarray-with-sum-k_6682399
*/

#include <bits/stdc++.h>
using namespace std;

//TIME COMPLEXITY:- O(N^3), SPACE COMPLEXITY:- O(1)
int longestSubarrayWithSumK0(vector<int> a, long long k){
     int max_subarr = 0;
     int n = a.size();
     for(int i=0; i<n ; i++){
        for(int j = i; j<n; j++){
            int temp_subarr = 0;
            long long sum =0;
            for(int k = i; k<=j; k++){
                sum += a[k];  
            }
            if(sum == k) max_subarr = max(max_subarr, j-i+1);
        }
     }
     return max_subarr;
}

//TIME COMPLEXITY:- O(N^2), SPACE COMPLEXITY:- O(1)
int longestSubarrayWithSumK1(vector<int> a, long long k){
     int max_subarr = 0;
     for(int i=0; i<a.size(); i++){
        long long temp_sum = 0;
        for(int j=i; j<a.size(); j++){
            temp_sum += a[j];
            if(temp_sum == k) {
                max_subarr = max(max_subarr, j-i+1);
            }
        }
    }    
    return max_subarr;
}

//PREFIX-SUM APPROACH (THIS WILL RUN ONLY FOR POSITIVE NUMBERS)
//TIME COMPLEXITY:- IF WE USE MAP O(N*log(N)), IF WE USE UNORDERED MAP CASE1:- THERE IS NO COLLISION O(N*1), CASE2:- THERE IS COLLISION O(N*N)

int longestSubarrayWithSumK2(vector<int> a, long long k){
     int maxLen = 0;
     map<long long, int> preSumMap;
     long long sum = 0;
     for(int i=0; i<a.size(); i++){
        sum += a[i];
        if(sum == k) maxLen = max(maxLen, i+1);
        long long rem = sum-k;
        if(preSumMap.find(rem) != preSumMap.end()){
            int len = i - preSumMap[rem];
            maxLen = max(maxLen, len);
        }

        preSumMap[sum] = i;
     }
     return maxLen;
}

//PREFIX-SUM APPROACH (THIS WILL RUN FOR POSITIVE AND NEGATIVE BOTH)
//TIME COMPLEXITY:- IF WE USE MAP O(N*log(N)), IF WE USE UNORDERED MAP CASE1:- THERE IS NO COLLISION O(N*1), CASE2:- THERE IS COLLISION O(N*N)
int longestSubarrayWithSumK3(vector<int> a, long long k){
     int maxLen = 0;
     map<long long, int> preSumMap;
     long long sum = 0;
     for(int i=0; i<a.size(); i++){
        sum += a[i];
        if(sum == k) maxLen = max(maxLen, i+1);
        long long rem = sum-k;
        if(preSumMap.find(rem) != preSumMap.end()){ //!= preSumMap.end(): The result of preSumMap.find(rem) is then compared with preSumMap.end(). If the iterator returned by find is not equal to end(), it means the key was found in the map.
            int len = i - preSumMap[rem];
            maxLen = max(maxLen, len);
        }
        if(preSumMap.find(sum) == preSumMap.end()){
        preSumMap[sum] = i;
        }
     }
     return maxLen;
}


//TIME COMPLEXITY:- O(2N), SPACE COMPLEXITY:- O(1)
int longestSubarrayWithSumK4(vector<int> a, long long k){
    int left = 0, right = 0;
    long long sum = a[0]; 
    int max_len = 0;
    int n = a.size();
    while(right < n){
        while(left<=right && sum >k){
            sum -= a[left];
            left++;
        }
        if(sum == k){
            max_len = max(max_len, right-left+1);
        }
        right++;
        if(right <n) sum+= a[right]; 
    }
    return max_len;
}

int main(){
    // vector<int> arr = {8, 15, 17, 0, 11};
    // vector<int> arr = {1,2,3,1,1,1,1};
    vector<int> arr = {2,0,0,0,3};

    long long k = 3;
    // long long k = 17;

    cout << "Longest subarray with sum k= " << k << " is " << longestSubarrayWithSumK1(arr, k);
    return 0;
}