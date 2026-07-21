/*
====================================================
MAXIMUM BUILDING HEIGHT
LeetCode:
https://leetcode.com/problems/maximum-building-height/description/
====================================================

💡 PROBLEM SUMMARY
----------------------------------------------------
We are given:

✔ n buildings

✔ Some restricted buildings:
      [id, maxHeight]

Conditions:

1. Building 1 has height = 0

2. Adjacent buildings must satisfy:

      |h[i] - h[i-1]| <= 1

3. Heights can only be reduced,
   never increased beyond restriction.

Goal:

✔ Find the maximum building height
  that can be achieved.

====================================================
MOST IMPORTANT OBSERVATION ⭐
----------------------------------------------------
Look at constraints:

    2 <= n <= 10^9

    restrictions <= 10^5

----------------------------------------------------
Immediately tells us:

✔ Cannot process all buildings

✔ Need to work only with
  restricted positions

This is the key observation.

====================================================
WHY RESTRICTIONS ARE ENOUGH ?
----------------------------------------------------
The only places where height is
explicitly bounded are:

✔ Restricted buildings

----------------------------------------------------
All buildings in between are free
to grow while maintaining:

      difference <= 1

So if we know the valid heights
of restricted buildings,

we can derive everything else.

====================================================
STEP 1 : ADD MISSING RESTRICTIONS ⭐
----------------------------------------------------
Question guarantees:

Building 1 height = 0

So add:

    {1, 0}

----------------------------------------------------
Also:

Last building can never exceed:

    n - 1

because starting from building 1,
height can increase by at most 1.

So add:

    {n, n-1}

====================================================
STEP 2 : SORT RESTRICTIONS
----------------------------------------------------
After sorting:

    id1 < id2 < id3 ...

Now we can propagate constraints
from left and right.

====================================================
LEFT TO RIGHT PASS ⭐
----------------------------------------------------
Suppose:

    Building A
    height = h1

and

    Building B
    height = h2

Distance:

    d = idB - idA

----------------------------------------------------
Maximum possible height at B:

    h1 + d

because every step can increase by at most 1.

----------------------------------------------------
Therefore:

    h2 = min(h2, h1 + d)

====================================================
RIGHT TO LEFT PASS ⭐
----------------------------------------------------
Same logic from opposite side.

----------------------------------------------------
Maximum possible height at A:

    h2 + d

Therefore:

    h1 =
    min(h1, h2 + d)

----------------------------------------------------
After both passes:

✔ Every restriction becomes valid.

✔ All restrictions now satisfy
  adjacent-difference constraints.

====================================================
WHAT DO WE HAVE NOW ?
----------------------------------------------------
We only know heights of:

✔ Restricted buildings

But we need:

✔ Maximum height among ALL buildings

including buildings between them.

====================================================
KEY GEOMETRIC OBSERVATION ⭐⭐⭐
----------------------------------------------------
Suppose:

(id1, h1)

and

(id2, h2)

Distance:

    d = id2 - id1

----------------------------------------------------
Between them:

Height can increase by 1
and decrease by 1.

Maximum height occurs somewhere
in the middle.

----------------------------------------------------
Example:

    h1 = 2
    h2 = 4
    d  = 6

----------------------------------------------------
First:

Use some distance to make
smaller height catch up.

Then:

Remaining distance can be split
on both sides.

====================================================
MAXIMUM HEIGHT FORMULA ⭐
----------------------------------------------------
Maximum achievable peak:

* VISUAL INTUITION:
     *
     *         peak
     *        /    \
     *       /      \
     * hL --/        \-- hR
     *  L              R
     *
     * Rise from left: peak = hL + d1
     * Rise from right: peak = hR + d2
     * Total: d1 + d2 = R - L = distance
     * So: 2*peak = hL + hR + distance
     *     peak = (hL + hR + distance) / 2

    (h1 + h2 + d) / 2

----------------------------------------------------
This formula automatically handles:

✔ Equal heights

✔ Different heights

✔ Odd/even distance

====================================================
APPROACH
----------------------------------------------------

STEP 1:
✔ Add:

      {1,0}

      {n,n-1}

----------------------------------------------------

STEP 2:
✔ Sort restrictions

----------------------------------------------------

STEP 3:
✔ Left → Right relaxation

      min(current,
          prevHeight + distance)

----------------------------------------------------

STEP 4:
✔ Right → Left relaxation

      min(current,
          nextHeight + distance)

----------------------------------------------------

STEP 5:
✔ For every adjacent restriction pair

Compute:

      (h1 + h2 + d) / 2

----------------------------------------------------

STEP 6:
✔ Return maximum value

====================================================
IMPORTANT OBSERVATIONS
----------------------------------------------------
✔ n can be 10^9

✔ Never iterate all buildings

✔ Work only on restrictions

✔ Two-pass relaxation validates
  all restrictions

✔ Peak occurs between two
  restricted buildings

====================================================
TIME & SPACE COMPLEXITY
----------------------------------------------------
Let:

    m = restrictions.size()

----------------------------------------------------
Sorting:

➡ O(m log m)

----------------------------------------------------
Passes:

➡ O(m)

----------------------------------------------------
Total:

➡ O(m log m)

SPACE:

➡ O(m)

====================================================
KEY TAKEAWAY
----------------------------------------------------
Whenever:

✔ Adjacent difference is bounded

and

✔ Only some positions have constraints

Think:

✔ Constraint propagation

(left → right)

(right → left)

----------------------------------------------------
After validating constraints,

the maximum value between two
restricted points becomes:

    (h1 + h2 + distance) / 2

which is the core formula of
this problem.

====================================================
*/

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {

        if (restrictions.empty()) return n - 1;

        restrictions.push_back({ 1, 0 });
        restrictions.push_back({ n, n - 1 });

        sort(restrictions.begin(), restrictions.end());

        int sz = restrictions.size();

        for (int i = 1; i < sz; i++) {
            restrictions[i][1] = min(restrictions[i][1], restrictions[i - 1][1] + (restrictions[i][0] - restrictions[i - 1][0]));
        }

        for (int i = sz - 2; i >= 0; i--) {
            restrictions[i][1] = min(restrictions[i][1], restrictions[i + 1][1] + (restrictions[i + 1][0] - restrictions[i][0]));
        }

        int ans = 0;

        for (int i = 1; i < sz; i++) {
            long long id1 = restrictions[i - 1][0];
            long long h1 = restrictions[i - 1][1];

            long long id2 = restrictions[i][0];
            long long h2 = restrictions[i][1];

            long long d = id2 - id1;

            ans = max(ans, (int)((h1 + h2 + d) / 2));
        }

        return ans;
    }
};

int main() {

    return 0;
}

