/*
====================================================
DISJOINT SET UNION (DSU) / UNION FIND
====================================================

💡 PROBLEM SUMMARY
----------------------------------------------------
Disjoint Set is a data structure used to:

✔ Group nodes into components
✔ Quickly check whether two nodes
  belong to same component
✔ Merge components efficiently

----------------------------------------------------
Mostly used in:
✔ Graph problems
✔ Minimum Spanning Tree
✔ Dynamic connectivity
✔ Cycle detection

====================================================
CORE IDEA ⭐
----------------------------------------------------
Every component has:
✔ one ultimate parent (representative)

Initially:
✔ every node is its own parent

Example:
----------------------------------------------------
1   2   3   4

After union(1,2):

    1
   /
  2

Now:
✔ both belong to same component

====================================================
MAIN OPERATIONS
----------------------------------------------------

1️⃣ FIND
----------------------------------------------------
✔ Find ultimate parent of node

2️⃣ UNION
----------------------------------------------------
✔ Merge two components

====================================================
FIND OPERATION + PATH COMPRESSION ⭐
----------------------------------------------------
findUPar(node)

Goal:
✔ Reach ultimate parent recursively

----------------------------------------------------
Example:

1 ← 2 ← 3 ← 4

If we call:
    find(4)

Normally:
✔ 4 → 3 → 2 → 1

----------------------------------------------------
Path Compression optimization:
----------------------------------------------------
After finding ultimate parent:

Make:
    4 → 1
    3 → 1
    2 → 1

directly.

----------------------------------------------------
Result:
✔ future operations become very fast

====================================================
WHY PATH COMPRESSION IS IMPORTANT
----------------------------------------------------
Without compression:
✔ tree may become long

With compression:
✔ tree becomes almost flat

Hence:
✔ nearly constant time operations

====================================================
UNION BY RANK ⭐
----------------------------------------------------
Idea:
✔ Attach smaller rank tree
  under larger rank tree

----------------------------------------------------
Rank means:
✔ approximate tree height

Why?
----------------------------------------------------
To avoid deep trees.

----------------------------------------------------
Case 1:
✔ smaller rank attaches to larger rank

Case 2:
✔ equal ranks:
      attach any one
      increase rank by 1

====================================================
UNION BY SIZE ⭐
----------------------------------------------------
Idea:
✔ smaller component attaches
  to larger component

----------------------------------------------------
Size means:
✔ number of nodes in component

After attaching:
✔ update component size

====================================================
RANK vs SIZE
----------------------------------------------------
Both work on same intuition:

✔ keep tree shallow

----------------------------------------------------
Difference:
----------------------------------------------------
Rank:
✔ based on height

Size:
✔ based on number of nodes

----------------------------------------------------
In practice:
✔ Union by Size is often
  easier to understand

====================================================
IMPORTANT NOTE ⭐
----------------------------------------------------
Before union:

Always find:
    ultimate parents

Because:
✔ direct parent may not be
  actual representative

====================================================
TIME COMPLEXITY
----------------------------------------------------
With:
✔ Path Compression
✔ Union by Rank/Size

Operations become:
➡ Almost O(1)

More precisely:
➡ O(α(N))

where:
✔ α = Inverse Ackermann Function
✔ grows extremely slowly

====================================================
APPLICATIONS
----------------------------------------------------
✔ Kruskal's Algorithm
✔ Detect cycle in graph
✔ Number of connected components
✔ Dynamic graph connectivity
✔ Accounts Merge
✔ Network connectivity problems

====================================================
KEY TAKEAWAY
----------------------------------------------------
Disjoint Set helps us:

✔ Efficiently manage components
✔ Merge sets quickly
✔ Check connectivity quickly

Golden combination:
✔ Path Compression
+
✔ Union by Rank / Size

====================================================
*/

#include<bits/stdc++.h>
using namespace std;

class DisjointSet {
    vector<int> rank, parent, size;
public:
    DisjointSet(int n){
        rank.resize(n+1, 0);
        parent.resize(n+1, 0);
        size.resize(n+1, 1);
        for(int i = 0; i<=n; i++){
            parent[i] = i;
        }
    }

    //Recursive function to track ultimate parent and compress the node <-> parent relation to node <-> ultimate_parent relation
    int findUPar(int node){
        if(node == parent[node]) return node;

        return parent[node] = findUPar(parent[node]);
    }

    //always attack smaller rank node with larger rank node 
    void unionByRank(int u, int v){
        int ulp_u = parent[u];
        int ulp_v = parent[v];
        if(ulp_u == ulp_v) return;

        if(rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        }else if(rank[ulp_v] < rank[ulp_u]){
            parent[ulp_v] = ulp_u;
        }else{
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    //Both union by rank and union by size work on same logic, which ever is lesser will attached to greater rank/size, but size vala more intuitive because we just need to attach all the nodes
    //and increase the size of the parent node, that's it, in rank, the structure will get distort due to ultimate parent compression
    void unionBySize(int u, int v){
        int ulp_u = parent[u];
        int ulp_v = parent[v];
        if(ulp_u == ulp_v) return;

        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }else{
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }

};

int main() {

    return 0;
}

