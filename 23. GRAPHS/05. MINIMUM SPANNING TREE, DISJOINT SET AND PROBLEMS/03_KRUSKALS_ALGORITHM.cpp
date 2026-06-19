/*
====================================================
KRUSKAL'S ALGORITHM
====================================================

💡 PROBLEM SUMMARY
----------------------------------------------------
Kruskal's Algorithm is used to find:

✔ Minimum Spanning Tree (MST)

----------------------------------------------------
MST means:

✔ Connect all nodes
✔ No cycles
✔ Minimum total edge weight

====================================================
CORE IDEA: GREEDY + DISJOINT SET ⭐
----------------------------------------------------
Kruskal's Algorithm works on:

✔ Greedy approach
✔ Disjoint Set Union (DSU)

----------------------------------------------------
Greedy choice:
✔ Always pick smallest weight edge first

But:
✔ adding every edge may create cycle

So:
✔ DSU helps detect cycle efficiently

====================================================
MAIN INTUITION
----------------------------------------------------
Suppose edges are:

    1--2 (2)
    2--3 (5)
    1--3 (1)

----------------------------------------------------
We first choose:
✔ minimum weight edge

So order becomes:

    (1--3) weight 1
    (1--2) weight 2
    (2--3) weight 5

----------------------------------------------------
Now:
✔ include edges only if they
  connect DIFFERENT components

====================================================
WHY DISJOINT SET IS REQUIRED ⭐
----------------------------------------------------
Before adding edge:

    u ----- v

We check:

✔ Do u and v already belong
  to same component?

----------------------------------------------------
If YES:
✔ adding edge creates cycle
✔ skip it

If NO:
✔ safe to include
✔ merge components

====================================================
HOW DSU HELPS
----------------------------------------------------
DSU provides:

✔ findUPar(node)
      → finds ultimate parent

✔ union(u,v)
      → merges components

----------------------------------------------------
If:

    findUPar(u) == findUPar(v)

Then:
✔ both already connected

====================================================
WHY SORTING IS IMPORTANT
----------------------------------------------------
Kruskal always works greedily.

So:
✔ process edges in increasing order
  of weight

----------------------------------------------------
Smallest edges are always considered first.

====================================================
APPROACH
----------------------------------------------------

STEP 1: Store all edges
----------------------------------------------------
Store edges as:

    {weight, {u, v}}

Why?
----------------------------------------------------
Because sorting automatically
sorts by weight first.

----------------------------------------------------

STEP 2: Sort edges
----------------------------------------------------
✔ Smallest weight edge comes first

----------------------------------------------------

STEP 3: Traverse edges
----------------------------------------------------
For every edge:

✔ Check ultimate parents

----------------------------------------------------

STEP 4: Include edge if safe
----------------------------------------------------
If:
    parents are different

Then:
✔ include edge in MST
✔ add weight
✔ merge components

Otherwise:
✔ skip edge

====================================================
IMPORTANT CONDITIONS
----------------------------------------------------
✔ Graph should be connected
✔ DSU prevents cycles
✔ Sorting is mandatory
✔ Greedy choice ensures MST

====================================================
PRIM'S vs KRUSKAL'S
----------------------------------------------------
PRIM'S:
✔ Node based expansion

KRUSKAL'S:
✔ Edge based expansion

----------------------------------------------------
Prim's:
✔ Uses Priority Queue

Kruskal's:
✔ Uses Sorting + DSU

====================================================
TIME & SPACE COMPLEXITY
----------------------------------------------------
TIME:
➡ O(E log E)

Sorting dominates complexity.

----------------------------------------------------
SPACE:
➡ O(V + E)

====================================================
KEY TAKEAWAY
----------------------------------------------------
Whenever problem asks:
✔ Minimum Spanning Tree

Think:
✔ Prim's Algorithm
✔ Kruskal's Algorithm

----------------------------------------------------
Kruskal's main philosophy:

✔ Take smallest edge first
✔ Avoid cycles using DSU

====================================================
*/

#include<bits/stdc++.h>
using namespace std;

class DisjointSet {

    vector<int> rank, parent, size;

public:

    DisjointSet(int n) {

        rank.resize(n + 1, 0);
        parent.resize(n + 1, 0);
        size.resize(n + 1, 1);

        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findUPar(int node) {

        if (node == parent[node]) {
            return node;
        }

        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {

        int ulp_u = parent[u];
        int ulp_v = parent[v];

        if (ulp_u == ulp_v) {
            return;
        }

        if (rank[ulp_u] < rank[ulp_v]) {

            parent[ulp_u] = ulp_v;

        }
        else if (rank[ulp_v] < rank[ulp_u]) {

            parent[ulp_v] = ulp_u;

        }
        else {

            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v) {

        int ulp_u = parent[u];
        int ulp_v = parent[v];

        if (ulp_u == ulp_v) {
            return;
        }

        if (size[ulp_u] < size[ulp_v]) {

            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];

        }
        else {

            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
public:

    int spanningTree(int V, vector<vector<int>> adj[]) {

        vector<pair<int, pair<int, int>>> edges;

        for (int i = 0; i < V; i++) {

            for (auto it : adj[i]) {

                int adjNode = it[0];
                int wt = it[1];
                int node = i;

                edges.push_back({ wt, {node, adjNode} });
            }
        }

        DisjointSet ds(V);

        sort(edges.begin(), edges.end());

        int mstWt = 0;

        for (auto it : edges) {

            int wt = it.first;
            int u = it.second.first;
            int v = it.second.second;

            if (ds.findUPar(u) != ds.findUPar(v)) {

                mstWt += wt;

                ds.unionBySize(u, v);
            }
        }

        return mstWt;
    }
};

int main() {

    return 0;
}