/*
#SWAP TWO NUMBERS

LINK:- https://www.geeksforgeeks.org/problems/swap-two-numbers3844/1
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    pair<int, int> get(int a, int b) {
        // code here
        a = a ^ b;
        b = a ^ b;
        a = a ^ b;

        return { a, b };
    }
};

int main() {
    Solution obj;
    pair<int, int> ans = obj.get(3, 4);
    cout << ans.first << " " << ans.second;
    return 0;
}