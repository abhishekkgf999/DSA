/*

#LARGEST SUBARRAY WITH 0 SUM

LINK:- https://www.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1?category%5B%5D=Hash&company%5B%5D=Amazon&page=1&query=category%5B%5DHashcompany%5B%5DAmazonpage1company%5B%5DAmazoncategory%5B%5DHash

OVERVIEW!!

Examples:

Input: arr[] = {15,-2,2,-8,1,7,10,23}, n = 8
Output: 5
Explanation: The largest subarray with sum 0 is -2 2 -8 1 7.

Input: arr[] = {2,10,4}, n = 3
Output: 0
Explanation: There is no subarray with 0 sum.

Input: arr[] = {1, 0, -4, 3, 1, 0}, n = 6
Output: 5
Explanation: The subarray is 0 -4 3 1 0.

Expected Time Complexity: O(n).
Expected Auxiliary Space: O(n).

Constraints:
1 <= n <= 10^5
-1000 <= arr[i] <= 1000, for each valid i

*/


#include<bits/stdc++.h>
using namespace std;

//OPTIMAL SOLUTION :- (TC :- O(N) & SC:- O(N) -> in worst case, we insert all element in map)
int maxLen(vector<int>& arr, int n) {
        int max_len = 0;
        unordered_map<long long, int> mpp;

        long long sum = 0;

        for(int i = 0; i<n; i++){
            sum+= arr[i];
            if(sum == 0) max_len = i+1;

            if(mpp.find(sum) != mpp.end()){
                int len = i-mpp[sum];
                max_len = max(max_len, len);
            }

            if(mpp.find(sum) == mpp.end()){
                mpp[sum] = i;
            }
        }

        return max_len;
}

int main(){
    
    vector<int> arr = {15,-2,2,-8,1,7,10,23};
    int n = arr.size();

    cout<<"Length of maximum subarray with sum 0 is:- "<<maxLen(arr, n);

    return 0;
}