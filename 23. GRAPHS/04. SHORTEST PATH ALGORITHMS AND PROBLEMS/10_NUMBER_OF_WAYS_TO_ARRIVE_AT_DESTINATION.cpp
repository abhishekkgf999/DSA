/*
====================================================
NUMBER OF WAYS TO ARRIVE AT DESTINATION
LeetCode:
https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/description/
====================================================

💡 PROBLEM SUMMARY
----------------------------------------------------
- Given:
    • Weighted UNDIRECTED graph
    • Source node = 0
    • Destination node = n-1

Goal:
✔ Find:
    • minimum distance from source to destination
    • total number of shortest paths

✔ Return:
    number of shortest paths modulo 1e9+7

====================================================
CORE IDEA: DIJKSTRA + PATH COUNTING ⭐
----------------------------------------------------
Normal Dijkstra only stores:
✔ shortest distance

But here we also need:
✔ number of ways to achieve that
  shortest distance

So for every node we maintain:

✔ dist[node]
    → shortest distance

✔ ways[node]
    → number of shortest paths

====================================================
KEY INSIGHT
----------------------------------------------------
There can be:
✔ multiple shortest paths

Example:
----------------------------------------------------
If node can be reached:

Path 1 → distance = 5
Path 2 → distance = 5

Then:
✔ both contribute to answer

So:
    ways[node] += ways[parent]

====================================================
IMPORTANT OBSERVATION
----------------------------------------------------
CASE 1:
----------------------------------------------------
If NEW SHORTER path found:

    newDist < dist[adjNode]

Then:
✔ We found better minimum distance

So:
✔ old ways become useless
✔ replace them

    ways[adjNode] = ways[node]

----------------------------------------------------

CASE 2:
----------------------------------------------------
If SAME shortest distance found:

    newDist == dist[adjNode]

Then:
✔ another shortest path discovered

So:
✔ add number of ways

    ways[adjNode] += ways[node]

====================================================
WHY MOD IS REQUIRED
----------------------------------------------------
Number of paths can become very large.

So:
✔ Use modulo:
    1e9 + 7

while updating ways.

====================================================
WHY LONG LONG IS REQUIRED
----------------------------------------------------
Distances can become very large.

So:
✔ Use long long for:
    • distance array
    • priority queue distance

Otherwise:
✔ integer overflow may occur

====================================================
APPROACH
----------------------------------------------------

STEP 1: Build adjacency list
----------------------------------------------------
Graph is UNDIRECTED:

    u ↔ v

Store both directions.

----------------------------------------------------

STEP 2: Initialize structures
----------------------------------------------------
✔ dist[i] = ∞
✔ ways[i] = 0

Source node:
    dist[0] = 0
    ways[0] = 1

✔ Min heap stores:
    {distance, node}

----------------------------------------------------

STEP 3: Apply Dijkstra
----------------------------------------------------
While PQ not empty:

✔ Extract node with minimum distance

✔ Skip outdated entries

✔ Traverse neighbours

----------------------------------------------------

STEP 4: Relaxation logic
----------------------------------------------------
If shorter path found:

✔ update distance
✔ copy ways from current node

If equal shortest path found:

✔ add ways

    ways[adjNode] += ways[node]

----------------------------------------------------

STEP 5: Final answer
----------------------------------------------------
✔ ways[n-1]
    = total shortest paths

====================================================
IMPORTANT CONDITIONS
----------------------------------------------------
✔ Graph is UNDIRECTED
✔ Multiple shortest paths possible
✔ Use MOD while adding ways
✔ Use long long for distances
✔ Skip outdated PQ entries

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
✔ "count number of shortest paths"

Think:
✔ Dijkstra + Ways array

Dijkstra gives:
✔ minimum distance

Ways array gives:
✔ number of optimal paths

====================================================
*/

#include<bits/stdc++.h>
using namespace std;

#define MOD 1000000007

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<int,int>> adj[n];
        
        for(auto it : roads){
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

        vector<long long> dist(n, LLONG_MAX);
        vector<int> ways(n, 0);

        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;

        dist[0] = 0;
        ways[0] = 1;

        pq.push({0, 0});

        while(!pq.empty()){
            auto [d, node] = pq.top();
            pq.pop();

            if(d > dist[node]) continue;

            for(auto [adjNode, adjDist] : adj[node]){

                if(adjDist + d < dist[adjNode]){
                    ways[adjNode] = ways[node];
                    dist[adjNode] = d + adjDist;
                    pq.push({dist[adjNode], adjNode});
                }
                else if(adjDist + d == dist[adjNode]){
                    ways[adjNode] = (ways[adjNode] + ways[node]) % MOD;
                }
            }
        }

        return ways[n-1];
    }
};

int main(){
    
    return 0;
}