/*
#PRINT DIVISOR

LINK:- https://www.geeksforgeeks.org/problems/all-divisors-of-a-number/1
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void print_divisors(int n) {
        vector<int> ans;

        for (int i = 1; i <= sqrt(n); i++) {
            if (n % i == 0) {
                ans.push_back(i);
                if (n / i != i)ans.push_back(n / i);
            }
        }

        sort(ans.begin(), ans.end());
        for (auto i : ans)cout << i << " ";
    }
};

int main() {
    Solution sol;

    // Example 1: A perfect square
    int n1 = 36;
    cout << "Divisors of " << n1 << " are: ";
    sol.print_divisors(n1);
    cout << endl;

    // Example 2: A non-perfect square
    int n2 = 12;
    cout << "Divisors of " << n2 << " are: ";
    sol.print_divisors(n2);
    cout << endl;

    // Example 3: A prime number
    int n3 = 7;
    cout << "Divisors of " << n3 << " are: ";
    sol.print_divisors(n3);
    cout << endl;

    return 0;
}
