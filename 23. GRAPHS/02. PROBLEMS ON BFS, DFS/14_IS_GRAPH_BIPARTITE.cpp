/*
====================================================
IS GRAPH BIPARTITE
LeetCode:
https://leetcode.com/problems/is-graph-bipartite/description/
====================================================

💡 PROBLEM SUMMARY
- Given an undirected graph (adjacency list)

Goal:
✔ Check whether the graph can be divided into
  two independent sets such that:

    • No two nodes within the same set are connected
    • Every edge connects nodes from different sets

If possible → graph is bipartite  
Else → not bipartite

====================================================
KEY IDEA: GRAPH COLORING (2-COLORING) 🎨
----------------------------------------------------
We try to color the graph using 2 colors:
    0 and 1

Rule:
✔ Adjacent nodes must have different colors

If at any point:
    two adjacent nodes have same color
    → graph is NOT bipartite

If successfully colored:
    → graph is bipartite

====================================================
WHY THIS WORKS
----------------------------------------------------
A graph is bipartite if and only if:
✔ it can be colored using 2 colors
✔ without conflicts

This is equivalent to:
✔ no odd-length cycle exists

====================================================
APPROACH (BFS)
----------------------------------------------------
STEP 1: Initialize
----------------------------------------------------
Create a color array:
    -1 → unvisited
     0 → color A
     1 → color B

----------------------------------------------------

STEP 2: Handle disconnected graph
----------------------------------------------------
Graph may have multiple components.

So for every node:
    if not colored → start BFS

----------------------------------------------------

STEP 3: BFS Traversal
----------------------------------------------------
✔ Start with any node
✔ Assign color = 0
✔ Push into queue

While queue not empty:
    - Take current node
    - Traverse all neighbours

For each neighbour:
    ✔ If same color → return false
    ✔ If unvisited:
          assign opposite color
          push into queue

----------------------------------------------------

STEP 4: If no conflicts found
----------------------------------------------------
Return true

====================================================
APPROACH (DFS)
----------------------------------------------------
Instead of BFS, we can use DFS:

✔ Assign color to current node
✔ Visit all neighbours recursively

For each neighbour:
    ✔ If same color → return false
    ✔ If unvisited:
          call DFS with opposite color

If all recursive calls succeed:
    → graph is bipartite

====================================================
IMPORTANT CONDITIONS
----------------------------------------------------
✔ Graph may be disconnected → check all nodes
✔ Use -1 to mark unvisited nodes
✔ Colors alternate between 0 and 1
✔ Conflict occurs if:
      color[u] == color[v]

====================================================
TIME & SPACE ANALYSIS
----------------------------------------------------
TIME COMPLEXITY:
➡ O(V + E)
(V = vertices, E = edges)

SPACE COMPLEXITY:
➡ O(V)
(for color array + queue/recursion stack)

====================================================
KEY TAKEAWAY
----------------------------------------------------
Bipartite graph = can be colored using 2 colors
such that no adjacent nodes share the same color.

If conflict appears → not bipartite.

This can be checked using either BFS or DFS.
====================================================
*/

#include<bits/stdc++.h>
using namespace std;

class Solution_bfs {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> color(V, -1);

        for (int i = 0; i < V; i++) {
            if (color[i] != -1) continue;

            queue<int> q;
            q.push(i);
            color[i] = 0;

            while (!q.empty()) {
                int node = q.front();
                q.pop();

                for (auto& it : graph[node]) {
                    if (color[it] == color[node])
                        return false;

                    if (color[it] == -1) {
                        color[it] = 1 - color[node];
                        q.push(it);
                    }
                }
            }
        }

        return true;
    }
};

class Solution_dfs {
public:
    bool dfs(vector<vector<int>>& graph, int curr, vector<int> &color, int currColor){
        color[curr] = currColor;

        for(auto &it: graph[curr]){
            if(color[it] == currColor) return false;

            if(color[it] == -1){
                int colorOfV = (currColor == 1 ? 0 : 1);
                if(dfs(graph, it, color, colorOfV) == false) return false;
            }
        }

        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> color(V, -1);

        for(int i = 0; i<V; i++){
            if(color[i] == -1){
                if(dfs(graph, i, color, 1) == false) return false;
            }
        }

        return true;
    }
};

int main(){
    vector<vector<int>> graph = {{}, {2,4,6}, {1,2,8,9}, {7,8}, {1,2,8,9}, {6,9}, {1,5,7,8,9}, {3,6,9}, {2,3,4,6,9}, {2,4,5,6,7,8}};

    return 0;
}