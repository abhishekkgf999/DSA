/*

#SUM OF BEAUTY OF ALL SUBSTRING

LINK:- https://leetcode.com/problems/sum-of-beauty-of-all-substrings/description/

*/

#include<bits/stdc++.h>
using namespace std;

//BRUTE FORCE SOLUTION
int beautySum(string s) {
    int ans = 0;
    for (int i = 0; i < s.size(); i++) {
        vector<int> mpp(26, 0);
        for (int j = i; j < s.size(); j++) {
            mpp[s[j] - 'a']++;
           
            int mf = INT_MIN, lf = INT_MAX;
            for (int k = 0; k < 26; k++) {
                if (mpp[k] > 0) { 
                    mf = max(mf, mpp[k]);
                    lf = min(lf, mpp[k]);
                }
            }

            ans += (mf - lf);
        }
    }
    return ans;
}

int main(){
    string s = "aabcbaa";
    cout<<beautySum(s);
    return 0;
}