/*
#FIND THE WINNER OF CIRCULAR GAME

LINK:- https://leetcode.com/problems/find-the-winner-of-the-circular-game/
*/

#include<bits/stdc++.h>
using namespace std;

void solve(int k, vector<int> &arr, int index, int &ans){
        if(arr.size() == 1){    //LAST PERSON LEFT
            ans = arr[0];
            return;
        }
        
        //FINDING THE INDEX(PERSON) WHICH HAVE TO DELETE(KILL) FROM ARRAY
        index = (index+k)%arr.size();
        arr.erase(arr.begin() + index);

        solve(k, arr, index, ans); //DELETING (KILLING) FOR REMAINING ONES
    }
    int findTheWinner(int n, int k) {
        vector<int> arr;
        for(int i = 1; i<=n; i++){
            arr.push_back(i);
        }
        int ans = -1;
        solve(k-1, arr, 0, ans);
        return ans;
    }

int main(){
    cout<<findTheWinner(5, 2);
    return 0;
}