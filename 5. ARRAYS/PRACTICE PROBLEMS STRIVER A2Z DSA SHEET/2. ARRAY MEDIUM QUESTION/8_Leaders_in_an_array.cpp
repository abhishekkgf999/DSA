/*
#LEADERS IN AN ARRAY PROBLEM

LINK:- https://www.naukri.com/code360/problems/superior-elements_6783446
*/


#include<bits/stdc++.h>
using namespace std;

//BRUTE FORCE SOLUTION
//TIME COMPLEXITY:- O(N^2), SPACE COMPLEXITY:- O(N)
vector<int> superiorElements1(vector<int>&a) {
    vector<int> ans;
    int n =  a.size();
    ans.push_back(a[n-1]);
    for(int i = n-2; i>=0; i--){
        bool valid = true;
        for(int j = i+1; j<n; j++){
          if (a[j] >= a[i]) {
            valid = false;
            break;
          }
        }
        if(valid) ans.push_back(a[i]);
    }

    return ans;
}

//OPTIMAL SOLUTION
//TIME COMPLEXITY:- O(N), SPACE COMPLEXITY:- O(N)
vector<int> superiorElements2(vector<int>&a) {
    vector<int> ans;
    int n =  a.size();
    ans.push_back(a[n-1]);
    int i = n-1, j = n-2;
    while(j>=0){
        if(a[j]>a[i]){
            ans.push_back(a[j]);
            i = j;
        }
        j--;
    }
    return ans;
}

int main(){
    vector<int> a = {1,2,2,1};
    vector<int> ans = superiorElements1(a);
    for(auto i : ans){
        cout<<i<<" ";
    }
    return 0;
}