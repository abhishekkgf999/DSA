/*
====================================================
M-COLORING PROBLEM
GeeksforGeeks:
https://www.geeksforgeeks.org/problems/m-coloring-problem-1587115620/1
====================================================

💡 PROBLEM SUMMARY
- Given:
    • A graph with V vertices
    • List of edges
    • An integer m (number of colors)

Goal:
✔ Determine if the graph can be colored using
  at most m colors such that:

    • No two adjacent vertices have same color

Return:
✔ true  → if possible
✔ false → otherwise

====================================================
KEY IDEA: BACKTRACKING + GRAPH COLORING 🎨
----------------------------------------------------
This is an extension of bipartite graph coloring.

Instead of 2 colors:
✔ We now have m colors

Approach:
✔ Try assigning each node a color (1 → m)
✔ Ensure no adjacent node has same color
✔ If conflict occurs → try another color
✔ If no color works → backtrack

====================================================
APPROACH
----------------------------------------------------
STEP 1: Convert edges → adjacency list
----------------------------------------------------
Build graph representation for traversal.

----------------------------------------------------

STEP 2: Initialize color array
----------------------------------------------------
color[i] = -1 → node is uncolored

----------------------------------------------------

STEP 3: Recursive Backtracking
----------------------------------------------------
Function: solve(node)

Base case:
✔ If all nodes are colored (node == V)
      → return true

For current node:
    Try all colors from 1 → m

    If color is safe:
        ✔ Assign color
        ✔ Recur for next node

    If recursion fails:
        ❌ Backtrack (remove color)

----------------------------------------------------

STEP 4: Safety Check
----------------------------------------------------
Function: isSafe(node, color)

✔ Check all adjacent nodes
✔ If any neighbour has same color:
      return false

✔ Else:
      return true

====================================================
IMPORTANT CONDITIONS
----------------------------------------------------
✔ Adjacent nodes must have different colors
✔ Try all possible color assignments (1 → m)
✔ Backtracking ensures exploring all possibilities
✔ If one valid coloring exists → return true
✔ Graph may not always be colorable with m colors

====================================================
TIME & SPACE ANALYSIS
----------------------------------------------------
TIME COMPLEXITY:
➡ O(m^V)
Each node tries m colors in worst case

SPACE COMPLEXITY:
➡ O(V)
(for recursion stack + color array)

====================================================
KEY TAKEAWAY
----------------------------------------------------
This is a classic backtracking problem.

Idea:
✔ Try assigning colors node by node
✔ Validate constraints
✔ Backtrack if conflict occurs

It is essentially:
"Can we color the graph with m colors?"

====================================================
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool isSafe(int node, vector<int> adj[], vector<int> &color, int c){
        for(auto &it : adj[node]){
            if(color[it] == c) return false;
        }
        
        return true;
    }
    bool solve(int node, vector<int> adj[], vector<int> &color, int v, int m){
        if(node == v) return true;
        
        for(int c = 1; c<=m; c++){
            if(isSafe(node, adj, color, c)){
                color[node] = c;
                if(solve(node+1, adj, color, v, m)) return true;
                color[node] = -1;
            }
        }
        
        return false;
    }
    bool graphColoring(int v, vector<vector<int>> &edges, int m) {
        // code here
        vector<int> adj[v];
        for(int i = 0; i<edges.size(); i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        vector<int> color(v, -1);
        if(solve(0, adj, color, v, m)) return true;
        return false;
    }
};

int main(){
    vector<vector<int>> edges = {{0, 1}, {1,3}, {2,3}, {3, 0}, {0, 2}};
    int m = 3;
    int v = 4;
    Solution obj;
    cout<<obj.graphColoring(v, edges, m);
    return 0;
}