/*
====================================================
ARTICULATION POINT IN GRAPH (TARJAN'S ALGORITHM)
GeeksForGeeks:
https://www.geeksforgeeks.org/problems/articulation-point2616/1
====================================================

💡 PROBLEM SUMMARY
----------------------------------------------------
Given:

✔ An undirected graph

Goal:

✔ Find all Articulation Points

----------------------------------------------------
Articulation Point:

A node whose removal increases
the number of connected components
in the graph.

OR

Removing that node disconnects
some part of the graph.

====================================================
CORE INTUITION ⭐
----------------------------------------------------
This problem is very similar to:

✔ Bridges in Graph

The only difference:

Bridge:
    Remove Edge

Articulation Point:
    Remove Node

----------------------------------------------------
Again we use:

✔ tin[]  → discovery time

✔ low[]  → lowest reachable
            discovery time

====================================================
WHAT IS tin[] ?
----------------------------------------------------
tin[node]

✔ Time at which node is first visited

Example:

DFS Order:

    0 → 1 → 2 → 3

Then:

    tin[0] = 0
    tin[1] = 1
    tin[2] = 2
    tin[3] = 3

====================================================
WHAT IS low[] ?
----------------------------------------------------
low[node]

✔ Lowest discovery time reachable
  from that node

----------------------------------------------------
Can be reached through:

✔ Child edges

✔ Back edges

====================================================
MAIN QUESTION ⭐
----------------------------------------------------
Suppose:

    node → child

After DFS of child:

Can child (or its subtree)
reach any ancestor of node
without using node?

----------------------------------------------------
If NO:

Then removing node will disconnect
that entire subtree.

Therefore:

✔ node becomes articulation point

====================================================
ARTICULATION POINT CONDITION ⭐⭐⭐
----------------------------------------------------
For non-root nodes:

If:

    low[child] >= tin[node]

Then:

✔ child cannot reach any ancestor
  of node

✔ node acts as the only connection

Therefore:

✔ node is articulation point

----------------------------------------------------
Formula:

    low[child] >= tin[node]

====================================================
WHY '>=' AND NOT '>' ?
----------------------------------------------------
For Bridges:

    low[child] > tin[node]

----------------------------------------------------
For Articulation Point:

    low[child] >= tin[node]

----------------------------------------------------
Because:

Even if child reaches node itself
and cannot go above it,

removing node still disconnects
the child subtree.

====================================================
SPECIAL CASE: ROOT NODE ⭐
----------------------------------------------------
Root node follows a different rule.

----------------------------------------------------
If root has:

    child > 1

Then:

✔ Root is articulation point

Why?

Because:

Removing root separates
multiple DFS branches.

----------------------------------------------------
Condition:

    child > 1 && parent == -1

====================================================
WHY CHILD COUNT IS REQUIRED ?
----------------------------------------------------
Example:

        0
       / \
      1   2

----------------------------------------------------
Root has:

2 DFS branches

Removing 0:

    1     2

Graph becomes disconnected.

Hence:

✔ Articulation Point

====================================================
BACK EDGE CASE
----------------------------------------------------
If neighbour already visited:

✔ Back edge found

Update:

    low[node] =
        min(low[node], tin[it])

----------------------------------------------------
We use:

    tin[it]

because:

✔ we want discovery time
  of already visited ancestor

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
    mark[]

----------------------------------------------------

STEP 3:
✔ Start DFS

----------------------------------------------------

STEP 4:
✔ Calculate tin and low

----------------------------------------------------

STEP 5:
✔ Update low after child DFS

----------------------------------------------------

STEP 6:
✔ Check articulation condition

    low[child] >= tin[node]

----------------------------------------------------

STEP 7:
✔ Handle root separately

    child > 1

----------------------------------------------------

STEP 8:
✔ Return all marked nodes

====================================================
IMPORTANT CONDITIONS
----------------------------------------------------
✔ Graph is UNDIRECTED

✔ Skip parent edge

✔ Root handled separately

✔ Articulation condition:

      low[child] >= tin[node]

✔ Root condition:

      child > 1

====================================================
TIME & SPACE COMPLEXITY
----------------------------------------------------
TIME:
➡ O(V + E)

Each node and edge
visited once.

----------------------------------------------------
SPACE:
➡ O(V + E)

Adjacency list +
DFS recursion stack

====================================================
KEY TAKEAWAY
----------------------------------------------------
Tarjan's Algorithm uses:

✔ Discovery Time (tin)

✔ Lowest Reachable Time (low)

----------------------------------------------------
For Bridges:

    low[child] > tin[parent]

----------------------------------------------------
For Articulation Points:

    low[child] >= tin[node]

----------------------------------------------------
Special Root Rule:

    DFS Children > 1

====================================================
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    int timer = 0;
    void dfs(int node, int parent, vector<int> &vis, int tin[], int low[], vector<int> &mark, vector<int> adj[]){
        vis[node] = 1;
        tin[node] = low[node] = timer;
        timer++;
        int child = 0;
        for(auto it : adj[node]){
            if(it == parent) continue;
            if(!vis[it]){
                dfs(it, node, vis, tin, low, mark, adj);
                low[node] = min(low[node], low[it]);
                if(low[it] >= tin[node] && parent != -1){
                    mark[node] = 1;
                }
                child++;
            }else{
                low[node] = min(low[node], tin[it]);
            }
        }
        
        if(child > 1 && parent == -1){
            mark[node] = 1;
        }
    }
  public:
    vector<int> articulationPoints(int V, vector<vector<int>>& edges) {
        vector<int> vis(V, 0);
        int tin[V];
        int low[V];
        vector<int> mark(V, 0);
        vector<int> adj[V];
        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        for(int i = 0; i<V; i++){
            if(!vis[i]){
                dfs(i, -1, vis, tin, low, mark, adj);
            }
        }
        
        vector<int> ans;
        for(int i = 0; i<V; i++){
            if(mark[i] == 1) ans.push_back(i);
        }
        
        if(ans.size() == 0) return {-1};
        
        return ans;
    }
};

int main(){
    
    return 0;
}