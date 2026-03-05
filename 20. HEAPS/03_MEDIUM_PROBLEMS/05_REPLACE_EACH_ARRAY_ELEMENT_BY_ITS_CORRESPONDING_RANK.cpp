/*
#REPLACE EACH ARRAY ELEMENT BY ITS CORRESPONDING RANK

LINK:- https://leetcode.com/problems/rank-transform-of-an-array/description/
*/

#include<bits/stdc++.h>
using namespace std;


/*

💡 PROBLEM SUMMARY:
- Given an array of integers
- Replace each element with its rank
- Rank starts from 1
- Same values must get SAME rank
- Smaller value → smaller rank

====================================================
APPROACH: SORT + HASH MAP ⭐
----------------------------------------------------
IDEA:
- Agar array sorted hota, toh rank directly mil jata
- Original order preserve karna hai, isliye:
    ➜ Sorted copy banayenge
    ➜ Mapping se original array update karenge

----------------------------------------------------
STEPS:
1️⃣ Original array ki ek copy banao
2️⃣ Copy ko sort karo
3️⃣ Ek unordered_map banao (value → rank)
4️⃣ Rank variable start karo from 1
5️⃣ Sorted array traverse karo:
      ➜ Agar element map me nahi hai:
            assign current rank
            rank++
      ➜ Agar already present hai:
            skip (same value → same rank)
6️⃣ Ab original array traverse karo:
      ➜ Har element ko map se uska rank assign kar do

----------------------------------------------------
IMPORTANT POINT:
- Duplicate values ko same rank milta hai
- Rank sirf unique sorted elements ke liye increase hota hai


TIME COMPLEXITY:
➡ O(n log n)

SPACE COMPLEXITY:
➡ O(n)

*/


class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> copy = arr;
        int n = arr.size();
        sort(copy.begin(), copy.end());

        unordered_map<int, int> mpp;
        int r = 1;

        for(int i = 0; i<n; i++){
            if(mpp.find(copy[i]) == mpp.end()){
                mpp[copy[i]] = r++;
            }
        }

        for(int i = 0; i<n; i++){
            arr[i] = mpp[arr[i]];
        }

        return arr;
    }
};

int main(){
    
    return 0;
}