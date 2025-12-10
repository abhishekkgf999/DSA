/*

#MERGE OVERLAPPING SUBINTERVALS  (MARK FOR REVISION)

LINK:- https://leetcode.com/problems/merge-intervals/


Example 1:
Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].

Example 2:
Input: intervals = [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.

Example 3:
Input: intervals = [[1,4],[2,3]]
Output: [[1,4]]
Explanation: Intervals [1,4] and [2,3] are considered overlapping.
 

*/



#include<bits/stdc++.h>
using namespace std;

//BRUTE FORCE SOLUTION (TC:-  O(N*logN) + O(2*N) & SC:- O(N))
/*

1. **Sorting the intervals**: 
   - The intervals are first sorted based on their starting points (`intervals.begin(), intervals.end()`). 
     This helps to easily identify overlapping intervals as overlapping ones will be adjacent or nearby.

2. **Iterating through the intervals**: 
   - You loop through each interval in the sorted list.
   - For each interval, you start by noting the `start` and `end` times.

3. **Skipping fully contained intervals**:
   - If the current interval is fully contained within the last interval in the `ans` array 
     (i.e., `end` is less than or equal to the last merged interval's `end`), then the interval is skipped. 
     This ensures that smaller intervals inside larger ones are ignored.

4. **Merging overlapping intervals**: 
   - For each interval, you check if the `end` of the current interval overlaps with the next interval (`intervals[j][0]`). 
   - If they overlap, you adjust the `end` to be the maximum of the two (`max(end, intervals[j][1])`).
   - You continue merging until you find a non-overlapping interval.

5. **Adding the merged interval**:
   - Once you’ve found the maximal `end` for a series of overlapping intervals, you push the merged interval (`start, end`) 
     into the `ans` vector.

6. **Final result**:
   - The process repeats for all intervals, and the result is a vector of merged intervals.

### In short:
- **Sort the intervals** to process them in order.
- For each interval, if it overlaps with the next, **merge them** by updating the end.
- Skip intervals already covered by a previous one.
- **Add** the merged interval to the result. 


*/
vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        
        for(int i = 0; i<n; i++){

            int start = intervals[i][0];
            int end = intervals[i][1];

            if(!ans.empty() &&  ans.back()[1] >= end) continue;

            for(int j = i+1; j<n; j++){
                if(end >= intervals[j][0]){
                    end = max(end, intervals[j][1]);
                }
                else{
                    break;
                }
            }

            ans.push_back({start,end});

        }

        return ans;
    }

//OPTIMAL SOLUTION (TC:- O(N*logN) + O(N) & SC:- O(N))
/*

**Intuition:**

=> In the previous approach, while checking the intervals, we first selected an interval using a loop and then compared it 
   with others using another loop. But in this approach, we will try to do the same using a single loop. Let’s understand how:

=> We will start traversing the given array with a single loop. At the first index, as our answer list is empty, we will insert 
   the first element into the answer list. While traversing afterward we can find two different cases:

***Case 1: If the current interval can be merged with the last inserted interval of the answer list:
           
        => In this case, we will update the end of the last inserted interval with the maximum(current interval’s end, last inserted interval’s end) 
           and continue moving afterward. 

***Case 2: If the current interval cannot be merged with the last inserted interval of the answer list:

        => In this case, we will insert the current interval in the answer array as it is. And after this insertion, 
           the last inserted interval of the answer list will obviously be updated to the current interval.

#Note: Within the previous approach, we have already discussed how to check if the current interval can or cannot be merged with the 
       other interval.

#Approach:
The steps are as follows:

1. First, we will group the closer intervals by sorting the given array of intervals(if it is not already sorted).

2. After that, we will start traversing the array using a loop(say i) and insert the first element into our answer 
   list(as the answer list is empty).

3. Now, while traversing we will face two different cases:

    **Case 1: If the current interval can be merged with the last inserted interval of the answer list:

        ==> In this case, we will update the end of the last inserted interval with the 
            maximum(current interval’s end, last inserted interval’s end) and continue moving afterward. 

    **Case 2: If the current interval cannot be merged with the last inserted interval of the answer list:

        => In this case, we will insert the current interval in the answer array as it is. And after this insertion, 
           the last inserted interval of the answer list will obviously be updated to the current interval.

4. Thus the answer list will be updated with the merged intervals and finally, we will return the answer list.

Intuition: Since we have sorted the intervals, the intervals which will be merging are bound to be adjacent. We kept on merging simultaneously as we were traversing through the array and when the element was non-overlapping we simply inserted the element in our answer list.
*/
vector<vector<int>> merge1(vector<vector<int>>& intervals) {
        int n = intervals.size();

        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ans;

        for(int i = 0; i<n; i++){
            if(ans.empty() || ans.back()[1] < intervals[i][0]){
                ans.push_back(intervals[i]);
            }
            else{
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            }
        }

        return ans;

    }

int main(){
    
    // vector<vector<int>> intervals = {{1,4}, {2,3}};
    vector<vector<int>> intervals = {{1,3}, {2,6}, {8,10}, {15,18}};

    vector<vector<int>> ans = merge(intervals);

    for(auto i : ans){
        for(auto j : i){
            cout<<j<<" ";
        }cout<<endl;
    }

    return 0;
}