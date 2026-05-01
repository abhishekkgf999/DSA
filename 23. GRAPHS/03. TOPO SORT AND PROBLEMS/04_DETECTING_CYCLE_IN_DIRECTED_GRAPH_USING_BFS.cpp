/*
====================================================
DETECT CYCLE IN DIRECTED GRAPH (BFS - KAHN'S ALGORITHM)
====================================================

💡 PROBLEM SUMMARY
- Given:
    • A directed graph (adjacency list)

Goal:
✔ Detect whether the graph contains a cycle

Return:
✔ true  → if cycle exists
✔ false → otherwise

====================================================
KEY IDEA: TOPOLOGICAL SORT (KAHN'S ALGORITHM) 🔄
----------------------------------------------------
This approach is based on:

✔ Topological Sort using BFS

Observation:
✔ A Directed Acyclic Graph (DAG) can have
  a valid topological ordering of all vertices

✔ If a graph contains a cycle:
    → Some nodes will always have dependencies
    → Their indegree will never become 0

So:
✔ If we cannot process all nodes → cycle exists

====================================================
WHY THIS WORKS
----------------------------------------------------
✔ Nodes in cycle depend on each other
✔ Their indegree never reduces to 0

So they are never pushed into queue

Thus:
✔ Total processed nodes < total vertices

====================================================
APPROACH
----------------------------------------------------
STEP 1: Compute indegree
----------------------------------------------------
For every node:
    count incoming edges

----------------------------------------------------

STEP 2: Initialize queue
----------------------------------------------------
Push all nodes with:
    indegree = 0

These nodes have no dependencies

----------------------------------------------------

STEP 3: BFS Traversal (Kahn’s Algorithm)
----------------------------------------------------
✔ Pop node from queue
✔ Increment processed node count

✔ For each neighbour:
      reduce indegree

✔ If indegree becomes 0:
      push into queue

----------------------------------------------------

STEP 4: Check for cycle
----------------------------------------------------
After BFS:

✔ If processed nodes == V:
      → no cycle (valid DAG)

✔ If processed nodes < V:
      → cycle exists

====================================================
IMPORTANT CONDITIONS
----------------------------------------------------
✔ Works only for directed graph
✔ Based on indegree reduction
✔ Cycle prevents some nodes from reaching indegree 0
✔ Count of processed nodes is key indicator

====================================================
TIME & SPACE ANALYSIS
----------------------------------------------------
TIME COMPLEXITY:
➡ O(V + E)

SPACE COMPLEXITY:
➡ O(V)
(for indegree array + queue)

====================================================
KEY TAKEAWAY
----------------------------------------------------
Cycle detection using BFS is based on
topological sorting.

Core idea:
✔ If all nodes can be processed → no cycle
✔ If some nodes remain → cycle exists

====================================================
*/

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
        bool isCyclic(int V, vector<int> adj[]){
            int inDegree[V] = {0};
            for(int i = 0; i<V; i++){
                for(auto it: adj[i]){
                    inDegree[it]++;
                }
            }

            queue<int> q;
            for(int i = 0; i<V; i++){
                if(inDegree[i] == 0)q.push(i);
            }

            int cnt = 0;
            while(!q.empty()){
                int node = q.front();
                q.pop();
                cnt++;

                for(auto it: adj[node]){
                    inDegree[it]--;
                    if(inDegree[it] == 0)q.push(it);
                }
            }

            if(cnt == V) return false;
            return true;
        }
};

int main(){
    
    return 0;
}