/*
#Kth SYMBOL IN GRAMMAR

LINK:- https://leetcode.com/problems/k-th-symbol-in-grammar/description/

*/

#include<bits/stdc++.h>
using namespace std;

/*
kthGrammar(3, 4)

Row 3: 0110 → 4th symbol is 0

Trace:

k > mid (4 > 2) → go to kthGrammar(2, 2) and flip

k == mid → go to kthGrammar(1, 1) → 0 → flip → 1

Flip again → 0 ✅
*/

//TIME COMPLEXITY :- O(N)
int kthGrammar(int n, int k) {
    // Base case: For the first row or the first position, the result is always 0.
    if (n == 1 || k == 1) return 0;

    // Calculate the midpoint of the current row.
    int mid = pow(2, n - 1) / 2;

    // If k is in the first half, recursively call the function for the first half.
    if (k <= mid) return kthGrammar(n - 1, k);

    // If k is in the second half, recursively call the function for the first half,
    // but invert the result as the second half is the complement of the first half.
    else return !(kthGrammar(n - 1, k - mid));
}

int main(){
    cout<<kthGrammar(4, 7);
    return 0;
}