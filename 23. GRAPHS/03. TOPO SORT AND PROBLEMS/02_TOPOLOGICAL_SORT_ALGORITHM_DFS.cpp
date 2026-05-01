/*
====================================================
TOPOLOGICAL SORT (DFS BASED) => ONLY VALID IN DIRECTED ACYCLIC GRAPH (DAG)
====================================================

💡 PROBLEM SUMMARY
- Given:
    • A Directed Acyclic Graph (DAG)

Goal:
✔ Return a linear ordering of vertices such that:
    For every directed edge (u → v),
    node u appears before node v

====================================================
KEY IDEA: DFS + STACK (POSTORDER) 📚
----------------------------------------------------
Topological sorting ensures dependency order.

Idea:
✔ Visit nodes using DFS
✔ Only after visiting all its neighbours,
  push the node into a stack

Why?
✔ A node should appear AFTER all nodes
  it points to (dependencies)

So:
✔ Last finished node → appears first in result

====================================================
WHY STACK IS USED
----------------------------------------------------
DFS ensures:
✔ We go as deep as possible first

When recursion returns:
✔ It means all dependent nodes are processed

So we push node into stack at that moment

Finally:
✔ Reverse of finishing order = topological order

====================================================
APPROACH
----------------------------------------------------
STEP 1: Initialize
----------------------------------------------------
vis[i] = 0 → node not visited

Create a stack to store ordering

----------------------------------------------------

STEP 2: Traverse all nodes
----------------------------------------------------
Graph may be disconnected

For every node:
    if not visited → call DFS

----------------------------------------------------

STEP 3: DFS Traversal
----------------------------------------------------
For current node:

✔ Mark as visited

✔ Visit all neighbours:
    if not visited → DFS(neighbour)

✔ After visiting all neighbours:
    push current node into stack

----------------------------------------------------

STEP 4: Build answer
----------------------------------------------------
Pop all elements from stack:
✔ This gives topological ordering

====================================================
IMPORTANT CONDITIONS
----------------------------------------------------
✔ Works only for DAG (no cycles)
✔ If cycle exists → topo sort not possible
✔ DFS ensures correct dependency resolution
✔ Stack stores reverse finishing order

====================================================
TIME & SPACE ANALYSIS
----------------------------------------------------
TIME COMPLEXITY:
➡ O(V + E)

SPACE COMPLEXITY:
➡ O(V)
(stack + recursion stack + visited array)

====================================================
KEY TAKEAWAY
----------------------------------------------------
Topological sort is about ordering nodes
based on dependencies.

Core trick:
✔ Perform DFS
✔ Push node AFTER exploring all neighbours
✔ Reverse order using stack

This gives valid topological ordering.
====================================================
*/

#include<bits/stdc++.h>
using namespace std;

class Solution{
        void dfs(int node, int vis[], stack<int> st, vector<int> adj[]){
            vis[node] = 1;
            for(auto it: adj[node]){
                if(!vis[it]) dfs(it, vis, st, adj);
            }

            st.push(node);
        }
    public:
        vector<int> topoSort(int V, vector<int> adj[]){
            int vis[V] = {0};
            stack<int> st;

            for(int i = 0; i<V; i++){
                if(!vis[i]){
                    dfs(i, vis, st, adj);
                }
            }

            vector<int> ans;
            while(!st.empty()){
                ans.push_back(st.top());
                st.pop();
            }

            return ans;
        }
};

int main(){
    
    return 0;
}