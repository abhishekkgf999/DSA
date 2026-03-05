/*
#TASK SCHEDULAR

LINK:- https://leetcode.com/problems/task-scheduler/description/
*/

#include<bits/stdc++.h>
using namespace std;


/*
💡 PROBLEM SUMMARY:
- Given tasks represented by capital letters (A–Z)
- Same tasks must have at least `n` units of cooldown between them
- Each task takes exactly 1 unit time
- Find the MINIMUM total time to finish all tasks

====================================================
KEY OBSERVATION:
----------------------------------------------------
👉 At maximum, we can execute (n + 1) tasks in one cycle
- 1 task execution
- n cooldown slots (can be idle or other tasks)

====================================================
APPROACH: GREEDY + MAX HEAP ⭐
----------------------------------------------------
IDEA:
- Jis task ki frequency zyada hai, use pehle execute karna best hai
- Isse future me idle time kam hota hai

----------------------------------------------------
STEPS:
1️⃣ Frequency count:
   - 26 size vector me har task ki frequency store karo

2️⃣ Max Heap:
   - Saari non-zero frequencies ko max heap me daalo
   - Heap top = highest frequency task

3️⃣ Scheduling loop:
   - Jab tak heap empty na ho:
        ➜ Ek temporary vector banao (current cycle ke liye)

4️⃣ Ek cycle me (n + 1) tasks execute karo:
   - Heap se top element nikaalo
   - Uski frequency 1 se decrease karo
   - Decreased frequency temp vector me daal do

5️⃣ Cycle ke baad:
   - Jo frequencies > 0 hain
     ➜ unhe heap me wapas daal do

6️⃣ Time calculation:
   - Agar heap empty ho gayi:
        ➜ time += temp.size()
        (last cycle, no idle time needed)
   - Else:
        ➜ time += (n + 1)
        (full cycle with possible idle slots)

----------------------------------------------------
WHY THIS WORKS?
----------------------------------------------------
✔ Max frequency tasks pehle finish hote hain
✔ Cooldown automatically manage ho jata hai
✔ Idle time minimum hota hai
✔ Greedy choice gives optimal answer

====================================================
TIME & SPACE ANALYSIS
----------------------------------------------------
- Total tasks = T

TIME COMPLEXITY:
➡ O(T log 26) ≈ O(T)
(Heap size max 26)

SPACE COMPLEXITY:
➡ O(26) ≈ O(1)

====================================================
IMPORTANT EDGE CASE:
----------------------------------------------------
- Agar n = 0:
  ➜ No cooldown
  ➜ Answer = total number of tasks

====================================================
*/

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> mpp(26, 0);

        for(char &ch: tasks){
            mpp[ch-'A']++;
        }

        int time = 0;

        priority_queue<int> pq;

        for(int i = 0; i<26; i++){
            if(mpp[i] > 0) pq.push(mpp[i]);
        }

        while(!pq.empty()){
            vector<int> temp;

            for(int i = 1; i<=n+1; i++){
                if(!pq.empty()){
                    int freq = pq.top();
                    pq.pop();
                    freq--;
                    temp.push_back(freq);
                }
            }

            for(int &f : temp){
                if(f > 0) pq.push(f);
            }

            if(pq.empty()){
                time += temp.size();
            }else time += n+1;
        }

        return time;
    }
};

int main(){
    
    return 0;
}