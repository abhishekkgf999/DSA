/*
#CHECK POWER OF TWO

LINK:- https://www.geeksforgeeks.org/problems/power-of-2-1587115620/1
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPowerofTwo(int n) {
        // Corrected expression
        return n > 0 && (n & (n - 1)) == 0;
    }
};

int main() {
    Solution obj;
    cout << obj.isPowerofTwo(4);
    return 0;
}