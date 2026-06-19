/*
====================================================
NETWORK DELAY TIME
LeetCode:
https://leetcode.com/problems/network-delay-time/
====================================================

💡 PROBLEM SUMMARY
----------------------------------------------------
- Given:
    • Directed weighted graph
    • A source node k

Goal:
✔ Find time taken for signal to reach
  all nodes

✔ Signal travels through edges with
  given weights

✔ If any node is unreachable:
      return -1

✔ Otherwise:
      return maximum time taken among
      all nodes

====================================================
CORE IDEA: DIJKSTRA'S ALGORITHM ⭐
----------------------------------------------------
This is a classic:
✔ Single Source Shortest Path problem

We need:
✔ minimum time from source node k
  to every other node

----------------------------------------------------
Why maximum at the end?
----------------------------------------------------
Because:
✔ Signal spreads simultaneously

Final answer depends on:
✔ slowest node to receive signal

So:
✔ compute shortest time to all nodes
✔ return maximum among them

====================================================
WHY DIJKSTRA WORKS
----------------------------------------------------
✔ Graph has positive edge weights

✔ Dijkstra guarantees:
      shortest distance from source
      to every node

====================================================
APPROACH
----------------------------------------------------

STEP 1: Build adjacency list
----------------------------------------------------
Graph is DIRECTED:

    u → v

Store:
    adj[u] = {v, weight}

----------------------------------------------------

STEP 2: Initialize structures
----------------------------------------------------
✔ dist[i] = ∞

✔ dist[k] = 0
    (source node)

✔ Min heap stores:
    {time, node}

----------------------------------------------------

STEP 3: Dijkstra traversal
----------------------------------------------------
While PQ not empty:

✔ Extract node with minimum time

✔ Skip outdated entries

✔ Traverse neighbours

✔ If shorter path found:
      update distance
      push into PQ

----------------------------------------------------

STEP 4: Compute final answer
----------------------------------------------------
✔ Traverse all nodes

✔ If any node remains ∞:
      → unreachable → return -1

✔ Otherwise:
      return maximum distance

====================================================
IMPORTANT CONDITIONS
----------------------------------------------------
✔ Graph is DIRECTED
✔ All edge weights are positive
✔ Dijkstra works efficiently here
✔ Maximum distance = total delay time

====================================================
TIME & SPACE COMPLEXITY
----------------------------------------------------
TIME:
➡ O((V + E) log V)

SPACE:
➡ O(V + E)

====================================================
KEY TAKEAWAY
----------------------------------------------------
Whenever problem asks:
✔ "time/distance from one node to all nodes"

Think:
✔ Dijkstra

And if asked:
✔ "when will all nodes receive signal?"

Return:
✔ maximum shortest distance

====================================================
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n + 1); 
        
        for (auto& edge : times) {
            int u = edge[0], v = edge[1], w = edge[2];
            adj[u].push_back({v, w});
        }

        vector<int> dist(n + 1, INT_MAX);
        dist[k] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        
        pq.push({0, k}); 

        while (!pq.empty()) {
            auto [time, node] = pq.top();
            pq.pop();

            if (time > dist[node]) continue;

            for (auto [nei, wt] : adj[node]) {
                if (dist[nei] > time + wt) {
                    dist[nei] = time + wt;
                    pq.push({dist[nei], nei});
                }
            }
        }

        int maxTime = 0;
        
        for (int i = 1; i <= n; ++i) {
            if (dist[i] == INT_MAX) return -1; 
            maxTime = max(maxTime, dist[i]);
        }

        return maxTime;
    }
};

int main(){
    
    return 0;
}