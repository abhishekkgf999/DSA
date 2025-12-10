/*
#PHONE KEYPAD PROBLEM

LINK:- https://www.youtube.com/watch?v=tWnHbSHwNmA&list=PLDzeHZWIZsTryvtXdMr6rPh4IDexB5NIA&index=43

*/

#include<bits/stdc++.h>
using namespace std;

void solve(string digits, string mapping[], int index, vector<string> &ans, string output) {
    // Base Case: If we've processed all digits, add the current combination to the answer
    if(index >= digits.size()){
        if(output != "") ans.push_back(output); // Only add non-empty strings
        return;
    }
    
    // Get the current digit a an integer
    int i = digits[index] - '0';

    // Iterate over all characters mapped to the current digit
    for(char ch : mapping[i]){
        // Add the current character to the output
        output = output + ch;

        // Recursive Call: Move to the next digit
        solve(digits, mapping, index + 1, ans, output);

        // Note: If we used a reference for `output`, we would remove the last added character 
        output.pop_back();
    }
}

vector<string> letterCombinations(string digits) {
    // To store the final list of combinations
    vector<string> ans;

    // To store the temporary combination in progress
    string output;

    // Starting index for the input digits
    int index = 0;

    // Mapping of digits to corresponding letters as per the phone keypad
    string mapping[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    // If the input string is empty, directly return an empty list
    if (digits.empty()) return ans;

    // Start solving recursively
    solve(digits, mapping, index, ans, output);

    // Return the list of all combinations
    return ans;
}

int main(){
    string digits = "23";
    vector<string> ans = letterCombinations(digits);
    for(auto ch : ans){
        cout<<ch<<", ";
    }
    return 0;
}