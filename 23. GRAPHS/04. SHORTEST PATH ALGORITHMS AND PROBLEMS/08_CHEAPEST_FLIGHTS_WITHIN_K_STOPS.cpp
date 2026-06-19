/*
====================================================
CHEAPEST FLIGHTS WITHIN K STOPS
LeetCode:
https://leetcode.com/problems/cheapest-flights-within-k-stops/description/
====================================================

💡 PROBLEM SUMMARY
----------------------------------------------------
- Given:
    • Flights between cities
    • Each flight has a cost

Goal:
✔ Reach destination with:
    • minimum total cost
    • at most k stops

✔ If impossible → return -1

====================================================
CORE IDEA: MODIFIED DIJKSTRA / BFS ⭐
----------------------------------------------------
Normal Dijkstra only minimizes:
✔ distance

But here we also have constraint:
✔ number of stops

So state becomes:
    {stops, cost, node}

----------------------------------------------------
We cannot simply use:
✔ minimum distance only

Because:
✔ A cheaper path may use too many stops

====================================================
KEY INSIGHT
----------------------------------------------------
We must track BOTH:
✔ cost
✔ stops

Condition to move:
----------------------------------------------------
✔ stops used <= k + 1

Why k + 1 ?
----------------------------------------------------
Because:
✔ Stops means intermediate nodes

Example:
    0 → 1 → 2

Here:
✔ flights(edges) = 2
✔ stops = 1

So maximum edges allowed:
    k + 1

====================================================
WHY THIS WORKS
----------------------------------------------------
Priority queue processes:
✔ smaller stop count first

For every neighbour:
✔ Try relaxing cost

Only proceed if:
✔ stops constraint satisfied
✔ cheaper cost found

====================================================
APPROACH
----------------------------------------------------

STEP 1: Build graph
----------------------------------------------------
✔ Directed graph

Store:
    u → {v, cost}

----------------------------------------------------

STEP 2: Initialize structures
----------------------------------------------------
Priority Queue stores:
    {stops, {distance, node}}

dist[node] stores:
    {minimum stops, minimum cost}

----------------------------------------------------

STEP 3: Traversal
----------------------------------------------------
While PQ not empty:

✔ Extract node

✔ Traverse neighbours

✔ If:
      stops + 1 <= k + 1
AND
      new cost < stored cost

Then:
✔ update
✔ push into PQ

----------------------------------------------------

STEP 4: Final answer
----------------------------------------------------
✔ If destination reachable within k stops:
      return minimum cost

✔ Otherwise:
      return -1

====================================================
IMPORTANT CONDITIONS
----------------------------------------------------
✔ Graph is DIRECTED
✔ Stops constraint is very important
✔ k stops means maximum k+1 edges
✔ Cannot use standard Dijkstra directly

====================================================
TIME & SPACE COMPLEXITY
----------------------------------------------------
TIME:
➡ O(E log V)

SPACE:
➡ O(V + E)

====================================================
KEY TAKEAWAY
----------------------------------------------------
Whenever problem says:
✔ "minimum cost with constraints"

Think:
✔ Modified Dijkstra / BFS with state tracking

State may include:
✔ stops
✔ fuel
✔ time
✔ discounts
✔ etc.

====================================================
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>> adj[n];
        
        for(auto it : flights){
            int u = it[0];
            int v = it[1];
            int wt = it[2];

            adj[u].push_back({v, wt});
        }

        priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>> pq;
        
        vector<pair<int,int>> dist(n, {1e9, 1e9});

        dist[src] = {0, 0};
        
        pq.push({0, {0, src}});

        while(!pq.empty()){
            int stops = pq.top().first;
            int d = pq.top().second.first;
            int node = pq.top().second.second;

            pq.pop();

            for(auto it : adj[node]){
                int adjNode = it.first;
                int adjWt = it.second;
                int adjStop = dist[adjNode].first;
                int adjDist = dist[adjNode].second;

                if((stops + 1 <= k+1) && (d + adjWt < adjDist)){
                    dist[adjNode].first = stops+1;
                    dist[adjNode].second = d + adjWt;
                    pq.push({dist[adjNode].first, {dist[adjNode].second, adjNode}});
                }
            }
        }

        return dist[dst].first - 1 <= k ? dist[dst].second : -1;
    }
};

/*
More cleaner version
*/

// typedef tuple<int,int,int> ti;
// class Solution_2 {
// public:
//     int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
//         vector<vector<pair<int,int>>>vp(n);
//         for(const auto&f:flights)   vp[f[0]].emplace_back(f[1],f[2]);
//         priority_queue<ti,vector<ti>,greater<ti>>pq;
//         pq.emplace(0,src,K+1);
//         while(!pq.empty()){
//             auto [cost,u,stops] = pq.top();
//             pq.pop();
//             if(u==dst)  return cost;
//             if(!stops)  continue;
//             for(auto to:vp[u]){
//                 auto [v,w] = to;
//                 pq.emplace(cost+w,v,stops-1);
//             }
//         }
//         return -1;
//     }
// };

int main(){
    
    return 0;
}