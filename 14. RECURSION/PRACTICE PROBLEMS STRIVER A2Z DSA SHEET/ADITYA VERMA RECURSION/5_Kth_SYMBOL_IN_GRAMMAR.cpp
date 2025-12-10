/*
#Kth SYMBOL IN GRAMMAR

LINK:- https://leetcode.com/problems/k-th-symbol-in-grammar/description/

*/

#include<bits/stdc++.h>
using namespace std;

/*
Pattern: Each row is built by duplicating the previous row, but second half is flipped.

Row Structure:
- Row 1: 0
- Row 2: 01
- Row 3: 0110
- Row 4: 01101001

Key Insight:
- If k is in first half of row n → same as position k in row n-1
- If k is in second half of row n → opposite of corresponding position in row n-1

Why it works: Each row has a recursive structure - first half copies previous row, second half flips it. So we can reduce the problem size by half each time.

Time: O(n), Space: O(n) recursion stack


------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

Why subtract mid from k in second half:

Understanding the mapping:

When we're in the second half, we need to find the corresponding position in the previous row that generated this position.

Example: Row 3: 0110 (positions 1,2,3,4)
- First half: positions 1,2 → come from row 2 positions 1,2  
- Second half: positions 3,4 → come from row 2 positions 1,2 (but flipped)

The mapping:
- Position 3 in row 3 → comes from position 1 in row 2 (3 - 2 = 1)
- Position 4 in row 3 → comes from position 2 in row 2 (4 - 2 = 2)

General rule:
- If k is in second half, it corresponds to position k - mid in the previous row
- We subtract mid to translate the position from second half back to the corresponding first half position

Think of it as: 
- Second half positions are just shifted copies of first half
- k - mid gives us the relative position within the second half
- This relative position maps to the same position in the previous row (before flipping)

So k - mid is just coordinate transformation to find the source position.

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

int main() {
    cout << kthGrammar(4, 7);
    return 0;
}