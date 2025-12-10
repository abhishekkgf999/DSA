/*

#VALID ANAGRAM

LINK:- https://leetcode.com/problems/valid-anagram/description/


----------------------------------------------------------------------------------------

# Anagram
An anagram is a word or phrase formed by rearranging the letters of a different word or phrase, 
using all the original letters exactly once.
*/

#include<bits/stdc++.h>
using namespace std;

//MY SOLUTION (TC:- o(N), SC:- O(26))
bool isAnagram(string s, string t) {
        int n1 = s.size();
        int n2 = t.size();

        if(n1 != n2) return false;

        vector<int> freq1(26, 0);
        vector<int> freq2(26, 0);

        for(int i = 0; i<s.size(); i++){
            freq1[s[i]-'a']++;
            freq2[t[i]-'a']++;
        }

        for(int i = 0; i<26; i++){
            if(freq1[i] != freq2[i]) return false;
        }

        return true;
    }

//OPTIMAL SOLUTION (TC:- O(nlogn), SC:- O(1))
bool isAnagram_OPTIMAL_SOLUTION(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }

int main(){
    string s = "anagram", t = "nagaram";
    cout<<isAnagram(s,t)<<endl;
    return 0;
}