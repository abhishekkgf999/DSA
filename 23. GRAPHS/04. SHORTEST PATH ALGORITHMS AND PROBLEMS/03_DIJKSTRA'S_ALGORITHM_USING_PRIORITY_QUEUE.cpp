/*
====================================================
DIJKSTRA'S ALGORITHM (SHORTEST PATH)
====================================================

💡 PROBLEM SUMMARY
- Given:
    • A weighted graph (directed)
    • Source node (src)

Goal:
✔ Find shortest distance from source
  to all other nodes

====================================================
KEY IDEA: GREEDY + MIN HEAP (PRIORITY QUEUE) ⭐
----------------------------------------------------
We always pick the node with:
✔ Minimum distance discovered so far

Why?
✔ That ensures we are always expanding
  the shortest possible path first

Data Structure:
✔ Min Heap (priority_queue with greater comparator)

Stores:
    {distance, node}

====================================================
WHY THIS WORKS
----------------------------------------------------
✔ Once a node is picked with minimum distance,
  that distance is guaranteed to be shortest

✔ Then we try to improve distances of its neighbours
  (called "relaxation")

====================================================
APPROACH
----------------------------------------------------
STEP 1: Build adjacency list
----------------------------------------------------
✔ Store graph as:
    adj[u] = {v, weight}

----------------------------------------------------

STEP 2: Initialize
----------------------------------------------------
✔ dist[i] = ∞ (large value)
✔ dist[src] = 0

✔ Push {0, src} into min heap

----------------------------------------------------

STEP 3: Process nodes (Dijkstra)
----------------------------------------------------
While priority queue not empty:

✔ Extract node with smallest distance

✔ If current distance > stored distance:
      → skip (outdated entry)

✔ Traverse all neighbours

For each neighbour:
    if (current distance + edge weight < dist[adjNode]):
        ✔ update distance
        ✔ push into priority queue

----------------------------------------------------

STEP 4: Final result
----------------------------------------------------
✔ dist[] contains shortest distances
✔ Unreachable nodes remain large (∞)

====================================================
IMPORTANT CONDITIONS
----------------------------------------------------
✔ Works only for:
    NON-NEGATIVE edge weights

✔ Optimization:
    Skip outdated entries using:
        if(dis > dist[node]) continue;

✔ Graph can be directed or undirected
  (depends on input)

====================================================
WHY DIJKSTRA FAILS FOR NEGATIVE WEIGHTS 🚨
----------------------------------------------------
Example:
u → v with weight = -1

✔ Distance keeps decreasing:
    u → v = -1
    v → u = -2
    u → v = -3 ...

✔ Infinite relaxation happens

So:
✔ Dijkstra cannot handle negative weights
✔ Use Bellman-Ford instead for such cases

====================================================
TIME & SPACE ANALYSIS
----------------------------------------------------
TIME COMPLEXITY:
➡ O((V + E) log V)

SPACE COMPLEXITY:
➡ O(V)
(for distance array + priority queue)

====================================================
KEY TAKEAWAY
----------------------------------------------------
Dijkstra is a greedy algorithm for shortest path.

Core idea:
✔ Always expand the closest node first
✔ Use min heap for efficiency
✔ Relax edges to update shortest distances

Limitation:
✔ Does NOT work with negative edge weights

====================================================
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        vector<pair<int,int>> adj[V];
        for(auto it : edges){
            int u = it[0], v = it[1], wt = it[2];
            adj[u].push_back({v, wt});
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int> dist(V, 1e9);

        dist[src] = 0;
        pq.push({0, src});

        while(!pq.empty()){
            int dis  = pq.top().first;   
            int node = pq.top().second;  
            pq.pop();

            if(dis > dist[node]) continue;

            for(auto it : adj[node]){
                int adjNode    = it.first;
                int edgeWeight = it.second;

                if(dis + edgeWeight < dist[adjNode]){
                    dist[adjNode] = dis + edgeWeight;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }

        return dist;
    }
};



int main(){
    
    return 0;
}