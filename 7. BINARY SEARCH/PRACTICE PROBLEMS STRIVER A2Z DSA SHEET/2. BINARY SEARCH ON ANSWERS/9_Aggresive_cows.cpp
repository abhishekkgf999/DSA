/*

#AGGRESIVE COWS

LINK:- https://www.naukri.com/code360/problems/aggressive-cows_1082559?source=youtube&campaign=love_babbar_codestudio2&leftPanelTab=0
*/


#include<bits/stdc++.h>
using namespace std;

int count_cows(vector<int> stalls, int k, int min_dist){
        int cow = 1;    //Number of cows placed
        int dist = stalls[0];   //Position of last placed cow
        for(int i=1; i<stalls.size(); i++){
            if(stalls[i]-dist >= min_dist){
                cow++;  //Place Next cow
                dist = stalls[i];   //Updating last position 
            }
        }
        return cow;
}

int aggressiveCows_linearSearch(vector<int> &stalls, int k)
{
    int n = stalls.size();
    sort(stalls.begin(), stalls.end());
    if(n <k) return -1;
    int low = 1, high = stalls[n-1]-1;
    int ans = -1;
    for(int i = low; i<=high; i++){
        if(count_cows(stalls, k, i) == k){
            ans = max(ans, i);
        }
    }
    return ans;
}

int aggressiveCows_binarySearch(vector<int> &stalls, int k)
{
    int n = stalls.size();
    sort(stalls.begin(), stalls.end());
    if(n<k) return -1;
    int l= 1, r = stalls[n-1]-1;
    int ans = -1;
    while(l<=r){
        int mid = l + (r-l)/2;
        if(count_cows(stalls, k, mid) >= k){
            ans = mid;
            l = mid+1;
        }
        else r = mid-1;
    }
    return ans;
}

int main(){
    vector<int> stalls = {0,3,4,7,10,9};
    int k = 4;
    // cout<<aggressiveCows_linearSearch(stalls, k);
    cout<<aggressiveCows_binarySearch(stalls, k);
    return 0;
}