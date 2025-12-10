/*
#ROD CUTTING PROBLEM

LINK:- https://www.geeksforgeeks.org/problems/rod-cutting0840/1

*/

/*
# INTUITION

1. If only one piece length (length = 1) is available, we can only cut unit-sized segments.
   Hence, total profit = price[0] * remaining length.

2. If the current piece length `n` is less than or equal to the remaining rod length `L`,
   we can:
   - Cut a piece of length `n`
   - Add its profit (price[n-1])
   - Recur with the reduced rod length (L - n) using the same piece length (unbounded reuse)

3. If the current piece length `n` is greater than `L`, it can't be used.
   So, we skip it and try a shorter piece (i.e., n - 1).

# APPROACH

1. Base Case:
   If only piece length 1 is available (n == 1), the entire rod is cut into unit pieces.
   → return price[0] * L;

2. Take the current piece (if its length ≤ L):
   → take = price[n-1] + rod_cutting(n, L - n);

3. Or skip the current piece and try a smaller one:
   → not_take = rod_cutting(n - 1, L);

4. Return the better of the two options:
   → return max(take, not_take);

# COMPLEXITY

- Time: O(2^n) due to overlapping subproblems and branching
- Space: O(L + n) from recursive call stack (no memoization yet)
*/



#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>& price, int L, int n) {
    if (n == 1)
        return price[0] * L;

    int take_that_piece = 0;
    if (n <= L) {
        take_that_piece = price[n - 1] + solve(price, L - n, n);
    }

    int not_take_that_piece = solve(price, L, n - 1);

    return max(take_that_piece, not_take_that_piece);
}
int cutRod(vector<int>& price) {
    // code here
    int L = price.size();
    int n = L;
    return solve(price, L, n);
}

int main(){
    vector<int> price = {1, 5, 8, 9, 10, 17, 17, 20};
    cout<<cutRod(price);
    return 0;
}