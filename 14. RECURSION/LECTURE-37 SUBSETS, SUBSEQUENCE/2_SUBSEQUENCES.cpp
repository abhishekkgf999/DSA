/*
#SUBSEQUENCES

LINK:- https://www.naukri.com/code360/problems/subsequences-of-string_985087?leftPanelTab=0
*/

#include<bits/stdc++.h>
using namespace std;

void solve(string str, vector<string> &ans, int index, string temp){
	//BASE CASE
	if(index >= str.size()){
		if(temp != "") ans.push_back(temp);     //WE DONT HAVE TO INCLUDE EMPTY SUBSEQUENCE

		return;
	}

	//EXCLUDE
	solve(str, ans, index+1, temp);

	//INCLUDE
	temp = temp + str[index];
	solve(str, ans, index+1, temp);
}

vector<string> subsequences(string str){
	
	vector<string> ans;
	int index = 0;
	string temp = "";

	solve(str, ans, index, temp);

	return ans;
	
}

int main(){
    
    return 0;
}