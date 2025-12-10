/*

#MINIMUM NUMBER OF DAYS TO MAKE M BOUQUETS

LINK:- https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/description/

*/


#include<bits/stdc++.h>
using namespace std;

int calculate_bloom(vector<int> bloomDay, int m, int k, int day){
    int bouquets = 0;
    int count = 0;
    for(int i = 0; i<bloomDay.size(); i++){
        if(bloomDay[i] <= day){
            count++;
        }
        else if(bloomDay[i] > day){
            count = 0;
        }
        if(count == k){
            bouquets++;
            count = 0;
        }
    }
    return bouquets;
}

int minDays_linearSearch(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if(n < (m*k)) return -1;
        int l = *min_element(bloomDay.begin(), bloomDay.end());
        int maxi = *max_element(bloomDay.begin(), bloomDay.end());
        for(int i = l; i<=maxi; i++){
            if(calculate_bloom(bloomDay, m, k, i) == m){
                return i;
            }
        }
        return l;
    }

int minDays_binarySearch(vector<int>& bloomDay, int m, int k){
    int n = bloomDay.size();
    int l = 1, r = *max_element(bloomDay.begin(), bloomDay.end());
    int ans = -1;
    while(l<=r){
        int mid = l + (r-l)/2;
        if(calculate_bloom(bloomDay, m, k, mid) >= m){
            ans = mid;
            r = mid-1;
        }
        else l = mid+1;
    }

    return ans;
}

int main(){
    vector<int> bloomDay = {1,10,3,10,2};
    int m = 3;
    int k = 1;
    cout<<minDays_binarySearch(bloomDay, m, k);
    return 0;
}