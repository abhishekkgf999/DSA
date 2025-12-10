/*
#Set the rightmost unset bit

Link:- https://www.geeksforgeeks.org/problems/set-the-rightmost-unset-bit4436/1
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int setBit(int n) {
        // Write Your Code here
        int temp = 1;
        int copy = n;
        while (copy & 1) {
            temp = temp << 1;
            copy = copy >> 1;
        }

        if (n == temp)return n;

        return n ^ temp;
    }
};

int main() {
    Solution obj;
    cout << obj.setBit(6);
    return 0;
}