/*
====================================================
SHORTEST PATH IN DIRECTED ACYCLIC GRAPH (DAG)
GeeksforGeeks:
https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph/1
====================================================

💡 PROBLEM SUMMARY
- Given:
    • A Directed Acyclic Graph (DAG)
    • Weighted edges

Goal:
✔ Find shortest distance from source node (0)
  to all other nodes

✔ If a node is unreachable → return -1

====================================================
KEY IDEA: TOPOLOGICAL SORT + RELAXATION 🔄
----------------------------------------------------
In a DAG:
✔ No cycles exist
✔ We can process nodes in a linear order

Idea:
✔ First get topological order of nodes
✔ Then relax edges in that order

Why?
✔ Ensures we process a node only after
  all possible ways to reach it are considered

====================================================
WHY TOPO SORT IS USED
----------------------------------------------------
✔ Guarantees correct order of processing

Example:
If u → v:
✔ u will always come before v in topo order

So:
✔ When processing u, we already know
  shortest distance to u

✔ Then we can update distance to v safely

====================================================
APPROACH
----------------------------------------------------
STEP 1: Build adjacency list
----------------------------------------------------
✔ Store graph as:
    adj[u] = {v, weight}

----------------------------------------------------

STEP 2: Perform Topological Sort (DFS)
----------------------------------------------------
✔ Use DFS to generate topo order
✔ Push node into stack after visiting neighbours

Stack gives:
✔ Reverse topological order

----------------------------------------------------

STEP 3: Initialize distances
----------------------------------------------------
✔ dist[i] = ∞ (INT_MAX)
✔ dist[0] = 0 (source node)

----------------------------------------------------

STEP 4: Process nodes in topo order
----------------------------------------------------
While stack not empty:

✔ Pop node

✔ For each neighbour:
      if dist[node] + weight < dist[neighbour]:
            update distance

(This step is called "edge relaxation")

----------------------------------------------------

STEP 5: Final conversion
----------------------------------------------------
✔ If dist[i] == ∞:
      → unreachable → set to -1

====================================================
IMPORTANT CONDITIONS
----------------------------------------------------
✔ Graph must be DAG
✔ No need for Dijkstra (faster than that here)
✔ Topo order ensures correct dependency flow
✔ Always check dist[node] != INT_MAX before relaxing

====================================================
TIME & SPACE ANALYSIS
----------------------------------------------------
TIME COMPLEXITY:
➡ O(V + E)

SPACE COMPLEXITY:
➡ O(V)
(for stack + visited + distance array)

====================================================
KEY TAKEAWAY
----------------------------------------------------
Shortest path in DAG is efficiently solved using:
✔ Topological Sort + Relaxation

Main trick:
✔ Process nodes in topo order
✔ Update distances like Dijkstra,
  but without priority queue

====================================================
*/

#include<bits/stdc++.h>
using namespace std;

// User function Template for C++
class Solution {
  public:
    void topoSort(int node, vector<pair<int,int>> adj[], vector<int> &vis, stack<int> &st){
        vis[node] = 1;
        
        for(auto it : adj[node]){
            int v = it.first;
            if(!vis[v]) topoSort(v, adj, vis, st);
        }
        
        st.push(node);
    }
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        // code here
        vector<pair<int,int>> adj[V];
        for(int i = 0; i<edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            adj[u].push_back({v, wt});
        }
        
        vector<int> vis(V, 0);
        stack<int> st;
        for(int i = 0; i<V; i++){
            if(!vis[i]){
                topoSort(i, adj, vis, st);
            }
        }
        
        vector<int> dist(V, INT_MAX);
        dist[0] = 0;
        while(!st.empty()){
            int node = st.top();
            st.pop();
            
            for(auto it: adj[node]){
                int v = it.first;
                int wt = it.second;
                
                if(dist[node] != INT_MAX && dist[node] + wt < dist[v]){
                    dist[v] = dist[node] + wt;
                }
            }
        }
        
        for(int i = 0; i<V; i++) dist[i] = (dist[i] == INT_MAX ? -1 : dist[i]);
        
        return dist;
    }
};


int main(){
    
    return 0;
}