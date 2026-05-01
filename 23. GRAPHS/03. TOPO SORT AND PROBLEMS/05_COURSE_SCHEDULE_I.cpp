/*
====================================================
COURSE SCHEDULE I
LeetCode:
https://leetcode.com/problems/course-schedule/description/
====================================================

💡 PROBLEM SUMMARY
- Given:
    • numCourses (0 to n-1)
    • prerequisites list [a, b]
      → to take course 'a', you must first take 'b'

Goal:
✔ Determine if it is possible to finish all courses

====================================================
KEY IDEA: CYCLE DETECTION IN DIRECTED GRAPH 🔁
----------------------------------------------------
Interpretation:
✔ Courses → Nodes
✔ Prerequisites → Directed edges

Edge:
    b → a
(means b must be completed before a)

Observation:
✔ If graph contains a cycle:
      → impossible to complete all courses

✔ If no cycle:
      → valid ordering exists → possible

So problem reduces to:
✔ Detect cycle in directed graph

====================================================
APPROACH: BFS (KAHN'S ALGORITHM)
----------------------------------------------------
We use topological sorting to detect cycle.

If we can generate a valid topo order of all courses:
    → no cycle → return true

If not:
    → cycle exists → return false

====================================================
STEP-BY-STEP
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
Push all courses with:
    indegree = 0

These have no prerequisites

----------------------------------------------------

STEP 3: BFS Traversal
----------------------------------------------------
✔ Pop course from queue
✔ Increment count of completed courses

✔ For its neighbours:
      decrease indegree

✔ If indegree becomes 0:
      push into queue

----------------------------------------------------

STEP 4: Final check
----------------------------------------------------
✔ If count == numCourses:
      → all courses processed → return true

✔ Else:
      → some courses couldn't be completed
      → cycle exists → return false

====================================================
IMPORTANT CONDITIONS
----------------------------------------------------
✔ Directed graph representation is crucial
✔ Edge direction: prerequisite → course
✔ Cycle prevents some nodes from reaching indegree 0
✔ Count of processed nodes determines result

====================================================
TIME & SPACE ANALYSIS
----------------------------------------------------
TIME COMPLEXITY:
➡ O(V + E)
(V = courses, E = prerequisites)

SPACE COMPLEXITY:
➡ O(V)
(for indegree + queue + adjacency list)

====================================================
KEY TAKEAWAY
----------------------------------------------------
This problem is a direct application of
cycle detection using Kahn’s Algorithm.

Core idea:
✔ If topological sort includes all nodes → possible
✔ Otherwise → cycle exists → not possible

====================================================
*/


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        vector<int> inDegree(numCourses, 0);

        for(int i = 0; i<prerequisites.size(); i++){
            inDegree[prerequisites[i][0]]++;
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        queue<int> q;
        for(int i = 0; i<numCourses; i++){
            if(inDegree[i] == 0)q.push(i);
        }

        int cnt = 0;
        while(!q.empty()){
            int v = q.front();
            q.pop();
            cnt++;
            for(auto it : adj[v]){
                inDegree[it]--;
                if(inDegree[it] == 0) q.push(it);
            }
        }

        return cnt == numCourses;
    }
};

int main(){
    
    return 0;
}