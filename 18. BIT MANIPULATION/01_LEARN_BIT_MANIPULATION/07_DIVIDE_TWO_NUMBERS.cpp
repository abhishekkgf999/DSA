/*
#DIVIDE TWO NUMBERS

LINK:- https://leetcode.com/problems/divide-two-integers/description/
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }

        if (dividend == divisor)return 1;

        bool sign = true;

        if ((dividend >= 0 && divisor < 0) || (dividend <= 0 && divisor > 0))sign = false;

        long long n = abs((long long)dividend);
        long long d = abs((long long)divisor);

        divisor = abs((long long)divisor);

        long quotient = 0;
        while (n >= d) {
            int cnt = 0;
            while (n >= (d << (cnt + 1))) {
                cnt += 1;
            }
            quotient += 1 << cnt;
            n -= (d << cnt);
        }

        if (quotient == (1 << 31) && sign)return INT_MAX;
        if (quotient == (1 << 31) && !sign)return INT_MIN;

        return sign ? quotient : -quotient;

    }
};

int main() {
    Solution s;

    // Test cases
    cout << "Test Case 1: 10 / 3 = " << s.divide(10, 3) << " (Expected: 3)" << endl;
    cout << "Test Case 2: 7 / -3 = " << s.divide(7, -3) << " (Expected: -2)" << endl;
    cout << "Test Case 3: 0 / 1 = " << s.divide(0, 1) << " (Expected: 0)" << endl;
    cout << "Test Case 4: 1 / 1 = " << s.divide(1, 1) << " (Expected: 1)" << endl;
    cout << "Test Case 5: 2147483647 / 1 = " << s.divide(INT_MAX, 1) << " (Expected: 2147483647)" << endl;
    cout << "Test Case 6: -2147483648 / -1 = " << s.divide(INT_MIN, -1) << " (Expected: 2147483647)" << endl;
    cout << "Test Case 7: -2147483648 / 1 = " << s.divide(INT_MIN, 1) << " (Expected: -2147483648)" << endl;
    cout << "Test Case 8: 100 / 10 = " << s.divide(100, 10) << " (Expected: 10)" << endl;
    cout << "Test Case 9: 100 / -10 = " << s.divide(100, -10) << " (Expected: -10)" << endl;

    return 0;
}