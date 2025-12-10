/*

#KOKO EATING BANANAS (USING BINARY SEARCH)

LINK:- https://leetcode.com/problems/koko-eating-bananas/description/
*/


#include<bits/stdc++.h>
using namespace std;

//MY SOLUTION TO CALCULATE NUMBER OF HOURS, GIVING TLE
int calcHour(vector<int> piles, int h, int speed){
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
    return hour;
}

int minEatingSpeed(vector<int>& piles, int h) {
    int n = piles.size();
    int l = 1, r = *max_element(piles.begin(), piles.end());
    int ans = -1;
    while(l<=r){
        int mid = l + (r-l)/2;
        int hour = calcHour(piles, h, mid) ;
        if(hour == h) return mid;
        else if(hour > h) l = mid+1;
        else{
            ans = mid;
            r = mid-1;
        }
    }
    return ans;
}


//STRIVERS SOLUTION (TC:- O(nlogn))
/*
Explanation of Changes:

1. Updated calcHour:
=>  We now calculate the hours required using "(pile + speed - 1)/speed" for each pile.
=>  This approach avoids modifying the piles vector and is more efficient.
=>  If at any point the number of hours exceeds h, we exit early, making the function faster.

2. Adjusted Binary Search Logic:
=>  If calcHour returns true (i.e., the bananas can be eaten in h or fewer hours), we update ans and try to find a 
    smaller speed by moving the right boundary (r).
=>  If calcHour returns false, we move the left boundary (l) to increase the speed.

3. Binary Search Stopping Condition:
=>  The loop runs while l <= r. After the loop ends, ans contains the minimum speed at which all bananas can be eaten 
    in at most h hours.

*/

/*

#Expression Breakdown: (pile + speed - 1) / speed
=>  This formula works because it ensures that any remainder after dividing pile by speed causes the integer division to 
    round up. Here’s how it works:

1. Integer Division (pile / speed):

=>  This gives the largest integer less than or equal to the actual division result. However, this will only be correct when 
    pile is exactly divisible by speed. Otherwise, it will miss the extra partial hour needed to finish the remainder.

2.  Adding "speed - 1":

=>  We add speed - 1 to the numerator before performing integer division. This ensures that any remainder after dividing pile 
    by speed causes the integer division to round up instead of down.

=>  The idea is to "push" any partial division result past a full multiple of speed into the next integer hour.
*/

/*
IMPLEMENTATION OF BELOW CEIL FUNCTION

int customCeil(double num) {
    int intPart = static_cast<int>(num); // Get the integer part of the number
    return (num > intPart) ? (intPart + 1) : intPart; // Add 1 if there's a decimal part
}
*/
bool calcHour2(vector<int> piles, int h, int speed){
    int hour = 0;
    for(auto pile: piles){
        // hour = hour + (pile + speed -1)/speed;
        hour += ceil((double)(pile) / (double)(speed)); // THIS AND ABOVE STATEMENT BOTH ARE EQUIVALENT
        if(hour > h) return false;
    }
    return hour<=h;
}

int minEatingSpeed2(vector<int> &piles, int h){
    int n = piles.size();
    int l = 1, r = *max_element(piles.begin(), piles.end());
    int ans = -1;
    while(l<=r){
        int mid = l + (r-l)/2;
        if(calcHour2(piles, h, mid)){
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
    vector<int> piles = {3,6,7,11};  
    int h = 8;
    cout<<minEatingSpeed2(piles, h); 
    return 0;
}