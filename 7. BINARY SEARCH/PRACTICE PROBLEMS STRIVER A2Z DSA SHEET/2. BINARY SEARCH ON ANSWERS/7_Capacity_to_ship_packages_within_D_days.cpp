/*

#CAPACITY TO SHIP PACKAGES WITHIN D DAYS

LINK:- https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/

*/

#include<bits/stdc++.h>
using namespace std;

int countDays(vector<int> &weights, int min_weight){
    int day = 1;
    int weight_sum = 0;
    for(auto i : weights){
        weight_sum += i;
        if(weight_sum > min_weight){
            day++;
            weight_sum = i;
        }
    }
    return day;
}

int shipWithinDays_linearSearch(vector<int>& weights, int days) {
        int n = weights.size();
        int l = *max_element(weights.begin(), weights.end());
        int r = accumulate(weights.begin(), weights.end(),0);
        
        for(int i = l; i<=r; i++){
            if(countDays(weights, i) == days) return i;
        }
        return -1;
    }

int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int l = *max_element(weights.begin(), weights.end());
        int r = accumulate(weights.begin(), weights.end(),0); 
        int ans = -1;
        while(l<=r){
            int mid = l + (r-l)/2;
            if(countDays(weights, mid) <= days){
                ans = mid;
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        return ans;
    }
int main(){
    vector<int> weights = {1,2,3,4,5,6,7,8,9,10};
    cout<<shipWithinDays(weights, 5);
    return 0;
}