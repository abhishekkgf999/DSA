/*
Check if a number is odd or not

link:- https://www.geeksforgeeks.org/problems/odd-or-even3618/1
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isEven(int n) {
        // code here
        return !(n & 1);
    }
};

int main() {
    Solution obj;
    cout << obj.isEven(5);
    return 0;
}