/*
#REVERSE WORDS IN STRINGS

LINK:- https://leetcode.com/problems/reverse-words-in-a-string/
*/

#include<bits/stdc++.h>
using namespace std;

string reverseWords(string s) {
        string ans;
        int start = 0, end = s.size() - 1;

    // Step 1: Trim leading and trailing spaces
        while (start <= end && s[start] == ' ') start++;
        while (end >= start && s[end] == ' ') end--;

        int temp_head = end;

    // Step 2: Traverse backwards and extract words
        while (temp_head >= start) {
            // Find the end of the current word
            while (temp_head >= start && s[temp_head] != ' ') temp_head--;
        
            // Append the word to the result
            ans += s.substr(temp_head + 1, end - temp_head) + ' ';

            // Skip spaces between words
            while (temp_head >= start && s[temp_head] == ' ') temp_head--;

            // Update end for the next word
            end = temp_head;
        }

    // Step 3: Remove the trailing space from the result
    if (!ans.empty() && ans.back() == ' ') ans.pop_back();

    return ans;
    }

int main(){
    string s = "  Hello   World  ";
    string ans = reverseWords(s);
    cout<<ans;
    return 0;
}