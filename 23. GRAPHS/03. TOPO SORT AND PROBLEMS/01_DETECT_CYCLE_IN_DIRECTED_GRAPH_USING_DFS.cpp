/*
====================================================
DETECT CYCLE IN DIRECTED GRAPH (DFS)
====================================================

💡 PROBLEM SUMMARY
- Given:
    • A directed graph (adjacency list)

Goal:
✔ Detect whether the graph contains a cycle

Return:
✔ true  → if cycle exists
✔ false → otherwise

====================================================
KEY IDEA: DFS + PATH VISITATION TRACKING 🔁
----------------------------------------------------
In a directed graph:

✔ A cycle exists if we revisit a node
  that is already part of the current DFS path

So we maintain two arrays:

1️⃣ vis[]      → marks nodes that are visited overall
2️⃣ pathVis[]  → marks nodes in current DFS path

Cycle condition:
✔ If we encounter a node that is already
  marked in pathVis → cycle detected

====================================================
WHY THIS WORKS
----------------------------------------------------
✔ vis[] ensures we don’t process the same node again
✔ pathVis[] helps detect back-edge in DFS

Back-edge:
✔ Edge pointing to an ancestor in current DFS path
✔ This directly indicates a cycle

====================================================
APPROACH
----------------------------------------------------
STEP 1: Initialize arrays
----------------------------------------------------
vis[i] = 0       → node not visited
pathVis[i] = 0   → node not in current path

----------------------------------------------------

STEP 2: Traverse all nodes
----------------------------------------------------
Graph may be disconnected.

For every node:
    if not visited → start DFS

----------------------------------------------------

STEP 3: DFS Traversal
----------------------------------------------------
For current node:

✔ Mark:
    vis[node] = 1
    pathVis[node] = 1

✔ Traverse all adjacent nodes

Case 1:
    If neighbour NOT visited:
        → recursively call DFS

Case 2:
    If neighbour is already in pathVis:
        → cycle detected → return true

----------------------------------------------------

STEP 4: Backtracking
----------------------------------------------------
After exploring all neighbours:

✔ Remove node from current path:
    pathVis[node] = 0

✔ Return false if no cycle found from this path

====================================================
IMPORTANT CONDITIONS
----------------------------------------------------
✔ Directed graph only (logic differs for undirected)
✔ Cycle exists if we revisit node in same DFS path
✔ pathVis is reset during backtracking
✔ vis ensures each node is processed once

====================================================
TIME & SPACE ANALYSIS
----------------------------------------------------
TIME COMPLEXITY:
➡ O(V + E)

SPACE COMPLEXITY:
➡ O(V)
(for vis + pathVis + recursion stack)

====================================================
KEY TAKEAWAY
----------------------------------------------------
To detect cycle in directed graph:

✔ Use DFS
✔ Track current path using pathVis[]
✔ If a node is revisited in same path → cycle exists

This detects cycles via back-edges in DFS.
====================================================
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    bool dfsCheck(int node, vector<int> adj[], int vis[], int pathVis[]) {
        vis[node] = 1;
        pathVis[node] = 1;

        for (auto it : adj[node]) {
            if (!vis[it]) {
                if (dfsCheck(it, adj, vis, pathVis) == true) return true;
            }
            else if (pathVis[it]) {
                return true;
            }
        }

        pathVis[node] = 0;
        return false;
    }
public:
    bool isCyclic(int V, vector<int> adj[]) {
        int vis[V] = { 0 };
        int pathVis[V] = { 0 };

        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                if (dfsCheck(i, adj, vis, pathVis) == true) return true;
            }
        }

        return false;
    }
};

int main() {

    return 0;
}