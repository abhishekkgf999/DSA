/*

#ROTATE STRING

LINK:- https://leetcode.com/problems/rotate-string/description/

*/

#include<bits/stdc++.h>
using namespace std;

//MY SOLUTION
bool rotateString(string s, string goal) {
        string temp = s;
        int n = s.size();

        for(int i = 0; i<n; i++){
            reverse(temp.begin(), temp.end());
            reverse(temp.begin(), temp.begin()+n-1);

            if(temp == goal) return true;
        }

        return false;
    }

//OPTIMAL SLOUTION
/*
We can easily see whether it is rotated if B can be found in (A + A).
For example, with A = "abcde", B = "cdeab", we have

“abcdeabcde” (A + A)
  “cdeab” (B)

  B is found in (A + A), so B is a rotated string of A.

The 'shift' operation can be regarded as a 'sliding' operation on A+A.
For example, A = “abcde”, B = “cdeab”，A+A="abcdeabcde".
We use a sliding window of size len(A) to 'slide' on A+A from left to right.Every sliding takes 1 step.
At the beginning, we are in the leftmost, the sliding window is 'abcde'.
After the first sliding, we get 'bcdea'(A shifts once).
After the second sliding, we get 'cdeab'(A shifts twice).
...
Until to the rightmost, we get 'abcde'
So if A can become B after serveral shifts, B must be a result we get above. So B must be a substring of A+A
*/
/*
=> string::npos
To put it simply, think of npos as no-position. As a return value, it is usually used to indicate that no 
matches were found in the string. Thus, if it returns true, matches were found at no positions (i.e., no matches).
*/
bool rotateString_optimalSolution(string s, string goal) {
        return s.size() == goal.size() && (s+s).find(goal) != string::npos;
    }

int main(){
    string s = "abcde";
    string goal = "cdeab";
    cout<<rotateString(s, goal)<<endl;
    cout<<rotateString_optimalSolution(s, goal);
    return 0;
}