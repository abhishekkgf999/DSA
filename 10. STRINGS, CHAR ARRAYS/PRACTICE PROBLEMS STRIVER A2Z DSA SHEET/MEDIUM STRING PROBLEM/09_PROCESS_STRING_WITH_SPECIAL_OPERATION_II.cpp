#include<bits/stdc++.h>
using namespace std;

/*
====================================================
PROCESS STRING WITH SPECIAL OPERATION II
LeetCode:
https://leetcode.com/problems/process-string-with-special-operations-ii/
====================================================

💡 PROBLEM SUMMARY
----------------------------------------------------
We are given a string containing:

✔ lowercase characters
✔ '#'
✔ '%'
✔ '*'

These symbols perform special operations
on a virtual string.

Goal:
✔ Return the kth character of the final
  processed string

----------------------------------------------------
IMPORTANT:

Final string length can become extremely large.

So:
✔ Building the actual string is impossible

====================================================
CORE IDEA: REVERSE SIMULATION ⭐
----------------------------------------------------
Instead of constructing the final string,

we only track:

✔ Current Length

and

✔ Position k

----------------------------------------------------
This is a classic:

"Find kth character without building
the entire string"

problem.

====================================================
OBSERVATION 1 : NORMAL CHARACTER
----------------------------------------------------
Suppose:

    current string = abc

Add:

    d

Result:

    abcd

----------------------------------------------------
Effect:

✔ length increases by 1

    len++

====================================================
OBSERVATION 2 : '#' OPERATION ⭐
----------------------------------------------------
Meaning:

Duplicate current string.

Example:

    abc

After '#'

    abcabc

----------------------------------------------------
Effect:

✔ Length doubles

    len = len * 2

====================================================
HOW DOES '#' AFFECT k ?
----------------------------------------------------
Example:

    abcabc

Length:

    6

----------------------------------------------------
Original half:

    abc
    012

Duplicated half:

    abc
    345

----------------------------------------------------
If:

    k >= len/2

Then:

Character actually belongs to
the first half.

So:

    k %= (len/2)

====================================================
OBSERVATION 3 : '%' OPERATION ⭐
----------------------------------------------------
Meaning:

Reverse the string.

Example:

    abcde

becomes:

    edcba

----------------------------------------------------
Length remains same.

Only position changes.

====================================================
HOW DOES '%' AFFECT k ?
----------------------------------------------------
If string length = len

Then:

    new position

becomes:

    len - 1 - k

====================================================
OBSERVATION 4 : '*' OPERATION ⭐
----------------------------------------------------
Meaning:

Delete last character.

Example:

    abcde

becomes:

    abcd

----------------------------------------------------
Effect:

✔ Length decreases by 1

====================================================
MAIN STRATEGY
----------------------------------------------------
STEP 1:

Find final length only.

----------------------------------------------------
STEP 2:

If:

    k >= finalLength

Then:

✔ answer doesn't exist

Return '.'

----------------------------------------------------
STEP 3:

Traverse string from BACKWARD

Undo operations one by one.

====================================================
WHY REVERSE TRAVERSAL WORKS ?
----------------------------------------------------
Forward:

    a → b → c

creates final string.

----------------------------------------------------
Backward:

We ask:

✔ From which position did
  current kth character originate?

====================================================
REVERSE HANDLING OF OPERATIONS
----------------------------------------------------

CHARACTER
----------------------------------------------------
Forward:

    len++

Backward:

    len--

----------------------------------------------------
If:

    k == len-1

Then:

✔ current character is answer

====================================================

'#'
----------------------------------------------------
Forward:

    len *= 2

Backward:

    len /= 2

----------------------------------------------------
Character in duplicated half:

maps to original half

So:

    k %= len

====================================================

'%'
----------------------------------------------------
Forward:

Reverse string

Backward:

Still reverse mapping

    k = len - 1 - k

====================================================

'*'
----------------------------------------------------
Forward:

Delete one character

    len--

Backward:

Restore deleted position

    len++

====================================================
APPROACH
----------------------------------------------------

PHASE 1:
----------------------------------------------------
Compute final length

Character:
    len++

'*':
    len--

'#':
    len *= 2

'%':
    no change

----------------------------------------------------

PHASE 2:
----------------------------------------------------
If:

    k >= len

Return '.'

----------------------------------------------------

PHASE 3:
----------------------------------------------------
Traverse string from right to left

Undo operations.

----------------------------------------------------

PHASE 4:
----------------------------------------------------
When encountering character:

If:

    k == len-1

Return that character

====================================================
IMPORTANT CONDITIONS
----------------------------------------------------
✔ Never build final string
✔ Only maintain length
✔ Reverse simulation is key
✔ '#' doubles length
✔ '%' reverses index
✔ '*' removes last character

====================================================
TIME & SPACE COMPLEXITY
----------------------------------------------------
TIME:
➡ O(N)

One forward pass +
One backward pass

----------------------------------------------------
SPACE:
➡ O(1)

====================================================
KEY TAKEAWAY
----------------------------------------------------
Whenever problem asks:

✔ kth character of huge string
✔ repeated transformations
✔ final string too large

Think:

✔ Reverse Simulation

Instead of constructing the result,

track:

✔ length
✔ position k

and undo operations backwards.

====================================================
*/

class Solution {
public:
    char processStr(string s, long long k) {
        long long len = 0;
        for (char c : s) {
            if (islower(c)) {
                len++;
            }
            else if (c == '*') {
                if (len > 0) len--;
            }
            else if (c == '#') {
                len *= 2;
            }
            else if (c == '%') {}
        }
        if (k >= len) return '.';
        for (int i = s.size() - 1; i >= 0; i--) {
            char c = s[i];
            if (islower(c)) {
                if (k == len - 1) {
                    return c;
                }
                len--;
            }
            else if (c == '*') {
                len++;
            }
            else if (c == '#') {
                len /= 2;
                k %= len;
            }
            else if (c == '%') {
                k = len - 1 - k;
            }
        }
        return '.';
    }
};

int main() {

    return 0;
}