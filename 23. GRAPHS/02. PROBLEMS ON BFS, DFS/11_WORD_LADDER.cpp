/*
====================================================
WORD LADDER
LeetCode:
https://leetcode.com/problems/word-ladder/description/
====================================================

💡 PROBLEM SUMMARY
- Given:
    beginWord
    endWord
    wordList

Goal:
✔ Find the length of the shortest transformation
  sequence from beginWord to endWord.

Rules:
✔ Change only ONE character at a time
✔ Each transformed word must exist in wordList
✔ Return number of words in shortest path
✔ If no transformation possible → return 0

====================================================
KEY IDEA: BFS (SHORTEST PATH IN UNWEIGHTED GRAPH) ⭐
----------------------------------------------------
This problem can be visualized as a graph:

✔ Each word = node
✔ Edge exists if two words differ by 1 character

We need:
✔ Shortest path from beginWord → endWord

Why BFS?
✔ BFS explores level by level
✔ First time we reach endWord = shortest path

====================================================
APPROACH
----------------------------------------------------
STEP 1: Store words in a set
----------------------------------------------------
Use unordered_set for:
✔ O(1) lookup
✔ Efficient deletion of visited words

If endWord is not present:
    return 0 immediately

----------------------------------------------------

STEP 2: Initialize BFS
----------------------------------------------------
Queue stores:
    {currentWord, steps}

Start with:
    {beginWord, 1}

Remove beginWord from set to avoid revisiting.

----------------------------------------------------

STEP 3: BFS Traversal
----------------------------------------------------
For each word popped:

✔ If word == endWord:
      return steps

✔ Try all transformations:
    For each index:
        replace with 'a' → 'z'

✔ If transformed word exists in set:
      - push into queue with steps + 1
      - remove from set (mark visited)

----------------------------------------------------

STEP 4: Continue until queue empty
----------------------------------------------------
If BFS finishes and endWord not reached:
    return 0

====================================================
IMPORTANT CONDITIONS
----------------------------------------------------
✔ Each transformation must exist in wordList
✔ Each word is used only once (remove from set)
✔ Only 1-letter difference allowed
✔ BFS ensures shortest path

====================================================
TIME & SPACE ANALYSIS
----------------------------------------------------
TIME COMPLEXITY:
➡ O(N × L × 26)
where:
    N = number of words
    L = length of each word

For each word:
    try changing every character (L)
    with 26 possibilities

SPACE COMPLEXITY:
➡ O(N)
(for set + queue)

====================================================
KEY TAKEAWAY
----------------------------------------------------
This is a classic shortest path problem in an
unweighted graph → solved using BFS.

Main trick:
Generate all possible one-letter transformations
and use a set to efficiently check validity.

====================================================
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());
        if(st.find(endWord) == st.end()) return 0;

        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        st.erase(beginWord);

        while(!q.empty()){
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();

            if(word == endWord) return steps;

            for(int i = 0; i<word.size(); i++){
                char original = word[i];
                for(char ch = 'a'; ch<= 'z'; ch++){
                    word[i] = ch;
                    if(st.find(word) != st.end()){
                        st.erase(word);
                        q.push({word, steps+1});
                    }
                }

                word[i] = original;
            }
        }

        return 0;
    }
};

int main(){
    
    return 0;
}