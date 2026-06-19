/*
====================================================
BRIDGES IN GRAPH (TARJAN'S ALGORITHM)
LeetCode:
https://leetcode.com/problems/critical-connections-in-a-network/description/
====================================================

💡 PROBLEM SUMMARY
----------------------------------------------------
- Given:
    • Undirected graph

Goal:
✔ Find all critical connections
  (Bridges)

----------------------------------------------------
Bridge means:

✔ An edge whose removal increases
  the number of connected components

OR

✔ Removing that edge disconnects
  some part of the graph

====================================================
CORE INTUITION ⭐
----------------------------------------------------
For every node we want to know:

1️⃣ When did this node get visited?

    → Discovery Time (tin)

2️⃣ Can this node (or its subtree)
    reach an ancestor using some
    other path?

    → Lowest Reachable Time (low)

----------------------------------------------------
These two values completely determine
whether an edge is a bridge or not.

====================================================
WHAT IS tin[] ?
----------------------------------------------------
tin[node]

✔ Time at which node was first visited

Example:

DFS Order:

    0 → 1 → 2 → 3

Then:

    t
    tin[1] = 2
    tin[2] = 3
    tin[3] = 4

====================================================
WHAT IS low[] ? ⭐
----------------------------------------------------
low[node]

✔ Smallest discovery time reachable
  from that in[0] = 1node

----------------------------------------------------
Reachable means:

✔ Through child edges
✔ Through back edges

====================================================
IMPORTANT QUESTION
----------------------------------------------------
Suppose we are standing at node:

    child

Can child reach:

    parent
or
    any ancestor

using another path?

----------------------------------------------------
If YES:

✔ Then edge is NOT a bridge

Because graph remains connected.

----------------------------------------------------
If NO:

✔ Then edge IS a bridge

Because removing it disconnects
the subtree.

====================================================
VISUAL EXAMPLE
----------------------------------------------------

    0
    |
    1
   / \
  2---3

----------------------------------------------------
For node 3:

✔ Can reach node 1
  through another route

    3 → 2 → 1

Therefore:

✔ Edge (1,3)
  is NOT a bridge

====================================================
BRIDGE CONDITION ⭐⭐⭐
----------------------------------------------------
After DFS of child:

If:

    low[child] > tin[parent]

Then:

✔ child cannot reach parent
  or any ancestor

except through this edge.

Therefore:

✔ parent ----- child

is a BRIDGE

----------------------------------------------------
This is the most important line
of Tarjan's Algorithm.

    if(low[child] > tin[parent])

====================================================
WHY DO WE UPDATE LOW ?
----------------------------------------------------
After visiting child:

    node → child

We update:

    low[node] =
        min(low[node], low[child])

----------------------------------------------------
Meaning:

✔ If child can reach some earlier
  ancestor, then parent can also
  use that information.

====================================================
WHY SKIP PARENT ?
----------------------------------------------------
During DFS:

    node → parent

will always exist.

----------------------------------------------------
If we use parent edge again:

✔ every node can trivially reach
  parent

which is meaningless.

----------------------------------------------------
We want:

✔ some OTHER path

not the DFS tree edge itself.

Therefore:

    if(it == parent)
        continue;

====================================================
BACK EDGE CASE ⭐
----------------------------------------------------
Suppose neighbour already visited.

----------------------------------------------------
This means:

✔ back edge found

So update:

    low[node] =
        min(low[node], tin[adj])

----------------------------------------------------
Meaning:

✔ we found another way to reach
  an older ancestor

====================================================
APPROACH
----------------------------------------------------

STEP 1:
✔ Build adjacency list

----------------------------------------------------

STEP 2:
✔ Maintain

    tin[]
    low[]
    visited[]

----------------------------------------------------

STEP 3:
✔ Start DFS

----------------------------------------------------

STEP 4:
✔ Assign

    tin[node]
    low[node]

----------------------------------------------------

STEP 5:
✔ Explore children

----------------------------------------------------

STEP 6:
✔ Update low values

----------------------------------------------------

STEP 7:
✔ Check bridge condition

    low[child] > tin[parent]

----------------------------------------------------

STEP 8:
✔ Store bridge

====================================================
IMPORTANT CONDITIONS
----------------------------------------------------
✔ Graph is UNDIRECTED
✔ Parent edge must be skipped
✔ Back edges update low[]
✔ Bridge condition:

      low[child] > tin[parent]

====================================================
TIME & SPACE COMPLEXITY
----------------------------------------------------
TIME:
➡ O(V + E)

Every edge is processed once.

----------------------------------------------------
SPACE:
➡ O(V + E)

Adjacency list + DFS recursion

====================================================
KEY TAKEAWAY
----------------------------------------------------
Tarjan's Algorithm revolves around:

✔ Discovery Time (tin)

and

✔ Lowest Reachable Time (low)

----------------------------------------------------
Golden Rule:

If a child subtree cannot reach
its parent (or any ancestor)
through another path,

then the connecting edge is
a BRIDGE.

Formula:

    low[child] > tin[parent]

====================================================
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
private:

    int timer = 1;

    void dfs(int node, int parent, vector<int>& vis, vector<int> adj[], int tin[], int low[], vector<vector<int>>& bridges) {

        vis[node] = 1;

        tin[node] = low[node] = timer++;

        for (auto it : adj[node]) {

            if (it == parent) {
                continue;
            }

            if (vis[it] == 0) {

                dfs(it, node, vis, adj, tin, low, bridges);

                low[node] =
                    min(low[node], low[it]);

                if (low[it] > tin[node]) {
                    bridges.push_back({ it, node });
                }
            }
            else {

                low[node] =
                    min(low[node], low[it]);
            }
        }
    }

public:

    vector<vector<int>> criticalConnections(
        int n,
        vector<vector<int>>& connections
    ) {

        vector<int> adj[n];

        for (auto it : connections) {

            int u = it[0];
            int v = it[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> vis(n, 0);

        int tin[n];
        int low[n];

        vector<vector<int>> bridges;

        dfs(0, -1, vis, adj, tin, low, bridges);

        return bridges;
    }
};

int main() {

    int n = 12;

    vector<vector<int>> connections = {
        {1,2}, {1,4}, {2,3}, {3,4},
        {4,5}, {5,6}, {6,7}, {7,8},
        {6,9}, {8,9}, {8,10},
        {10,11}, {10,12}
    };

    Solution obj;

    vector<vector<int>> bridges =
        obj.criticalConnections(n, connections);

    cout << "Critical Connections (Bridges): ";

    for (auto it : bridges) {
        cout << "[" << it[0] << ", "
            << it[1] << "] ";
    }

    cout << endl;

    return 0;
}