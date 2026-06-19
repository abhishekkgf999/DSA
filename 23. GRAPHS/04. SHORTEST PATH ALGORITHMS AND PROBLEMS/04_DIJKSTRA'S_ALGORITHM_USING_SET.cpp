/*
====================================================
DIJKSTRA'S ALGORITHM (USING SET)
====================================================

💡 PROBLEM SUMMARY
- Given:
    • A weighted graph (directed)
    • Source node (src)

Goal:
✔ Find shortest distance from source
  to all other nodes

====================================================
KEY IDEA: GREEDY + ORDERED SET ⭐
----------------------------------------------------
This is another implementation of Dijkstra
using a set instead of a priority queue.

✔ Set stores elements in sorted order
✔ Always gives smallest distance node first

Set stores:
    {distance, node}

====================================================
WHY USE SET INSTEAD OF PRIORITY QUEUE
----------------------------------------------------
✔ In priority queue:
    - Cannot remove/update existing entries easily
    - We may insert duplicate entries

✔ In set:
    - We can erase old entries
    - Maintain only the latest shortest distance

This makes updates cleaner and avoids duplicates

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
✔ dist[i] = ∞ (1e9)
✔ dist[src] = 0

✔ Insert {0, src} into set

----------------------------------------------------

STEP 3: Process nodes
----------------------------------------------------
While set not empty:

✔ Take node with smallest distance
    (begin() gives minimum)

✔ Remove it from set

✔ Traverse neighbours

----------------------------------------------------

STEP 4: Relax edges
----------------------------------------------------
For each neighbour:

✔ If new shorter distance found:
      - Remove old entry from set (if exists)
      - Update distance
      - Insert new pair into set

----------------------------------------------------

STEP 5: Final result
----------------------------------------------------
✔ dist[] contains shortest distances

====================================================
IMPORTANT CONDITIONS
----------------------------------------------------
✔ Works only for non-negative weights
✔ Set ensures sorted order (like min heap)
✔ Always remove outdated distance before inserting new one
✔ Avoids duplicate entries unlike priority queue

====================================================
TIME & SPACE ANALYSIS
----------------------------------------------------
TIME COMPLEXITY:
➡ O((V + E) log V)
(each insert/erase in set takes log V)

SPACE COMPLEXITY:
➡ O(V)
(for distance array + set)

====================================================
KEY TAKEAWAY
----------------------------------------------------
Dijkstra can be implemented using:

✔ Priority Queue → faster, simpler
✔ Set → allows deletion of old entries

Core idea remains same:
✔ Always process node with smallest distance
✔ Relax edges to update shortest paths

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

        set<pair<int,int>> st;
        vector<int> dist(V, 1e9);

        st.insert({0, src});
        dist[src] = 0;

        while(!st.empty()){
            auto it = *(st.begin());
            int dis  = it.first;   
            int node = it.second;  
            st.erase(it);

            for(auto it : adj[node]){
                int adjNode    = it.first;
                int edgeWeight = it.second;

                if(dis + edgeWeight < dist[adjNode]){
                    
                    if(dist[adjNode] != 1e9){
                        st.erase({dist[adjNode], adjNode});
                    }

                    dist[adjNode] = dis + edgeWeight;
                    st.insert({dist[adjNode], adjNode});
                }
            }
        }

        return dist;
    }
};

int main(){
    
    return 0;
}