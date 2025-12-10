/*
#PRINT NAME N TIMES USING RECURSION

LINK: :- https://www.naukri.com/code360/problems/-print-n-times_8380707?leftPanelTabValue=PROBLEM
*/

#include<bits/stdc++.h>
using namespace std;


//TIME COMPLEXITY :- O(N)
void solve( int n, vector<string> &ans){
    //BASE CASE
	if(n <= 0){
		return;
	}

    //PROCESS
	ans.push_back("Coding");
	ans.push_back("Ninjas");

    //RECURSIVE CALL
	solve(n-1, ans);
}

vector<string> printNTimes(int n) {
	vector<string> ans;
	solve(n,ans);
	return ans;
}

int main(){
    vector<string> ans = printNTimes(3);
    for(auto i : ans){
        cout<<i<<" ";
    }
    return 0;
}