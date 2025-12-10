/*

#PAINTER'S PARTITION

LINK:- https://www.naukri.com/code360/problems/painter-s-partition-problem_1089557

*/

#include<bits/stdc++.h>
using namespace std;

int count_painters(vector<int> boards, int capacity){
    int painter = 1;
    int last_painter_capacity = 0;
    for(int i = 0; i<boards.size(); i++){
        if(last_painter_capacity + boards[i] <= capacity){
            last_painter_capacity += boards[i];
        }
        else{
            painter++;
            last_painter_capacity = boards[i];
        }
    }
    return painter;
}

int findLargestMinDistance(vector<int> &boards, int k){
    int n = boards.size();
    int l = *max_element(boards.begin(), boards.end());
    int r = accumulate(boards.begin(), boards.end(), 0);
    while(l<=r){
        int mid = l + (r-l)/2;
        if(count_painters(boards, mid) <= k){
            r = mid-1;
        }
        else l = mid+1;
    }
    return l;
}

int main(){
    vector<int> boards = {2,1,5,6,2,3};
    int k = 2;
    cout<<findLargestMinDistance(boards, k);
    return 0;
}