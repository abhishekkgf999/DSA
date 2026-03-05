/*
#Kth Largest Element in an array

Link:- https://leetcode.com/problems/kth-largest-element-in-an-array/description/

*/

#include<bits/stdc++.h>
using namespace std;

/*
💡 PROBLEM SUMMARY:
- Given an array of integers
- Find the Kth largest element (not the Kth distinct)
- Array ko sort kiye bina optimized solution chahiye

====================================================
APPROACH 1: MAX HEAP (STRAIGHTFORWARD)
----------------------------------------------------
IDEA:
- Max heap me largest element hamesha top pe hota hai

STEPS:
1️⃣ Saare elements max heap me push karo
2️⃣ K-1 times pop karo
3️⃣ Heap ka top = Kth largest element

----------------------------------------------------
TIME & SPACE:
- Heap insertion = O(n log n)
- K pops = O(k log n)

TIME COMPLEXITY:
➡ O(n log n)

SPACE COMPLEXITY:
➡ O(n)

----------------------------------------------------
WHEN TO USE?
✔ Jab constraints small ho
✔ Easy to understand, direct approach

*/

class Solution1 {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for(auto i : nums) pq.push(i);

        for (int i = 1; i < k; i++)
            pq.pop();

        return pq.top();
    }
};

/*
====================================================
APPROACH 2: MIN HEAP OF SIZE K (OPTIMAL) ⭐
----------------------------------------------------
IDEA:
- Sirf K largest elements hi heap me rakhenge
- Heap ka top hamesha smallest among those K elements hoga

----------------------------------------------------
STEPS:
1️⃣ Ek min heap banao
2️⃣ Array ke elements ek-ek karke push karo
3️⃣ Jaise hi heap size > k:
      ➜ top element pop kar do (smallest nikal jayega)
4️⃣ End me heap ke andar sirf K largest elements rahenge
5️⃣ Heap ka top = Kth largest element

----------------------------------------------------
WHY THIS WORKS?
- Min heap smallest element ko top pe rakhta hai
- Jab (k+1)th element aata hai:
    ➜ sabse chhota element automatically remove ho jata hai
- Isliye heap me hamesha top K elements hi bache rehte hain

----------------------------------------------------
TIME & SPACE:
- Har insertion = log k
- Total elements = n

TIME COMPLEXITY:
➡ O(n log k)

SPACE COMPLEXITY:
➡ O(k)

----------------------------------------------------
BEST CHOICE?
⭐ Approach 2 (Min Heap of size K)
- Better performance
- Interview favorite
====================================================
*/
class Solution2 {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;

        for(auto it  : nums){
            pq.push(it);
            if(pq.size() > k){
                pq.pop();
            }
        }

        return pq.top();
    }
};

int main(){
    
    return 0;
}