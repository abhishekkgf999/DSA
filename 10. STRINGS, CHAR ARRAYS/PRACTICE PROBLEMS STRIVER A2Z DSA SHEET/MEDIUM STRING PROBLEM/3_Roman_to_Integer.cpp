/*

#ROMAN TO INTEGER

LINK :- https://leetcode.com/problems/roman-to-integer/description/

*/

#include<bits/stdc++.h>
using namespace std;


//MY SOLUTION
int romanToInt(string s) {
        int ans = 0;
        
        unordered_map<char, int> hash = {{'I', 1}, {'V', 5},
                                        {'X', 10}, {'L', 50}, 
                                        {'C', 100}, {'D', 500}, 
                                        {'M', 1000}};

        for(int i = 0; i<s.size(); i++){
            int value = hash[s[i]];
            if(value == 1 || value == 10 || value == 100){
                int next = hash[s[i+1]];
                if(next > value){
                    ans += next-value;
                    i++;
                }
                else ans += value;
            }
            else ans += value;
            
        }

        return ans;
    }

//OPTIMAL_SOLUTION
/*
The for loop iterates over each character in the input string s.
For the example "IX":

When i is 0, the current character s[i] is 'I'. Since there is a next character ('X'), and the value of 'I' (1) is less 
than the value of 'X' (10), the condition m[s[i]] < m[s[i+1]] is true. In this case, we subtract the value of the current 
character from ans.

ans -= m[s[i]];
ans -= m['I'];
ans -= 1;
ans becomes -1.


When i is 1, the current character s[i] is 'X'. This is the last character in the string, so there is no next character
to compare. Since there is no next character, we don't need to evaluate the condition. In this case, we add the value of 
the current character to ans.

ans += m[s[i]];
ans += m['X'];
ans += 10;
ans becomes 9.
*/
int romanToInt_OPTIMAL_SOLUTION(string s) {
        unordered_map<char, int> m;
        
        m['I'] = 1;
        m['V'] = 5;
        m['X'] = 10;
        m['L'] = 50;
        m['C'] = 100;
        m['D'] = 500;
        m['M'] = 1000;
        
        int ans = 0;
        
        for(int i = 0; i < s.length(); i++){
            if(m[s[i]] < m[s[i+1]]){
                ans -= m[s[i]];
            }
            else{
                ans += m[s[i]];
            }
        }
        return ans;
    }


int main(){
    string s = "XIV";
    cout<<romanToInt_OPTIMAL_SOLUTION(s);
    return 0;
}