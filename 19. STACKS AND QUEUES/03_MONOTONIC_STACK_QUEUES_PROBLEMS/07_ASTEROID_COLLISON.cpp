/*
#ASTEROID COLLISION

LINK:- https://leetcode.com/problems/asteroid-collision/

## Problem Statement
Given an array of asteroids with absolute value = size and sign = direction:
- Positive (+) → Moving RIGHT
- Negative (-) → Moving LEFT

When two asteroids collide, the smaller one explodes. If equal, both explode.

*/


#include<bits/stdc++.h>
using namespace std;

/*
## Core Concept: Stack-Based Collision Detection

### When Do Asteroids Collide?
Collision happens ONLY when:
- Stack has asteroid moving RIGHT (positive)
- Current asteroid moving LEFT (negative)


Stack top: +5 (moving →)
Current:   -3 (moving ←)
           ↓
        COLLISION!


### No Collision Cases:

1. Both moving RIGHT:  +5, +3 → No collision
2. Both moving LEFT:   -5, -3 → No collision  
3. LEFT then RIGHT:    -5, +3 → Moving apart, no collision

## Collision Scenarios

### Scenario 1: Current Asteroid WINS (Bigger)

if (abs(st.top()) < abs(x))
    st.pop();  // Remove top, continue checking

Example: Stack=[+5], Current=-8
- 8 > 5 → Remove +5
- Continue loop (may collide with more asteroids)

---

### Scenario 2: Both EQUAL Size (Both Destroyed)

else if (abs(st.top()) == abs(x)) {
    st.pop();          // Remove top
    destroyed = true;  // Current also destroyed
    break;             // Stop checking
}

Example: Stack=[+5], Current=-5
- Equal size → Both destroyed
- Don't add current to stack

---

### Scenario 3: Stack Asteroid WINS (Bigger)

else {
    destroyed = true;  // Current destroyed
    break;             // Stop checking
}

Example: Stack=[+8], Current=-5
- 8 > 5 → Current destroyed
- Stack asteroid survives, don't add current

*/

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& ass) {
        stack<int> st;

        for (int x : ass) {
            bool destroyed = false;   //Destroyed Flag Prevents adding destroyed asteroid to stack
            while (!st.empty() && st.top() > 0 && x < 0) {
                if (abs(st.top()) < abs(x))
                    st.pop();
                else if (abs(st.top()) == abs(x)) {
                    st.pop();
                    destroyed = true;
                    break;
                }
                else {
                    destroyed = true;
                    break;
                }
            }
            if (!destroyed) st.push(x);
        }

        vector<int> ans;
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};

int main() {
    vector<int> arr = { 5,10,-10 };
    Solution obj;
    vector<int> ans = obj.asteroidCollision(arr);
    for (auto i : ans)cout << i << " ";
    return 0;
}