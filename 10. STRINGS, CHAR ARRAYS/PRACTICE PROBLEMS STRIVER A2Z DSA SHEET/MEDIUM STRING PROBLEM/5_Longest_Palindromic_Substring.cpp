/*

#LONGEST PALINDROMIC SUBSTRING (REVIEW)

LINK:- https://leetcode.com/problems/longest-palindromic-substring/description/

*/

#include<bits/stdc++.h>
using namespace std;

//MY SOLUITON (GIVING MEMORY LIMIT EXCEED) (TC:- O(n^3))
bool isPalindrome(int start, int end, string s){
    while(start <= end){
        if(s[start++] != s[end--]){
            return false;
        }
    }
    return true;
}

string longestPalindrome(string s) {
        int start = -1;
        int maxlen = 0;
        for(int i = 0; i<s.size(); i++){
            for(int j = i; j<s.size(); j++){
                if(isPalindrome(i, j, s)){
                    int len = j-i+1;
                    if(len > maxlen){
                        maxlen = len;
                        start = i;
                    }
                }
            }
        }

        return s.substr(start, maxlen);
    }

//APPROACH - 2 (EXPAND AROUND CENTER) (TC:- O(n^2) & SC :- O(1))
/*
Intuition :
To enumerate all palindromic substrings of a given string, we first expand a given string at each 
possible starting position of a palindrome and also at each possible ending position of a palindrome 
and keep track of the length of the longest palindrome we found so far.

Approach :
1.  We observe that a palindrome mirrors around its center. Therefore, a palindrome can be expanded from 
    its center, and there are only 2n - 1 such centers.

2.  You might be asking why there are 2n - 1 but not n centers? The reason is the center of a palindrome 
    can be in between two letters. Such palindromes have even number of letters (such as "abba") and its 
    center are between the two 'b's.'

3.  Since expanding a palindrome around its center could take O(n) time, the overall complexity is O(n^2).
*/
string longestPalindrome_ExpandAroundCenter(string s) {
        if(s.size() <= 1) return s;

        //Lambda function (Helper function)
        auto expand_from_center = [&](int left, int right){
            while(left >= 0 && right <s.length() && s[left] == s[right]){
                left--;
                right++;
            }
            return s.substr(left+1, right-left-1);
        };

        string max_str = s.substr(0,1);

        for(int i = 0; i<s.length(); i++){
            string odd = expand_from_center(i, i);
            string even = expand_from_center(i, i+1);

            if(odd.length() > max_str.length()){
                max_str = odd;
            }
            if(even.length() > max_str.length()){
                max_str = even;
            }
        }

        return max_str;
    }

int main(){
    return 0;
}