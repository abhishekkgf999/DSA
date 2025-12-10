/*
#MODULAR EXPONENTIATION
LINK:- https://www.codingninjas.com/studio/problems/modular-exponentiation_1082146?leftPanelTabValue=SOLUTION


#In this solution, we will use:- https://cp-algorithms.com/algebra/binary-exp.html
#Modular arithmetic for beginers:- https://codeforces.com/blog/entry/72527


------x------x------x------x------x------x------x------x------x------x------x------x------x------x------x------x------x------

=>  The idea here is to split ‘N’ in powers of two by converting it into its binary representation to achieve answer
    in O(log ‘N’) steps.



=>  For example if ‘N’ = 7 and ‘X’ = 8. The binary representation of ‘N’ = 111. So 8^7 can be calculated using
    multiplication 8^4 , 8^2, 8.



=>  So in each step, we will keep squaring ‘X’ and if ‘N’ has a set bit its binary representation then we will
    multiply ‘X’ to answer.

------x------x------x------x------x------x------x------x------x------x------x------x------x------x------x------x------x------

The Steps are as follows:

=>Declare a variable to store our result, say ‘ANSWER’, and initialize it with 1.
=>Run a loop until ‘N’ > 0, and do:
    =>(A) If bitwise and of ‘N’ with 1 is 1 then multiply the answer with ‘X’.
    =>(B) Do modular squaring of 'X' i.e. do 'X' = ('X' * 'X') % 'M'.
=>Finally, return the ‘ANSWER’.

------x------x------x------x------x------x------x------x------x------x------x------x------x------x------x------x------x------

=>  Time Complexity
    O(log N), Where ‘N’ is the number given in the problem.

    Since we are running a loop that takes O(logN) time in the worst case. Hence the overall time complexity will be O(log N).

=>  Space Complexity
    O(1).

    Since constant space is required and hence the space complexity will be O(1).

*/

#include <bits/stdc++.h>
using namespace std;

int modularExponentiation(int x, int n, int m)
{
    int res = 1;

    while (n > 0)
    {
        if (n & 1)
        {
            res = (1LL * (res) * (x) % m) % m; // The use of (1LL * ...) ensures that intermediate results do not overflow,
                                               // as it forces the multiplication to be done using long long integers.
        }
        x = (1LL * (x) % m * (x) % m) % m;
        n = n >> 1;
    }
    return res;
}

int main()
{
    int x, n, m;
    cout << "Enter the value of number:- ";
    cin >> x;
    cout << "Enter the value for raising power:- ";
    cin >> n;
    cout << "Enter the modulo value:- ";
    cin >> m;

    int ans = modularExponentiation(x, n, m);
    cout << "The value of (" << x << "^" << n << ")%" << m << " is:- " << ans << endl;
    return 0;
}