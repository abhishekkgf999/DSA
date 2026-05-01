/*
====================================================
FIND EVENTUAL SAFE STATES
LeetCode:
https://leetcode.com/problems/find-eventual-safe-states/description/
====================================================

💡 PROBLEM SUMMARY
- Given:
    • A directed graph

Goal:
✔ Find all nodes that are "eventual safe nodes"

Definition:
✔ A node is safe if:
    Starting from that node,
    every possible path leads to a terminal node
    (node with no outgoing edges)

✔ Nodes that are part of or lead to a cycle
    → NOT safe

====================================================
KEY IDEA: CYCLE DETECTION + SAFE NODE MARKING 🔁
----------------------------------------------------
Observation:
✔ Nodes involved in cycles are NOT safe
✔ Nodes leading to cycles are also NOT safe
✔ Only nodes that eventually reach terminal nodes
  are safe

So problem reduces to:
✔ Detect cycles
✔ Mark nodes not involved in cycles as safe

====================================================
APPROACH 1: DFS + PATH VISITATION
----------------------------------------------------
We use 3 arrays:

✔ vis[]      → visited nodes
✔ pathVis[]  → nodes in current DFS path
✔ check[]    → marks safe nodes

----------------------------------------------------

DFS Logic:
----------------------------------------------------
✔ If node is part of cycle → return true
✔ If node leads to cycle → return true
✔ Else → mark as safe

Steps:
1️⃣ Mark node as visited and part of path
2️⃣ Explore neighbours

Case:
✔ If neighbour not visited → DFS
✔ If neighbour in current path → cycle detected

3️⃣ If no cycle found:
    ✔ mark check[node] = 1 (safe)

4️⃣ Remove node from path (backtrack)

----------------------------------------------------

Final:
----------------------------------------------------
✔ Collect all nodes where check[i] == 1

====================================================
APPROACH 2: DFS (Cycle Detection Only)
----------------------------------------------------
✔ Use vis[] and recursion stack (isRecursion[])

✔ Nodes still marked in recursion stack
  after DFS → part of cycle

✔ Nodes NOT in recursion stack → safe

====================================================
APPROACH 3: BFS (KAHN'S ALGORITHM + REVERSE GRAPH) ⭐
----------------------------------------------------
Key observation:
✔ Terminal nodes (outdegree = 0) are always safe

Problem:
✔ Normal graph traversal won’t reach all safe nodes easily

Solution:
✔ Reverse the graph

----------------------------------------------------

Why reverse graph?
----------------------------------------------------
✔ So we can start from terminal nodes
✔ And move backwards to find all safe nodes

----------------------------------------------------

Steps:
----------------------------------------------------
1️⃣ Reverse all edges

2️⃣ Compute indegree of reversed graph
   (original outdegree)

3️⃣ Push all nodes with indegree = 0
   → these are terminal nodes

4️⃣ BFS traversal:
    ✔ mark nodes as safe
    ✔ reduce indegree of neighbours

5️⃣ Nodes that never reach indegree 0
   → part of cycle → NOT safe

====================================================
IMPORTANT CONDITIONS
----------------------------------------------------
✔ Nodes in cycle → NOT safe
✔ Nodes leading to cycle → NOT safe
✔ Terminal nodes → always safe
✔ Reverse graph helps propagate safety

====================================================
TIME & SPACE ANALYSIS
----------------------------------------------------
TIME COMPLEXITY:
➡ O(V + E)

SPACE COMPLEXITY:
➡ O(V)
(for arrays + recursion/queue)

====================================================
KEY TAKEAWAY
----------------------------------------------------
This problem is about identifying nodes
that do NOT participate in cycles.

Three ways:
✔ DFS + path tracking
✔ DFS + recursion stack
✔ BFS (Kahn’s Algorithm) with reversed graph

Most optimized & intuitive:
➡ Reverse graph + BFS from terminal nodes

====================================================
*/

#include<bits/stdc++.h>
using namespace std;

class Solution_1 {
    bool dfsCheck(int node, vector<vector<int>>& adj, vector<int> &vis, vector<int> &pathVis, vector<int> &check) {
        vis[node] = 1;
        pathVis[node] = 1;
        check[node] = 0;

        for (auto it : adj[node]) {
            if (!vis[it]) {
                if (dfsCheck(it, adj, vis, pathVis, check) == true)
                    return true;
            } else if (pathVis[it]) {
                return true;
            }
        }

        check[node] = 1;
        pathVis[node] = 0;
        return false;
    }

public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> vis(V, 0);
        vector<int> pathVis(V, 0);
        vector<int> check(V, 0);

        vector<int> safeNodes;

        for (int i = 0; i < V; i++) {
            if (!vis[i])
                dfsCheck(i, graph, vis, pathVis, check);
        }

        for (int i = 0; i < V; i++) {
            if (check[i] == 1)
                safeNodes.push_back(i);
        }

        return safeNodes;
    }
};

class Solution_another_dfs_approach {
public:
    bool dfs(int node, vector<vector<int>>& graph, vector<int> &vis, vector<bool> &isRecursion){
        vis[node] = 1;
        isRecursion[node] = true;

        for(auto it : graph[node]){
            if(!vis[it]){
                if(dfs(it, graph, vis, isRecursion) == true) return true;
            }else if(isRecursion[it]){
                return true;
            }
        }

        isRecursion[node] = false;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> vis(V, 0);
        vector<bool> isRecursion(V, false);

        for(int i = 0; i<V; i++){
            if(!vis[i]){
                dfs(i, graph, vis, isRecursion);
            }
        }

        vector<int> ans;
        for(int i = 0; i<V; i++){
            if(!isRecursion[i]){
                ans.push_back(i);
            }
        }

        return ans;
    }
};

/*
====================================================
APPROACH 3: BFS (REVERSE GRAPH + KAHN'S ALGORITHM)
====================================================
*/
class Solution2_using_BFS {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<vector<int>> ReverseGraph(V);
        vector<bool> count(V, false);
        vector<int> inDegree(V, 0);

        for(int i = 0; i<V; i++){
            for(auto it : graph[i]){
                ReverseGraph[it].push_back(i);
                inDegree[i]++;
            }
        }
        
        queue<int> q;
        for(int i = 0; i<V; i++){
            if(inDegree[i] == 0) q.push(i);
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();
            count[node] = true;
            for(auto it : ReverseGraph[node]){
                inDegree[it]--;
                if(inDegree[it] == 0) q.push(it);
            }
        }

        vector<int> ans;
        for(int i = 0; i<V; i++){
            if(count[i]) ans.push_back(i);
        }

        return ans;
    }
};

int main(){
    vector<vector<int>> graph = {{1,2},{2,3},{5},{0},{5},{},{}};
    Solution_1 obj;
    vector<int> ans = obj.eventualSafeNodes(graph);
    for(auto it : ans) cout<<it<<" ";
    return 0;
}