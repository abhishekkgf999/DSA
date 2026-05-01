/*
====================================================
COURSE SCHEDULE II
LeetCode:
https://leetcode.com/problems/course-schedule-ii/description/
====================================================

💡 PROBLEM SUMMARY
- Given:
    • numCourses (0 to n-1)
    • prerequisites list [a, b]
      → to take course 'a', you must first take 'b'

Goal:
✔ Return a valid order to complete all courses

✔ If impossible (cycle exists) → return empty array

====================================================
KEY IDEA: TOPOLOGICAL SORT (KAHN'S ALGORITHM) 🔄
----------------------------------------------------
Interpretation:
✔ Courses → Nodes
✔ Prerequisites → Directed edges

Edge:
    b → a
(b must be completed before a)

This is a classic:
✔ "dependency ordering" problem

Whenever problem says:
    "A must be done before B"
→ Think TOPOLOGICAL SORT

====================================================
WHY THIS WORKS
----------------------------------------------------
✔ If graph has no cycle:
      → valid topological ordering exists

✔ If graph has cycle:
      → no valid ordering possible

So:
✔ Perform topo sort
✔ If all nodes included → valid answer
✔ Else → cycle exists → return empty

====================================================
APPROACH
----------------------------------------------------
STEP 1: Build graph
----------------------------------------------------
✔ Create adjacency list

For prerequisite [a, b]:
    b → a

✔ Increase indegree of 'a'

----------------------------------------------------

STEP 2: Initialize queue
----------------------------------------------------
Push all nodes with:
    indegree = 0

These have no dependencies

----------------------------------------------------

STEP 3: BFS (Kahn's Algorithm)
----------------------------------------------------
While queue not empty:

✔ Pop node
✔ Add it to answer

✔ For all neighbours:
      decrease indegree

✔ If indegree becomes 0:
      push into queue

----------------------------------------------------

STEP 4: Final check
----------------------------------------------------
✔ If ans.size() == numCourses:
      → valid ordering found → return ans

✔ Else:
      → cycle exists → return empty array

====================================================
IMPORTANT CONDITIONS
----------------------------------------------------
✔ Edge direction: prerequisite → course
✔ Indegree represents dependency count
✔ Cycle prevents full topo ordering
✔ Output must include all courses

====================================================
TIME & SPACE ANALYSIS
----------------------------------------------------
TIME COMPLEXITY:
➡ O(V + E)

SPACE COMPLEXITY:
➡ O(V)
(for indegree + queue + adjacency list)

====================================================
KEY TAKEAWAY
----------------------------------------------------
This is a direct extension of Course Schedule I.

Core idea:
✔ Instead of just checking possibility,
  we return the actual topological order

Rule to remember:
✔ "A before B" → use Topological Sort

====================================================
*/

#include<bits/stdc++.h>
using namespace std;

//SIMPLE DETECTION OF CYCLE IN DIRECTED GRAPH, IF THERE IS NO CYCLE (ans.size() == numCourses) THEN RETURN TOPO SORT, OTEHR WISE RETURN EMPTY ARRAY

//ALWAYS REMEMBER TO USE TOPO SORT WHEN THERE IS SOMETHING STATED THAT, (SOMETHING BEFORE SOMETHING)
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        vector<int> inDegree(numCourses, 0);

        for (int i = 0; i < prerequisites.size(); i++) {
            inDegree[prerequisites[i][0]]++;
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (inDegree[i] == 0)q.push(i);
        }

        vector<int> ans;
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            ans.push_back(v);
            for (auto it : adj[v]) {
                inDegree[it]--;
                if (inDegree[it] == 0) q.push(it);
            }
        }

        if (ans.size() == numCourses) return ans;

        return {};
    }
};

int main() {

    return 0;
}