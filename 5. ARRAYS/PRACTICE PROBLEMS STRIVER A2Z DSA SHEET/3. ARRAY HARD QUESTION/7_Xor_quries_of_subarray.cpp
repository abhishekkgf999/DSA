/*

#XOR queries of subarray

LINK:- https://leetcode.com/problems/xor-queries-of-a-subarray/description/

*/


#include<bits/stdc++.h>
using namespace std;

//BRUTE FORCE SOLUTION (TC:- O(N^2) & SC:- O(1))
vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {

    vector<int> ans;

    int n = queries.size();

    for(int i = 0; i<n; i++){
        int XOR = 0;
        for(int j = queries[i][0]; j<= queries[i][1]; j++){
            XOR = XOR^arr[j];
        }
        ans.push_back(XOR);
    }

    return ans;
}

//OPTIMAL SOLUTION (TC:- O(N) & SC:- O(2*N))
vector<int> xorQueries1(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> ans;

        unordered_map<long long, int> mpp;
        int XOR = 0;

        for(int i = 0; i<arr.size(); i++){
            XOR = XOR^arr[i];
            mpp[i] = XOR;
        }

        int n = queries.size();

        for(int i=0; i<n; i++){
            int right = queries[i][1];
            int left = queries[i][0];
            if(left > 0){
                int value = mpp[right]^mpp[left-1];
                ans.push_back(value);
                }
            else{
                int value = mpp[right];   
                ans.push_back(value);
                }
            }

        return ans;

    }


int main(){
    
    vector<int> arr = {1,3,4,8};

    vector<vector<int>> queries = {{0,1} , {1,2}, {0,3}, {3,3}};

    vector<int> ans = xorQueries(arr, queries);

    for(auto i : ans){
        cout<<i<<" ";
    }

    return 0;
}