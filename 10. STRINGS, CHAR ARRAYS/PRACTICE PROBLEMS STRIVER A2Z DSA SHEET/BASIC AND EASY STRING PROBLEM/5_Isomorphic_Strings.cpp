/*

#ISOMORPHIC STRINGS (REVIEW THIS SECTION)

LINK:- https://leetcode.com/problems/isomorphic-strings/description/


DESCRIPTION :- Given two strings s and t, determine if they are isomorphic.

Two strings s and t are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving 
the order of characters. No two characters may map to the same character, but a character 
may map to itself.
*/


#include<bits/stdc++.h>
using namespace std;


//MY SOLUTION
bool isIsomorphic(string s, string t) {
        unordered_map<char, char> mpp1;
        unordered_map<char, char> mpp2;

        for(int i = 0; i<s.size(); i++){
            if(mpp1.find(s[i]) == mpp1.end()){
                mpp1[s[i]] = t[i];
            }
            else if(mpp1[s[i]] != t[i]){
                return false;
            }
        }

        for(int i = 0; i<t.size(); i++){
            if(mpp2.find(t[i]) == mpp2.end()){
                mpp2[t[i]] = s[i];
            }
            else if(mpp2[t[i]] != s[i]){
                return false;
            }
        }

        return true;
    }

//OPTIMAL SOLUTION
/*
The idea is that we need to map a char to another one, for example, "egg" and "add", we need to 
constract the mapping 'e' -> 'a' and 'g' -> 'd'. Instead of directly mapping 'e' to 'a', another 
way is to mark them with same value, for example, 'e' -> 1, 'a'-> 1, and 'g' -> 2, 'd' -> 2, this works same.

So we use two arrays here m1 and m2, initialized space is 256 (Since the whole ASCII size is 256, 128 also works here). 
Traverse the character of both s and t on the same position, if their mapping values in m1 and m2 are different, 
means they are not mapping correctly, returen false; else we construct the mapping, since m1 and m2 are both 
initialized as 0, we want to use a new value when i == 0, so i + 1 works here.

*/
bool isIsomorphic_optimalSolution(string s, string t) {
        int m1[256] = {0}, m2[256] = {0}, n = s.size();

        for(int i = 0; i<s.size(); i++){
            if(m1[s[i]] != m2[t[i]]) return false;
            m1[s[i]] = i+1;
            m2[t[i]] = i+1;
        }

        return true;
    }



int main(){
    // string s = "bbbaaaba";
    // string t = "aaabbbba";
    string s = "badc";
    string t = "baba";
    // string s = "PAPER";
    // string t = "TITLE";
    cout<<isIsomorphic(s,t);
    return 0;
}