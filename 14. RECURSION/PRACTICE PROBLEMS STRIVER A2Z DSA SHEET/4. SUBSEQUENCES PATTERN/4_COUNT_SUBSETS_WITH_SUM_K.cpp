/*
#COUNT SUBSETS WITH SUM K

LINK:- https://www.naukri.com/code360/problems/count-subsets-with-sum-k_3952532
*/

#include<bits/stdc++.h>
using namespace std;

void solve(vector<int> &arr, int index, int sum, int &count, int target){
	if(sum == target){
        count++;
        return;
    }
    
    if(index >= arr.size()){ // Ensure index doesn't go out of bounds
        return;
    }

    // Include the current element
    solve(arr, index+1, sum + arr[index], count, target);

    // Exclude the current element
    solve(arr, index+1, sum, count, target);

}


int findWays(vector<int>& arr, int target){
	int count = 0;
	int sum = 0;
	solve(arr, 0, sum, count, target);
	return count;
}


int main(){
    vector<int> arr = {12, 14, 3, 18, 2};
    int target = 13;
    cout<<findWays(arr, target);
    return 0;
}