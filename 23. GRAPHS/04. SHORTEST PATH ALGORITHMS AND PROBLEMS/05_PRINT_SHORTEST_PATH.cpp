/*
====================================================
PRINT SHORTEST PATH (DIJKSTRA + PATH RECONSTRUCTION)
GeeksforGeeks:
https://www.geeksforgeeks.org/problems/shortest-path-in-weighted-undirected-graph/1
====================================================

💡 PROBLEM SUMMARY
- Given:
    • A weighted undirected graph
    • Nodes numbered from 1 to n

Goal:
✔ Find the shortest path from node 1 → node n
✔ Return:
    • total shortest distance
    • actual path taken

✔ If destination is unreachable → return {-1}

====================================================
KEY IDEA: DIJKSTRA + PARENT TRACKING ⭐
----------------------------------------------------
We use Dijkstra to compute shortest distances.

Extra step:
✔ Maintain a parent array to reconstruct path

Idea:
✔ When we update distance of a node,
  we also store:
        parent[child] = current node

This helps trace back the shortest path.

====================================================
APPROACH
----------------------------------------------------
STEP 1: Build adjacency list
----------------------------------------------------
✔ Since graph is undirected:
    u ↔ v

Store:
    adj[u] = {v, weight}
    adj[v] = {u, weight}

----------------------------------------------------

STEP 2: Initialize
----------------------------------------------------
✔ dist[i] = ∞ (1e9)
✔ dist[1] = 0 (source node)

✔ parent[i] = i (initially self)

✔ Use min heap:
    {distance, node}

----------------------------------------------------

STEP 3: Dijkstra traversal
----------------------------------------------------
While priority queue not empty:

✔ Extract node with smallest distance

✔ Skip outdated entries

✔ For each neighbour:
      if shorter path found:
          ✔ update distance
          ✔ update parent
          ✔ push into heap

----------------------------------------------------

STEP 4: Check reachability
----------------------------------------------------
✔ If dist[n] == ∞:
      → destination unreachable → return {-1}

----------------------------------------------------

STEP 5: Reconstruct path
----------------------------------------------------
✔ Start from node n
✔ Move backwards using parent[]

    n → parent[n] → parent[parent[n]] → ... → 1

✔ Store nodes in result

✔ Reverse path (excluding distance index)

----------------------------------------------------

STEP 6: Final result format
----------------------------------------------------
✔ ans[0] = shortest distance
✔ remaining elements = path from 1 → n

====================================================
IMPORTANT CONDITIONS
----------------------------------------------------
✔ Graph is undirected
✔ Parent array stores shortest path tree
✔ Reverse path after backtracking
✔ Always check outdated entries in PQ

====================================================
TIME & SPACE ANALYSIS
----------------------------------------------------
TIME COMPLEXITY:
➡ O((V + E) log V)

SPACE COMPLEXITY:
➡ O(V)
(for distance + parent + PQ)

====================================================
KEY TAKEAWAY
----------------------------------------------------
To print shortest path:

✔ Use Dijkstra to compute distances
✔ Maintain parent[] to track path
✔ Backtrack from destination to source

This converts shortest distance problem
into actual path reconstruction problem.

====================================================
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        vector<pair<int,int>> adj[n+1];
        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }
        
        vector<int> parent(n+1, 0);
        for(int i = 1; i<=n; i++) parent[i] = i;
        
        vector<int> dist(n+1, 1e9);
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        
        pq.push({0, 1});
        
        dist[1] = 0;

        while(!pq.empty()){
            int node = pq.top().second;
            int d = pq.top().first;
            pq.pop();
        
            if(d > dist[node]) continue;
        
            for(auto it : adj[node]){
                int adjNode = it.first;
                int adjWeight = it.second;
        
                if(d + adjWeight < dist[adjNode]){
                    dist[adjNode] = d + adjWeight;
                    parent[adjNode] = node;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }
        
        if(dist[n] == 1e9) return {-1};
        
        vector<int> ans;
        ans.push_back(dist[n]);
        
        int i = n;
        while(i != parent[i]){
            ans.push_back(i);
            i = parent[i];
        }
        ans.push_back(1);
        
        reverse(ans.begin()+1, ans.end());
        
        return ans;
        
    }
};

int main(){
    
    return 0;
}