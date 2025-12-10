/*
#FIND XOR OF NUMBERS FROM L TO R

LINK:- https://www.geeksforgeeks.org/problems/find-xor-of-numbers-from-l-to-r/1
*/

#include<bits/stdc++.h>
using namespace std;

/*
## Core Insight: XOR Pattern Repeats Every 4 Numbers

### Pattern Discovery

XOR from 1 to n:
n=1: 1
n=2: 1^2 = 3
n=3: 1^2^3 = 0
n=4: 1^2^3^4 = 4
n=5: 1^2^3^4^5 = 1    (pattern repeats!)
n=6: 1^2^3^4^5^6 = 7
n=7: 1^2^3^4^5^6^7 = 0
n=8: 1^2^3^4^5^6^7^8 = 8


### Pattern Formula
cpp
switch (n % 4) {
    case 0: return n;      // XOR(1 to n) = n
    case 1: return 1;      // XOR(1 to n) = 1
    case 2: return n + 1;  // XOR(1 to n) = n+1
    case 3: return 0;      // XOR(1 to n) = 0
}


## Range XOR Logic
Key property: XOR(L to R) = XOR(1 to R) ^ XOR(1 to L-1)

Why this works?
- XOR(1 to R) contains all numbers from 1 to R
- XOR(1 to L-1) contains all numbers from 1 to L-1
- XORing them cancels out 1 to L-1, leaving only L to R
*/

class Solution {
private:
    // Helper function to find the XOR sum from 1 to n
    int xor_until_N(int n) {
        switch (n % 4) {
        case 0:
            return n;
        case 1:
            return 1;
        case 2:
            return n + 1;
        case 3:
            return 0;
        default: // Should not be reached
            return 0;
        }
    }

public:
    int findXOR(int l, int r) {
        // XOR sum of range [l, r] = (XOR sum from 1 to r) ^ (XOR sum from 1 to l-1)
        return xor_until_N(r) ^ xor_until_N(l - 1);
    }
};

int main() {
    Solution sol;

    // Test cases
    int l1 = 2, r1 = 4; // Expected: 2^3^4 = 5
    cout << "XOR of numbers from " << l1 << " to " << r1 << " is: " << sol.findXOR(l1, r1) << endl;

    int l2 = 1, r2 = 10; // Expected: 1^2^3^...^10
    cout << "XOR of numbers from " << l2 << " to " << r2 << " is: " << sol.findXOR(l2, r2) << endl;

    int l3 = 5, r3 = 9; // Expected: 5^6^7^8^9 = 15
    cout << "XOR of numbers from " << l3 << " to " << r3 << " is: " << sol.findXOR(l3, r3) << endl;

    return 0;
}

