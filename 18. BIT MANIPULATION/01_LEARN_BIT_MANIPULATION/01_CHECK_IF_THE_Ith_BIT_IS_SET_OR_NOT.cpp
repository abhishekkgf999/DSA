/*
#Check K-th Bit

LINK:- https://www.geeksforgeeks.org/problems/check-whether-k-th-bit-is-set-or-not-1587115620/1
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkKthBit(int n, int k) {
        //  code here
        int result = n >> k;

        return result & 1;
    }
};

int main() {
    Solution obj;
    cout << obj.checkKthBit(5, 2);
    return 0;
}