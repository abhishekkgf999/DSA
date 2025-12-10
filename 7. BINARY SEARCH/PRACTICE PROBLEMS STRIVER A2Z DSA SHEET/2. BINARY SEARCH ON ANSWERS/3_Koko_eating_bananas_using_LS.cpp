/*

#KOKO EATING BANANAS (USING LINEAR SEARCH)

LINK:- https://leetcode.com/problems/koko-eating-bananas/description/
*/


#include<bits/stdc++.h>
using namespace std;

bool calcHour(vector<int> piles, int h, int speed){
    vector<int> piles_copy = piles;
    int hour = 0;
    int i =0;
    while(i<piles_copy.size()){
        if(piles_copy[i] <= speed){
            hour++;
            piles_copy[i] = 0;
            i++;
        }
        else{
            piles_copy[i] -= speed;
            hour++;
        }
    }
    if(hour == h) return true;
    return false;
}

int minEatingSpeed(vector<int>& piles, int h) {
    int low = 1;
    int high = *max_element(piles.begin(), piles.end());
    for(int i = low; i<=high; i++){
        if(calcHour(piles, h, i)) return i;
    }    
    return high;
}

int main(){
    vector<int> piles = {3,6,7,11};  
    int h = 8;
    cout<<minEatingSpeed(piles, h); 
    return 0;
}