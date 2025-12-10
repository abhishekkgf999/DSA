/*
#Remove duplicates from Sorted array

link:- https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/

*/

#include<bits/stdc++.h>
using namespace std;

/*
The worst-case scenario occurs when there are no duplicates in the array, and the function runs in O(n) time, 
where n is the size of the input vector nums.

the space complexity is O(1), constant space.
*/
//MY SOLUTION ↴
int removeDuplicates1(vector<int>& nums) {
        int k=0;
        int count = 0;
        int i=0;
        while(k<nums.size()){
            count = 1;
            for(int j=k+1; j<nums.size(); j++){
                if(nums[k] == nums[j]) count++;
                else break;
            }
            nums[i++] = nums[k];
            k = k+count;
        }
        
        return i;
    }

//OPTIMAL SOLUTION (LINK:- https://leetcode.com/problems/remove-duplicates-from-sorted-array/solutions/3676877/best-method-100-c-java-python-beginner-friendly)
//TIME COMPLEXITY:- O(N), SPACE COMPLEXITY:- O(1)
int removeDuplicates2(vector<int>& nums) {
        int j = 1; 
        for(int i =1; i<nums.size(); i++){
            if(nums[i-1] != nums[i]){
                nums[j++] = nums[i];
            }
        }
        return j;
    }

int main(){
    vector<int> arr = {0,0,1,1,1,2,2,3,3,4};
    cout<<"number of unique elements in array:- "<<removeDuplicates1(arr)<<endl;
    for(auto i : arr){
        cout<<i<<" ";
    }
    return 0;
}