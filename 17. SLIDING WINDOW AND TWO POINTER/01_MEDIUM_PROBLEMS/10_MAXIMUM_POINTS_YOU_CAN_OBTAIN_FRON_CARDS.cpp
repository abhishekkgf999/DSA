/*
#MAXIMUM POINTS YOU CAN OBTAIN FROM CARDS

LINK:- https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/
*/

#include<bits/stdc++.h>
using namespace std;

/*

## Core Algorithm: Prefix Sum + Sliding Transition

### Key Insight
Can only pick from ends → Valid combinations:
- k cards from left + 0 from right
- (k-1) from left + 1 from right
- (k-2) from left + 2 from right
- ...
- 0 from left + k from right

### Two-Phase Approach

### Phase 1: Initialize with All Left
Logic: Start with maximum left bias (all k cards from left side)

### Phase 2: Slide from Left to Right
Logic: Gradually shift from left-heavy to right-heavy selection
- Remove rightmost left card, add rightmost right card
- Check if this combination gives better sum

Sum transitions:
- leftSum decreases as we remove left cards
- rightSum increases as we add right cards
- Total cards always remains k

## Mental Model
Sliding between two extremes:

cardPoints = [1,2,3,4,5,6,1], k = 3

Combinations to check:
[1,2,3] + [] = 6           (all left)
[1,2] + [1] = 4           (2 left, 1 right)
[1] + [6,1] = 8           (1 left, 2 right)
[] + [5,6,1] = 12         (all right)

Maximum = 12


## Key Points
- Enumerate all valid combinations: k+1 possible ways to pick k cards from ends
- Efficient transition: Instead of recalculating, slide between combinations
- Two-pointer movement: Inner convergence from both ends

Time: O(k) | Space: O(1)
*/
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int ans = 0;
        int leftSum = 0, rightSum = 0;
        for (int i = 0; i < k; i++) {
            leftSum += cardPoints[i];
        }
        ans = max(ans, leftSum);
        int n = cardPoints.size();
        int i = k - 1, j = n - 1;
        while (k) {
            leftSum -= cardPoints[i];
            rightSum += cardPoints[j];
            ans = max(ans, (leftSum + rightSum));
            i--;
            j--;
            k--;
        }
        return ans;
    }
};

int main() {
    Solution sol;

    // Example 1: Standard case
    vector<int> cards1 = { 1,2,3,4,5,6,1 };
    int k1 = 3;
    cout << "Cards: {1,2,3,4,5,6,1}, k: 3" << endl;
    cout << "Max Score: " << sol.maxScore(cards1, k1) << endl; // Expected Output: 12

    // Example 2: Taking all from the right
    vector<int> cards2 = { 9,7,7,9,7,7,9 };
    int k2 = 7;
    cout << "Cards: {9,7,7,9,7,7,9}, k: 7" << endl;
    cout << "Max Score: " << sol.maxScore(cards2, k2) << endl; // Expected Output: 55

    // Example 3: Taking from both ends
    vector<int> cards3 = { 100,40,17,9,73,75 };
    int k3 = 3;
    cout << "Cards: {100,40,17,9,73,75}, k: 3" << endl;
    cout << "Max Score: " << sol.maxScore(cards3, k3) << endl; // Expected Output: 248

    return 0;
}
