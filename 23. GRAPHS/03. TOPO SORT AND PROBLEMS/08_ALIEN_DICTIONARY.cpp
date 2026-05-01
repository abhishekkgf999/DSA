/*
====================================================
ALIEN DICTIONARY
GeeksforGeeks:
https://www.geeksforgeeks.org/problems/alien-dictionary/1
====================================================

💡 PROBLEM SUMMARY
- Given:
    • A sorted dictionary of words (according to alien language)

Goal:
✔ Find the order of characters in the alien language

----------------------------------------------------
Rules:
✔ Words are sorted lexicographically (alien rules)
✔ We must derive character ordering from this

✔ If invalid ordering → return ""

====================================================
KEY IDEA: GRAPH + TOPOLOGICAL SORT 🔄
----------------------------------------------------
We need to determine order of characters.

Idea:
✔ Treat each character as a node
✔ Create directed edges based on ordering rules

Edge:
    u → v
means:
    character u comes before character v

Once graph is built:
✔ Apply Topological Sort to get valid ordering

====================================================
HOW TO BUILD GRAPH
----------------------------------------------------
Compare adjacent words:

For two words:
    s1 and s2

Find first index where:
    s1[j] != s2[j]

Then:
    s1[j] → s2[j]

Why?
✔ Because s1 appears before s2 in dictionary

----------------------------------------------------

IMPORTANT EDGE CASE 🚨
----------------------------------------------------
If:
    s1 = "abc"
    s2 = "ab"

✔ s2 is prefix of s1 but smaller word comes later

→ Invalid dictionary → return ""

====================================================
APPROACH
----------------------------------------------------
STEP 1: Build graph
----------------------------------------------------
✔ Compare adjacent words
✔ Find first different character
✔ Add directed edge

✔ Maintain indegree for each node

----------------------------------------------------

STEP 2: Track unique characters
----------------------------------------------------
✔ Use set to store all distinct characters
✔ This ensures we only process valid nodes

----------------------------------------------------

STEP 3: Topological Sort (Kahn’s Algorithm)
----------------------------------------------------
✔ Push all characters with indegree = 0 into queue

✔ While queue not empty:
      - pop character
      - add to answer
      - reduce indegree of neighbours

✔ If neighbour indegree becomes 0:
      push into queue

----------------------------------------------------

STEP 4: Validate result
----------------------------------------------------
✔ If result size == total unique characters:
      → valid ordering

✔ Else:
      → cycle exists → return ""

====================================================
IMPORTANT CONDITIONS
----------------------------------------------------
✔ Only first different character determines order
✔ Graph may have multiple valid topological orders
✔ Prefix edge case must be handled
✔ Cycle in graph → invalid ordering

====================================================
TIME & SPACE ANALYSIS
----------------------------------------------------
TIME COMPLEXITY:
➡ O(N * L + K)
N = number of words
L = max length of word
K = number of unique characters

SPACE COMPLEXITY:
➡ O(K + E)
(for graph + indegree + queue)

====================================================
KEY TAKEAWAY
----------------------------------------------------
This is a classic:
✔ "Find order from sorted dictionary"

Steps:
✔ Build graph from adjacent word comparison
✔ Apply Topological Sort
✔ Handle prefix edge case carefully

====================================================
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string findOrder(vector<string>& words) {
        // code here
        vector<int> adj[26];
        vector<int> inDegree(26, 0);
        set<int> st;

        for (int i = 0; i < words.size() - 1; i++) {
            string s1 = words[i];
            string s2 = words[i + 1];

            bool found = false;
            for (int j = 0; j < min(s1.length(), s2.length()); j++) {
                if (s1[j] != s2[j]) {
                    adj[s1[j] - 'a'].push_back(s2[j] - 'a');
                    inDegree[s2[j] - 'a']++;
                    found = true;
                    break;
                }
            }
            if (!found && s1.length() > s2.length()) return "";
        }

        for (auto& word : words) {
            for (char c : word) {
                st.insert(c - 'a');
            }
        }

        int V = st.size();
        string ans = "";
        queue<int> q;
        for (auto it : st) {
            if (inDegree[it] == 0) q.push(it);
        }

        while (!q.empty()) {
            int top = q.front();
            q.pop();
            ans += 'a' + top;
            for (auto it : adj[top]) {
                inDegree[it]--;
                if (inDegree[it] == 0) q.push(it);
            }
        }

        return ans.size() == V ? ans : "";
    }
};

int main() {

    return 0;
}