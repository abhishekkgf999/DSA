/*
#COUNT NUMBERS OF BIT TO BE FLIPPED TO CONVERT A TO B


LINK:- https://leetcode.com/problems/minimum-bit-flips-to-convert-number/description/

*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minBitFlips(int start, int goal) {
        int n = start ^ goal;    //XOR HIGHLIGTHS DIFFERING BITS
        int count = 0;
        while (n) {
            n = n & (n - 1); //THIS PROCESS REMOVES LAST SET BIT
            count++;
        }
        return count;
    }
};

int main() {
    Solution sol;

    int start1 = 10, goal1 = 7;
    int result1 = sol.minBitFlips(start1, goal1);
    cout << "To convert " << start1 << " to " << goal1 << ", " << result1 << " bits need to be flipped." << endl;

    int start2 = 3, goal2 = 4;
    int result2 = sol.minBitFlips(start2, goal2);
    cout << "To convert " << start2 << " to " << goal2 << ", " << result2 << " bits need to be flipped." << endl;

    int start3 = 6, goal3 = 6;
    int result3 = sol.minBitFlips(start3, goal3);
    cout << "To convert " << start3 << " to " << goal3 << ", " << result3 << " bits need to be flipped." << endl;

    return 0;
}