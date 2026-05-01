/*
====================================================
TOPOLOGICAL SORT (BFS - KAHN'S ALGORITHM)
====================================================

💡 PROBLEM SUMMARY
- Given:
    • A Directed Acyclic Graph (DAG)

Goal:
✔ Return a linear ordering of vertices such that:
    For every directed edge (u → v),
    node u appears before node v

====================================================
KEY IDEA: INDEGREE + BFS (KAHN'S ALGORITHM) 🔄
----------------------------------------------------
Instead of DFS, this approach uses:

✔ Indegree (number of incoming edges)
✔ Queue (BFS)

Idea:
✔ Nodes with indegree = 0 have no dependencies
✔ So they can appear first in topological order

Process:
✔ Remove such nodes and reduce indegree of neighbours
✔ Repeat until all nodes are processed

====================================================
WHY THIS WORKS
----------------------------------------------------
✔ If a node has indegree 0:
      → no prerequisites → safe to include

✔ Removing a node:
      → reduces dependency for its neighbours

✔ BFS ensures nodes are processed in correct order

====================================================
APPROACH
----------------------------------------------------
STEP 1: Compute indegree
----------------------------------------------------
For every node:
    Traverse adjacency list
    Increase indegree of neighbours

----------------------------------------------------

STEP 2: Initialize queue
----------------------------------------------------
Push all nodes with:
    indegree = 0

These are starting nodes of topo sort

----------------------------------------------------

STEP 3: BFS Traversal
----------------------------------------------------
While queue is not empty:

✔ Pop node from queue
✔ Add it to topo result

✔ For all neighbours:
      decrease indegree

✔ If any neighbour becomes 0:
      push into queue

----------------------------------------------------

STEP 4: Return result
----------------------------------------------------
Final topo vector contains valid ordering

====================================================
IMPORTANT CONDITIONS
----------------------------------------------------
✔ Works only for DAG
✔ If graph has cycle:
      topo sort will NOT include all nodes

✔ Indegree tracks dependencies
✔ Queue ensures correct processing order

====================================================
TIME & SPACE ANALYSIS
----------------------------------------------------
TIME COMPLEXITY:
➡ O(V + E)

SPACE COMPLEXITY:
➡ O(V)
(for indegree array + queue + result)

====================================================
KEY TAKEAWAY
----------------------------------------------------
Kahn’s Algorithm uses BFS to perform
topological sorting.

Core idea:
✔ Start with nodes having no incoming edges
✔ Gradually remove dependencies
✔ Build ordering level by level

====================================================
*/

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
        vector<int> topoSort(int V, vector<int> adj[]){
            int inDegree[V] = {0};
            for(int i = 0; i<V; i++){
                for(auto it : adj[i]){
                    inDegree[it]++;
                }
            }

            queue<int> q;
            for(int i = 0; i<V; i++){
                if(inDegree[i] == 0){
                    q.push(i);
                }
            }
            
            vector<int> topo;
            while(!q.empty()){
                int node = q.front();
                q.pop();
                topo.push_back(node);

                for(auto it: adj[node]){
                    inDegree[it]--;
                    if(inDegree[it] == 0) q.push(it);
                }
            }

            return topo;
        }
};  

int main(){
    
    return 0;
}