/*
#COUNT THE NUMBER OF SET BITS

LINK:- https://www.geeksforgeeks.org/problems/set-bits0143/1
*/

#include<bits/stdc++.h>
using namespace std;

class Solution1 {
public:
    int setBits(int n) {
        // Write Your Code here
        int count = 0;
        while (n) {
            if (n & 1) {
                count++;
            }
            n = n >> 1;
        }

        return count;
    }
};

class Solution2 {
public:
    int setBits(int n) {
        // Write Your Code here
        int count = 0;
        while (n) {
            n = n & (n - 1);
            count++;
        }

        return count;
    }
};

int main() {
    Solution1 sol1;
    Solution2 sol2;
    int n = 13; // Example input

    cout << "Using Solution 1 (right shift method):" << endl;
    cout << "The number of set bits in " << n << " is: " << sol1.setBits(n) << endl;

    cout << "\nUsing Solution 2 (Brian Kernighan's method):" << endl;
    cout << "The number of set bits in " << n << " is: " << sol2.setBits(n) << endl;

    return 0;
}