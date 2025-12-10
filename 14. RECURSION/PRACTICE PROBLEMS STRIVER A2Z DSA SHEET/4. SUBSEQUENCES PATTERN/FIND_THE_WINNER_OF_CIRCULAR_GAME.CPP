/*
#FIND THE WINNER OF CIRCULAR GAME

LINK:- https://leetcode.com/problems/find-the-winner-of-the-circular-game/
*/

#include<bits/stdc++.h>
using namespace std;

    int solve(int k, vector<int> &arr, int index){
        if(arr.size() == 1){    //LAST PERSON LEFT
            return arr[0];
        }
        
        //FINDING THE INDEX(PERSON) WHICH HAVE TO DELETE(KILL) FROM ARRAY
        index = (index+k)%arr.size();
        arr.erase(arr.begin() + index);

        return solve(k, arr, index); //DELETING (KILLING) FOR REMAINING ONES
    }
    int findTheWinner(int n, int k) {
        vector<int> arr;
        for(int i = 1; i<=n; i++){
            arr.push_back(i);
        } 
        return solve(k-1, arr, 0);
    }

int main(){
    cout<<findTheWinner(5, 2);
    return 0;
}