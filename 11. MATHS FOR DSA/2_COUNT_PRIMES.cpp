/*
#COUNT PRIMES
LINK:- https://leetcode.com/problems/count-primes/description/

#USING SIEVE OF ERATOSTHENES

In this approach , first we consider every n-1 range numbers as prime, ==> vector<bool> prime(n+1, true);
then just eliminate the multiple of prime numbers from the given search space ex:-
 for(int i=2; i<n; i++){
            if(prime[i]){
                count++;
                for(int j=2*i; j<n; j +=i){
                    prime[j] = false;
                }
            }
        }

lets say n = 10;
our suspect numbers are:- 2, 3, 4, 5, 6, 7, 8, 9
                          ^
                          |
we start with 2, and eliminate its multiple ==> 4, 6 & 8
and our count of prime is now ==> 1

now our suspect numbers are:- 2, 3, 4-Χ, 5, 6-Χ, 7, 8-Χ, 9
                                 ^
                                 |
eliminate 3 multiple ==> 6, 9
and our count of prime is now ==> 2

now our suspect numbers are:- 2, 3, 4-Χ, 5, 6-Χ, 7, 8-Χ, 9-Χ
                                         ^
                                         |
eliminate 5 multiple ==> 10(not in range)
and our count of prime is now ==> 3

now our suspect numbers are:- 2, 3, 4-Χ, 5, 6-Χ, 7, 8-Χ, 9-Χ
                                                 ^
                                                 |

eliminate 7 multiple ==> 14(not in range)
and our count of prime is now ==> 4

now loops end, no prime exists in our range


*/

#include <bits/stdc++.h>
using namespace std;


//TIME COMPLEXITY IS:- (N*LOG(LOG N)) ==> COMES FROM TAYLOR SERIES
//SPACE COMPLEXITY IS:- O(N)
int countPrimes(int n)
{
    vector<bool> prime(n + 1, true);

    prime[0] = prime[1] = false;
    int count = 0;

    for (int i = 2; i < n; i++)
    {
        if (prime[i])
        {
            count++;
            for (int j = 2 * i; j < n; j += i)
            {
                prime[j] = false;
            }
        }
    }
    return count;
}

int main()
{
    int n;
    cout << "Enter your number:- " << endl;
    cin >> n;

    int ans = countPrimes(n);
    cout << "Numbers of prime number exits that are strictly less than " << n << " is:- " << ans << endl;
    return 0;
}