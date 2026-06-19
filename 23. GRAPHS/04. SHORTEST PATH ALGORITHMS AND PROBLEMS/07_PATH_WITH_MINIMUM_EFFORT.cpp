/*
====================================================
PATH WITH MINIMUM EFFORT
LeetCode:
https://leetcode.com/problems/path-with-minimum-effort/
====================================================

💡 PROBLEM SUMMARY
----------------------------------------------------
- Given:
    • A grid of heights

Goal:
✔ Move from (0,0) → (n-1,m-1)

✔ Effort of a path =
    maximum absolute difference between
    adjacent cells in that path

✔ Return minimum possible effort

====================================================
CORE IDEA: DIJKSTRA WITH MODIFIED COST ⭐
----------------------------------------------------
This is NOT normal shortest path.

Instead of:
    sum of weights

We minimize:
    maximum edge weight in path

----------------------------------------------------
So:
✔ Path cost = max(edge differences)

This is called:
✔ "Minimize the maximum edge weight"

====================================================
KEY INSIGHT
----------------------------------------------------
Normal Dijkstra:
    dist[u] + weight

Here:
    new_effort = max(current_effort, edge_weight)

Why?
----------------------------------------------------
Because:
✔ Path effort depends on the WORST edge

So even if previous path is small,
a big jump increases total effort.

====================================================
WHY DIJKSTRA WORKS HERE
----------------------------------------------------
✔ Greedy property still holds

✔ Once we reach a node with minimum effort,
  it won't improve later

✔ Hence Dijkstra is valid

====================================================
APPROACH
----------------------------------------------------

STEP 1: Initialize
----------------------------------------------------
✔ effort[i][j] = ∞
✔ effort[0][0] = 0

✔ Min heap:
    {effort, i, j}

----------------------------------------------------

STEP 2: Dijkstra traversal
----------------------------------------------------
While PQ not empty:

✔ Extract cell with minimum effort

✔ Skip outdated entries

✔ Explore 4 directions

----------------------------------------------------

STEP 3: Relaxation
----------------------------------------------------
For neighbour:

✔ edge weight =
    abs(height difference)

✔ new_effort =
    max(current effort, edge weight)

✔ If new_effort < stored effort:
      update and push into PQ

----------------------------------------------------

STEP 4: Final answer
----------------------------------------------------
✔ Return effort[n-1][m-1]

====================================================
IMPORTANT CONDITIONS
----------------------------------------------------
✔ Movement allowed in 4 directions
✔ Use max() instead of addition
✔ Always skip outdated PQ entries
✔ No need for visited array

====================================================
TIME & SPACE COMPLEXITY
----------------------------------------------------
TIME:
➡ O((N × M) log(N × M))

SPACE:
➡ O(N × M)

====================================================
KEY TAKEAWAY
----------------------------------------------------
Whenever problem says:
✔ "minimize the maximum cost"

Think:
✔ Modified Dijkstra

Replace:
    +
with:
    max()

====================================================
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    struct compare{
        bool operator()(vector<int> a, vector<int> b){
            return a[0] > b[0];
        }
    };
    int minimumEffortPath(vector<vector<int>>& heights) {
        int row = heights.size();
        int col = heights[0].size();
        vector<vector<int>> effort(row, vector<int>(col, INT_MAX));
        priority_queue<vector<int>, vector<vector<int>>, compare> pq;

        effort[0][0] = 0;
        pq.push({0, 0, 0});

        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};

        while(!pq.empty()){
            int k = pq.size();
            while(k--){
                int d = pq.top()[0];
                int i = pq.top()[1];
                int j = pq.top()[2];
                pq.pop();

                if(d > effort[i][j]) continue;
                
                for(int it = 0; it<4; it++){
                    int ni = i + dx[it];
                    int nj = j + dy[it];

                    if(ni >=0 && ni<row && nj>=0 && nj<col && heights[ni][nj] > 0){
                        int new_effort = max(d, abs(heights[i][j] - heights[ni][nj]));

                        if(new_effort < effort[ni][nj]){
                            effort[ni][nj] = new_effort;
                            pq.push({new_effort, ni, nj});
                        }
                    }
                }
            }
        }

        return effort[row-1][col-1];
    }
};

int main(){
    
    return 0;
}