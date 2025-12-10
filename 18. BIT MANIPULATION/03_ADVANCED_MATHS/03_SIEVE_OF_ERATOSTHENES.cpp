/*
#SIEVE OF ERATOSTHENES

LINK:- https://leetcode.com/problems/count-primes/description/
*/


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        vector<bool> prime(n + 1, 1);

        prime[0] = prime[1] = 0;
        int count = 0;

        for (int i = 2; i < n; i++) {
            if (prime[i]) {
                count++;
                for (int j = 2 * i; j < n; j += i) {
                    prime[j] = 0;
                }
            }
        }
        return count;
    }
};

int main() {
    Solution obj;
    cout << obj.countPrimes(5);
    return 0;
}