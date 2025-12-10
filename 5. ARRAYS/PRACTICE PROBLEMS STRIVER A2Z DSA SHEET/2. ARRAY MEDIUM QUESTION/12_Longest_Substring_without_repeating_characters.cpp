/*
#LONGEST SUBSTRING WITHOUT REPEATING CHARACTERS

LINK:- https://leetcode.com/problems/longest-substring-without-repeating-characters/    
*/


#include<bits/stdc++.h>
using namespace std;

//BRUTE FORCE (NOT RUN ALL THE TEST CASES)
//TIME COMPLEXITY:- O(N^3), SPACE COMPLEXITY:- O(1)
int lengthOfLongestSubstring0(string s) {
    int n = s.length();
    if(n<=1) return n;
    int maxi = 0;
    for(int i = 0; i < n; i++) {
        for(int j = i; j <n; j++) {
            bool unique = true;
            for(int k = i; k < j; k++) {
                if(s[k] == s[j]) {
                    unique = false;
                    break;
                }
            }
            if(unique)
                maxi = max(maxi, j - i + 1);
            else
                break;
        }
    }

    return maxi;
}


int lengthOfLongestSubstring(string s) {
        int n = s.length();
        if(n <= 1) return n;
        vector<int> freq(26);
        int r = 0, l = 0;
        int maxi = 0;
        while(r < n){
            if(s.at(r) >= 'a' && s.at(r) <= 'z'){
                freq[s[r]-'a']++;
            }
            if(freq[s[r] - 'a'] > 1) {
                maxi = max(maxi, r - l);
                freq = {0};
                freq[s[r]-'a']++;
                l = r;
            }
            r++;
        }
        return maxi;
}


int main(){
    string str = "pwwkew";
    cout<<"Length of maximum substring without repeating characters:- "<<lengthOfLongestSubstring0(str);
    return 0;
}