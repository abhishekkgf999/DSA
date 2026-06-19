/*
====================================================
SHORTEST PATH IN BINARY MATRIX
LeetCode:
https://leetcode.com/problems/shortest-path-in-binary-matrix/description/
====================================================

💡 PROBLEM SUMMARY
- Given:
    • A binary matrix (0 = open, 1 = blocked)

Goal:
✔ Find shortest path from (0,0) → (n-1,n-1)

Rules:
✔ Movement allowed in 8 directions
✔ Path can only pass through cells with value 0
✔ Return length of shortest path
✔ If not reachable → return -1

====================================================
KEY IDEA
----------------------------------------------------
Two approaches:

1️⃣ Dijkstra (General shortest path)
2️⃣ BFS (Optimized for unit weight edges) ⭐

Since:
✔ All moves cost = 1

→ BFS is optimal and faster

====================================================
APPROACH 1: DIJKSTRA (GENERAL SOLUTION)
----------------------------------------------------
✔ Treat each cell as a node
✔ Each move has weight = 1

Use:
✔ Min heap to always expand shortest distance node

----------------------------------------------------

STEPS:
✔ Maintain dist matrix
✔ Initialize dist[0][0] = 0
✔ Push {distance, i, j} into PQ

✔ For each cell:
      explore all 8 directions

✔ If shorter distance found:
      update and push into PQ

----------------------------------------------------

FINAL:
✔ Return dist[n-1][n-1] + 1
✔ If unreachable → return -1

----------------------------------------------------

NOTE:
✔ Works but slower than BFS for this problem

====================================================
APPROACH 2: BFS (OPTIMAL) ⭐
----------------------------------------------------
Since all edges have equal weight:

✔ Use BFS instead of Dijkstra

Key idea:
✔ Each BFS level = path length

----------------------------------------------------

STEPS:
----------------------------------------------------
STEP 1: Check validity
✔ If start or end is blocked → return -1

----------------------------------------------------

STEP 2: Initialize BFS
✔ Queue stores coordinates
✔ Start from (0,0)

✔ Mark visited by changing grid value

----------------------------------------------------

STEP 3: BFS Traversal
----------------------------------------------------
For each level:

✔ Increase distance (d)

✔ Process all nodes at that level

✔ For each node:
      explore 8 directions

✔ If valid and unvisited:
      mark visited
      push into queue

----------------------------------------------------

STEP 4: Termination
----------------------------------------------------
✔ If (n-1, n-1) reached:
      return distance

✔ If queue empty:
      return -1

====================================================
IMPORTANT CONDITIONS
----------------------------------------------------
✔ Movement allowed in 8 directions
✔ Only traverse cells with value 0
✔ Mark visited to avoid revisiting
✔ BFS guarantees shortest path

====================================================
TIME & SPACE ANALYSIS
----------------------------------------------------
TIME COMPLEXITY:
➡ O(N × N)

SPACE COMPLEXITY:
➡ O(N × N)
(for queue or distance matrix)

====================================================
KEY TAKEAWAY
----------------------------------------------------
✔ Use BFS when all edges have equal weight
✔ Dijkstra is overkill in such cases

Core idea:
✔ Treat grid as graph
✔ Expand level by level to find shortest path

====================================================
*/

#include<bits/stdc++.h>
using namespace std;

/*
----------------------------------------------------
APPROACH 1: DIJKSTRA
----------------------------------------------------
*/
class Solution_Dijkstra_algorithm {
public:
    struct compare {
        bool operator()(vector<int> a, vector<int> b) { return a[0] > b[0]; }
    };
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        if(grid[0][0] == 1 || grid[row-1][col-1]) return -1;

        vector<vector<int>> dist(row, vector<int>(col, 1e9));
        priority_queue<vector<int>, vector<vector<int>>, compare> pq;

        dist[0][0] = 0;

        pq.push({0, 0, 0});

        while (!pq.empty()) {
            int d = pq.top()[0];
            int i = pq.top()[1];
            int j = pq.top()[2];

            pq.pop();

            if (d > dist[i][j])
                continue;

            for (int x = -1; x <= 1; x++) {
                for (int y = -1; y <= 1; y++) {
                    int ni = i + x;
                    int nj = j + y;

                    if (ni == i && nj == j)
                        continue;

                    if (ni >= 0 && nj >= 0 && ni < row && nj < col) {
                        if (grid[ni][nj] == 0 && d + 1 < dist[ni][nj]) {
                            dist[ni][nj] = d + 1;
                            pq.push({dist[ni][nj], ni, nj});
                        }
                    }
                }
            }
        }

        return dist[row-1][col-1] == 1e9 ? -1 : dist[row-1][col-1] + 1;
    }
};

/*
----------------------------------------------------
APPROACH 2: BFS (OPTIMAL)
----------------------------------------------------
*/
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        if(grid[0][0] == 1 || grid[row-1][col-1] == 1) return -1;

        queue<pair<int,int>> q;
        int d = 0;
        q.push({0, 0});

        while(!q.empty()){
            int size = q.size();
            d++;
            while(size--){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();

                if(x == row-1 && y == col-1) return d;

                int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
                int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

                for(int i = 0; i<8; i++){
                    int ni = x + dx[i];
                    int nj = y + dy[i];

                    if(ni >= 0 && nj >=0 && ni<row && nj<col && grid[ni][nj] == 0){
                        grid[ni][nj] = 1;
                        q.push({ni, nj});
                    }
                }
            }
        }

        return -1;
    }
};

int main(){
    
    return 0;
}