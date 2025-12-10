//https://www.naukri.com/code360/problems/count-ways-to-reach-nth-stairs_798650

#include<iostream>
using namespace std;

/*
 
### **Recursive Code for Counting Ways to Reach Nth Stairs**  

#### **Intuition:**  
To reach the **Nth stair**, we can come from:  
- `(N-1)th stair` by taking **1 step**  
- `(N-2)th stair` by taking **2 steps**  

So, the total ways to reach `N` will be:  
**Ways(N) = Ways(N-1) + Ways(N-2)**  

#### **Approach (Recursive Solution):**  
1. **Base Case:**  
   - If `n < 0 → return 0` (Invalid path)  
   - If `n == 0 → return 1` (Valid path, count this sequence)  

2. **Recursive Case:**  
   - Recursively calculate:  
     `ans = countDistinctWays(n-1) + countDistinctWays(n-2)`  

#### **Time Complexity:** `O(2^N)` (Exponential)  
#### **Optimization Needed:** Memoization or Tabulation  

✅ This is a classic **Fibonacci DP Problem**.

*/

int countDistinctWays(int n) {
    //BASE CASE
    if(n < 0){
        return 0;
    }

    if(n == 0){
        return 1;
    }
    
    //RECURSIVE CASE
    int ans = countDistinctWays(n-1) + countDistinctWays(n-2);

    return ans;
    
}

int main(){
    int n;
    cout<<"Enter number of stairs:- ";
    cin>>n;

    cout<<countDistinctWays(n);
    return 0;
}