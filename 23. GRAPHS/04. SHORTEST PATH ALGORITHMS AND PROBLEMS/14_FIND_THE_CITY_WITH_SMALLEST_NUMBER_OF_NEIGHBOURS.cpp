/*
====================================================
FIND THE CITY WITH SMALLEST NUMBER OF NEIGHBOURS

LeetCode:
https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/description/
====================================================

💡 PROBLEM SUMMARY
----------------------------------------------------
- Given:
    • Weighted UNDIRECTED graph
    • distanceThreshold

Goal:
✔ For every city:
      count how many cities are reachable
      within distanceThreshold

✔ Return the city having:
      minimum reachable cities

✔ If multiple cities have same answer:
      return city with GREATER index

====================================================
CORE IDEA: ALL PAIRS SHORTEST PATH ⭐
----------------------------------------------------
For every city:
✔ We need shortest distance
  to every other city

This becomes:
✔ Multi-source shortest path problem

----------------------------------------------------
Best algorithm here:
✔ Floyd Warshall

Because:
✔ It computes shortest distance
  between every pair of nodes

====================================================
WHY FLOYD WARSHALL ?
----------------------------------------------------
We need:

    every node → every node

shortest distance.

----------------------------------------------------
Dijkstra from every node would also work,
but Floyd Warshall is simpler here because:

✔ Constraints are small
✔ Direct all-pairs computation

====================================================
KEY INSIGHT
----------------------------------------------------
After Floyd Warshall:

✔ mat[i][j]
    = shortest distance from i to j

Then:
✔ simply count how many nodes
  satisfy:

    mat[i][j] <= distanceThreshold

====================================================
IMPORTANT TIE CONDITION ⭐
----------------------------------------------------
Question says:

If multiple cities have same minimum count:
✔ return city with larger index

----------------------------------------------------
So while updating answer:

Use:
    if(cnt <= mini)

NOT:
    if(cnt < mini)

Because:
✔ later city index should overwrite
  previous answer in tie case

====================================================
APPROACH
----------------------------------------------------

STEP 1: Initialize matrix
----------------------------------------------------
✔ Initialize all distances = INF

✔ distance from node to itself = 0

----------------------------------------------------

STEP 2: Insert edges
----------------------------------------------------
Since graph is UNDIRECTED:

    u ↔ v

Store both directions.

----------------------------------------------------

STEP 3: Apply Floyd Warshall
----------------------------------------------------
For every intermediate node k:

✔ Try improving:
      u → v
  via:
      u → k → v

----------------------------------------------------

STEP 4: Count reachable cities
----------------------------------------------------
For every city:

✔ Count nodes satisfying:
      shortest distance <= threshold

----------------------------------------------------

STEP 5: Track minimum
----------------------------------------------------
✔ Store city with minimum count

✔ In tie:
      choose larger city number

====================================================
IMPORTANT CONDITIONS
----------------------------------------------------
✔ Graph is UNDIRECTED
✔ Need shortest path between all pairs
✔ Tie case prefers larger index
✔ Floyd Warshall uses adjacency matrix

====================================================
TIME & SPACE COMPLEXITY
----------------------------------------------------
TIME:
➡ O(N³)

SPACE:
➡ O(N²)

====================================================
KEY TAKEAWAY
----------------------------------------------------
Whenever problem asks:
✔ shortest distance between all pairs

Think:
✔ Floyd Warshall

Whenever question involves:
✔ threshold-based reachability

Compute:
✔ all-pairs shortest path first

====================================================
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {

        vector<vector<int>> mat(n, vector<int>(n, 1e9));

        for (int i = 0; i < n; i++) {
            mat[i][i] = 0;
        }

        for (auto it : edges) {

            int u = it[0];
            int v = it[1];
            int wt = it[2];

            mat[u][v] = wt;
            mat[v][u] = wt;
        }

        for (int k = 0; k < n; k++) {

            for (int u = 0; u < n; u++) {

                for (int v = 0; v < n; v++) {

                    mat[u][v] = min(
                        mat[u][v],
                        mat[u][k] + mat[k][v]
                    );
                }
            }
        }

        int ans = 0;
        int mini = INT_MAX;

        for (int i = 0; i < n; i++) {

            int cnt = 0;

            for (int j = 0; j < n; j++) {

                if (i != j && mat[i][j] <= distanceThreshold) {
                    cnt++;
                }
            }

            if (cnt <= mini) {
                mini = cnt;
                ans = i;
            }
        }

        return ans;
    }
};

int main() {

    return 0;
}