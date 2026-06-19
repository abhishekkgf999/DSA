/*
====================================================
BELLMAN FORD ALGORITHM
====================================================

💡 PROBLEM SUMMARY
----------------------------------------------------
Bellman Ford Algorithm is used for:

✔ Finding shortest distance from
  source node to every node

✔ Detecting negative weight cycles

----------------------------------------------------
Unlike Dijkstra:

✔ Bellman Ford CAN work with
  negative edge weights

====================================================
CORE IDEA: EDGE RELAXATION ⭐
----------------------------------------------------
Bellman Ford works on one simple idea:

✔ Repeatedly relax all edges

----------------------------------------------------
Relaxation means:
----------------------------------------------------
If:

    dist[u] + wt < dist[v]

Then:
✔ We found a shorter path to v

So update:
    dist[v] = dist[u] + wt

====================================================
WHY V-1 ITERATIONS ?
----------------------------------------------------
In worst case:

✔ Shortest path may contain
  maximum V-1 edges

Example:
----------------------------------------------------
1 → 2 → 3 → 4 → 5

To correctly propagate shortest distance
through dependency chain,
we need:
✔ V-1 relaxations

----------------------------------------------------
After V-1 iterations:
✔ all shortest distances stabilize

====================================================
NEGATIVE CYCLE DETECTION ⭐
----------------------------------------------------
After completing V-1 relaxations:

✔ Run ONE EXTRA iteration

----------------------------------------------------
If any edge still relaxes:

    dist[u] + wt < dist[v]

Then:
✔ distance can still decrease

Meaning:
✔ negative cycle exists

----------------------------------------------------
Why?
----------------------------------------------------
Because shortest distances should
already be finalized after V-1 iterations.

If still improving:
✔ cycle is continuously reducing distance

====================================================
WHY DIJKSTRA FAILS FOR NEGATIVE WEIGHTS
----------------------------------------------------
Dijkstra assumes:
✔ once shortest distance is fixed,
  it never improves

Negative edges break this assumption.

----------------------------------------------------
Bellman Ford avoids this issue by:
✔ repeatedly relaxing all edges

====================================================
APPROACH
----------------------------------------------------

STEP 1: Initialize distance array
----------------------------------------------------
✔ dist[i] = INF

✔ dist[source] = 0

----------------------------------------------------

STEP 2: Relax all edges V-1 times
----------------------------------------------------
For every iteration:

✔ Traverse all edges

✔ Relax whenever shorter path found

----------------------------------------------------

STEP 3: Detect negative cycle
----------------------------------------------------
Run one more iteration:

✔ If any edge relaxes again:
      return {-1}

Otherwise:
✔ no negative cycle

====================================================
IMPORTANT CONDITIONS
----------------------------------------------------
✔ Works with negative weights
✔ Detects negative cycles
✔ Graph can be directed
✔ Relax all edges V-1 times
✔ Extra iteration used for cycle detection

====================================================
TIME & SPACE COMPLEXITY
----------------------------------------------------
TIME:
➡ O(V × E)

SPACE:
➡ O(V)

====================================================
KEY TAKEAWAY
----------------------------------------------------
Whenever graph contains:
✔ negative edge weights

Think:
✔ Bellman Ford

Whenever problem asks:
✔ detect negative cycle

Think:
✔ extra relaxation iteration

====================================================
*/

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    
        vector<int> bellman_ford(int V, vector<vector<int>> &edges, int S){
            vector<int> dist(V, 1e8);

            dist[S] = 0;

            for(int i = 0; i < V; i++){

                for(auto it : edges){

                    int u = it[0];
                    int v = it[1];
                    int wt = it[2];

                    if(dist[u] != 1e8 && dist[u] + wt < dist[v]){
                        dist[v] = dist[u] + wt;
                    }
                }
            }
            
            for(auto it : edges){

                int u = it[0];
                int v = it[1];
                int wt = it[2];

                if(dist[u] != 1e8 && dist[u] + wt < dist[v]){
                    return {-1};
                }
            }

            return dist;
        }
};

int main(){
    
    return 0;
}