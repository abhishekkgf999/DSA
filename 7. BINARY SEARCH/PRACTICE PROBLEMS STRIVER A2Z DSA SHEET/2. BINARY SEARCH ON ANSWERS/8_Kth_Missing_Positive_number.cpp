/*

#Kth Missing Positive Number (MARK FOR REVISION)

Link:- https://leetcode.com/problems/kth-missing-positive-number/description/

*/

#include<bits/stdc++.h>
using namespace std;

//BRUTE FORCE SOLUTION
int findKthPositive1(vector<int>& arr, int k) {
        int n = arr.size();
        set<int> temp;
        for(auto i : arr){
            temp.insert(i);
        }
        int missing_kth_number = -1;
        int high = *max_element(arr.begin(), arr.end());
        int count = 0;
        for(int i = 1; i<=high; i++){
            if(temp.find(i) == temp.end()){
                count++;
                if(count == k) return i;
            }
        }

        if(k > count) {
            return arr[n-1] + (k-count);
        }

        return -1;
    }


//BETTER SOLUTION (TC:- O(N) & SC:- O(1))
/*
=>  In this solution, assume if we have empty array {}, and we want to find 5th missing
    number, so the missing number list will be:- [1,2,3,4,5] and hence our array is empty
    the missing number will be 5.

=>  Now suppose we just inserted a number which is smaller than the 5 (lets say 2), array = {2}
    now missing number lists will be look like this :- {1,2(present),3,4,5,6} => notice that
    the missing number position is shifted by one place, and the missing number will be 6 now

=> That's why we incrementing the finding position if we encounter any smaller number.

=>  For bigger number, assume we inserted 7, and we have 2 in our array already, now we have to 
    find 5th missing number, and the missing number lists will look like this :- [1,2(present), 3,4,5,6,7(present)]
    => notice here that if we insert any bigger number than the finding missing number position, then it will not effect its 
    value. 

=> That's why when we encountering any bigger number than the missing number position, we just breaking the loop.
    because the missing number will lie always before that bigger number.

*/
int findKthPositive_linearSearch(vector<int>& arr, int k) {
        for(int i = 0; i<arr.size(); i++){
            if(arr[i] <= k){
                k++;
            }
            else{
                break;
            }
        }
        return k;
        
    }

//OPTIMAL SOLUTION (TC:- O(logN) & SC:- O(1))
/*
=>  We cannot apply binary search on the answer space here as we cannot assure which missing number has the possibility of being the kth 
    missing number. That is why, we will do something different here. We will try to find the closest neighbors (i.e. Present in the array) 
    for the kth missing number by counting the number of missing numbers for each element in the given array.

=>  Let’s understand it using an example. Assume the given array is {2, 3, 4, 7, 11}. Now, if no numbers were missing the given array would 
    look like {1, 2, 3, 4, 5}. Comparing these 2 arrays, we can conclude the following:

->  Up to index 0: Only 1 number i.e. 1 is missing in the given array.
->  Up to index 1: Only 1 number i.e. 1 is missing in the given array.
->  Up to index 2: Only 1 number i.e. 1 is missing in the given array.
->  Up to index 3: 3 numbers i.e. 1, 5, and 6 are missing.
->  Up to index 4: 6 numbers i.e. 1, 5, 6, 8, 9, and 10 are missing.

=>  For a given value of k as 5, we can determine that the answer falls within the range of 7 to 11. Since there are only 3 missing numbers 
    up to index 3, the 5th missing number cannot be before vec[3], which is 7. Therefore, it must be located somewhere to the right of 7. 
    Our actual answer i.e. 9 also supports this theory. So, by following this process we can find the closest neighbors 
    (i.e. Present in the array) for the kth missing number. In our example, the closest neighbors of the 5th missing number are 7 and 11.

=>How to calculate the number of missing numbers for any index i?

->  From the above example, we can derive a formula to find the number of missing numbers before any array index, i. The formula is
->  Number of missing numbers up to index i = "vec[i] - (i+1)".
->  The given array, vec, is currently containing the number vec[i] whereas it should contain (i+1) if no numbers were missing. 
    The difference between the current and the ideal element will give the result.

=>  Now, we will simply add more_missing_numbers to the preceding neighbor i.e. vec[high] to get the kth missing number.
        kth missing number  = vec[high] + k - (vec[high] - (high+1))
                            = vec[high] + k - vec[high] + high + 1
                            = k + high + 1.
*/
int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        int l =0, r = n-1;
        while(l<=r){
            int mid = l + (r-l)/2;
            int missing = arr[mid] - (mid+1);
            if(missing < k) l = mid+1;
            else r = mid-1;
        }

        return (l + k);
    }

int main(){
    vector<int> arr = {2,3,4,7,11};
    cout<<findKthPositive(arr, 5);
    return 0;
}