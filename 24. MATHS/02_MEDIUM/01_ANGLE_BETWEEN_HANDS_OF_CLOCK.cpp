/*
====================================================
ANGLE BETWEEN HANDS OF A CLOCK
LeetCode:
https://leetcode.com/problems/angle-between-hands-of-a-clock/
====================================================

💡 PROBLEM SUMMARY
----------------------------------------------------
Given:

✔ Hour hand position
✔ Minute hand position

Goal:

✔ Find the smaller angle formed
  between the two clock hands.

----------------------------------------------------
A clock always forms two angles:

    Smaller Angle
    Larger Angle

We must return:
✔ Smaller Angle

====================================================
CORE OBSERVATION ⭐
----------------------------------------------------
To solve this problem:

✔ Calculate angle of minute hand
✔ Calculate angle of hour hand

Then:

✔ Find absolute difference

====================================================
MINUTE HAND ANGLE
----------------------------------------------------
We know:

    360° → 60 minutes

Therefore:

    1 minute → 6°

Hence:

    minuteAngle = minutes × 6

----------------------------------------------------
Example:

15 minutes

    15 × 6 = 90°

====================================================
HOUR HAND ANGLE
----------------------------------------------------
We know:

    360° → 12 hours

Therefore:

    1 hour → 30°

Hence:

    hourAngle = hour × 30

----------------------------------------------------
But there is one important thing.

Hour hand continuously moves
while minutes increase.

====================================================
MINUTE CONTRIBUTION IN HOUR HAND ⭐
----------------------------------------------------
In 1 hour:

    Hour hand moves 30°

In 60 minutes:

    Hour hand moves 30°

Therefore:

    1 minute contributes

    30 / 60 = 0.5°

----------------------------------------------------
Hence:

    hourAngle =
        (hour % 12) × 30
        +
        minutes × 0.5

====================================================
WHY (hour % 12) ?
----------------------------------------------------
Clock is circular.

Example:

12 o'clock

should represent:

    0°

NOT:

    360°

So:

    hour % 12

keeps everything relative to
12 o'clock position.

====================================================
FINAL ANGLE
----------------------------------------------------
After calculating both angles:

    totalAngle =
        |hourAngle - minuteAngle|

====================================================
SMALLER ANGLE CONDITION ⭐
----------------------------------------------------
A circle contains:

    360°

----------------------------------------------------
If one angle is:

    totalAngle

Then other angle is:

    360 - totalAngle

----------------------------------------------------
We need:

✔ Smaller angle

So:

    min(
        totalAngle,
        360 - totalAngle
    )

====================================================
APPROACH
----------------------------------------------------
STEP 1:
✔ Calculate minute hand angle

----------------------------------------------------
STEP 2:
✔ Calculate hour hand angle

----------------------------------------------------
STEP 3:
✔ Find absolute difference

----------------------------------------------------
STEP 4:
✔ Return smaller angle

====================================================
IMPORTANT OBSERVATIONS
----------------------------------------------------
✔ Minute hand moves 6° per minute

✔ Hour hand moves 30° per hour

✔ Hour hand additionally moves
  0.5° per minute

✔ Always return smaller angle

====================================================
TIME & SPACE COMPLEXITY
----------------------------------------------------
TIME:
➡ O(1)

SPACE:
➡ O(1)

====================================================
KEY TAKEAWAY
----------------------------------------------------
Clock problems usually involve:

✔ Converting time into angles

Remember:

Minute Hand:
    6° per minute

Hour Hand:
    30° per hour
    +
    0.5° per minute

Final Answer:

    min(
        |hourAngle - minuteAngle|,
        360 - |hourAngle - minuteAngle|
    )

====================================================
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    double angleClock(int hour, int minutes) {
        double minuteAngle = minutes*6;
        double hourAngle = (hour%12)*30 + minutes*0.5;
        double totalAngle = abs(hourAngle - minuteAngle);
        return min(totalAngle, 360-totalAngle); 
    }
};

int main(){
    
    return 0;
}