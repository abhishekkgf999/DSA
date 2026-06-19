/*
====================================================
MINIMUM MULTIPLICATION TO REACH END
GeeksforGeeks:
https://www.geeksforgeeks.org/problems/minimum-multiplications-to-reach-end/0
====================================================

💡 PROBLEM SUMMARY
----------------------------------------------------
- Given:
    • An array of numbers
    • start value
    • end value

Operation:
✔ From current number:
      multiply with any array element

✔ After multiplication:
      take modulo 1000

Goal:
✔ Find minimum operations required
  to reach end from start

✔ If impossible → return -1

====================================================
CORE IDEA: GRAPH + SHORTEST PATH ⭐
----------------------------------------------------
This problem may look mathematical,
but internally it behaves exactly like
a GRAPH shortest path problem.

----------------------------------------------------
Think of:
✔ every number as a node

Transition:
----------------------------------------------------
From current node:
    x

We can move to:
    (x * arr[i]) % 1000

So:
✔ multiplication operation creates edges

====================================================
IMPORTANT OBSERVATION
----------------------------------------------------
Since modulo = 1000:

Possible values are only:
    0 → 999

So total possible nodes:
✔ only 1000

This is the MOST IMPORTANT observation.

----------------------------------------------------
That means:
✔ finite graph exists
✔ shortest path traversal possible

====================================================
WHY BFS / DIJKSTRA WORKS
----------------------------------------------------
Every operation costs:
✔ exactly 1 step

So:
✔ every edge weight is same

Hence:
✔ BFS is enough

This solution uses:
✔ Priority Queue based traversal
  (Dijkstra style)

which also works correctly.

====================================================
APPROACH
----------------------------------------------------

STEP 1: Create steps array
----------------------------------------------------
✔ steps[i]
    = minimum operations required
      to reach node i

Initialize:
    INT_MAX

because initially:
✔ every node is unreachable

----------------------------------------------------

STEP 2: Start traversal
----------------------------------------------------
✔ start node requires:
      0 operations

Push into PQ:
    {steps, node}

----------------------------------------------------

STEP 3: Generate neighbours
----------------------------------------------------
For every array element:

Generate:
    newNode = (node * arr[i]) % 1000

This becomes:
✔ neighbouring node

----------------------------------------------------

STEP 4: Relaxation
----------------------------------------------------
If:
    newStep < stored steps

Then:
✔ update minimum steps
✔ push into PQ

----------------------------------------------------

STEP 5: Early stopping
----------------------------------------------------
Whenever:
✔ end node is popped first time

That guarantees:
✔ minimum operations

because PQ always processes
smaller step count first.

----------------------------------------------------

STEP 6: Final check
----------------------------------------------------
✔ If end remains unreachable:
      return -1

Otherwise:
✔ return minimum steps

====================================================
IMPORTANT CONDITIONS
----------------------------------------------------
✔ Nodes range from 0 → 999
✔ Modulo operation is compulsory
✔ Same node may appear multiple times
✔ Skip outdated PQ entries
✔ Every operation costs 1

====================================================
TIME & SPACE COMPLEXITY
----------------------------------------------------
TIME:
➡ O(1000 × N log 1000)

SPACE:
➡ O(1000)

====================================================
KEY TAKEAWAY
----------------------------------------------------
Whenever problem involves:
✔ transforming numbers
✔ minimum operations
✔ finite states

Think:
✔ Graph traversal

Here:
✔ numbers become nodes
✔ operations become edges

====================================================
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int minSteps(vector<int>& arr, int start, int end) {
        vector<int> steps(1000, INT_MAX);

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        pq.push({0, start});

        steps[start] = 0; 
        
        while(!pq.empty()){
            auto [s, node] = pq.top();
            pq.pop();
            
            if(node == end) return steps[end];
            
            if(steps[node] < s) continue;
            
            for(int i = 0; i<arr.size(); i++){
                int newNode = (node * arr[i]) % 1000;
                int newStep = steps[node] + 1;

                if(newStep < steps[newNode]){
                    steps[newNode] = newStep;
                    pq.push({newStep, newNode});
                }
            }
        }
        
        return steps[end] == INT_MAX ? -1 : steps[end];
    }
};

int main(){
    
    return 0;
}