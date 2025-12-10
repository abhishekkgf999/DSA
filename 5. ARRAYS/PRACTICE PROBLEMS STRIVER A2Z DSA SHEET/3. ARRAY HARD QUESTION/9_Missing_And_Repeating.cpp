/*

#MISSING AND REPEATING NUMBER

LINK:- https://www.geeksforgeeks.org/problems/find-missing-and-repeating2512/1

Input: n = 2 arr[] = [2, 2]
Output: 2 1
Explanation: Repeating number is 2 and smallest positive missing number is 1.

Input: n = 3 arr[] = [1, 3, 3] 
Output: 3 2
Explanation: Repeating number is 3 and smallest positive missing number is 2.
*/


#include<bits/stdc++.h>
using namespace std;

//BRUTE FORCE SOLUTION (TC:- O(N^2) & SC:- O(1))
vector<int> findTwoElement(vector<int> arr){
    int missing = -1, repeating = -1;

    for(int i = 1; i<=arr.size(); i++){
        int cnt = 0;
        for(int j = 0; j<arr.size(); j++){
            if(i == arr[j])cnt++;
        }
        if(cnt == 2) repeating = i;
        if(cnt == 0) missing = i;

        if (repeating != -1 && missing != -1)
            break;
    }

    return {repeating, missing};
}

//BETTER SOLUTION (TC:- O(2N) & SC:- O(N))
vector<int> findTwoElement1(vector<int> arr) {

        unordered_map<int, int> mpp;

        for(auto i : arr){
            mpp[i]++;
        }

        int missing = -1, repeating = -1;
        for(int i = 1; i<=arr.size(); i++){
            if(mpp[i] == 2) repeating = i;
            else if (mpp[i] == 0) missing = i;

            if (repeating != -1 && missing != -1)
            break;
        }

        return {repeating, missing};;
    }

//TC :- O(N) & SC:- O(1)
vector<int> findTwoElement2(vector<int> arr){
    int repeating = -1;
    int missing = -1; 

    for(int i = 0; i< arr.size(); i++){
        int ind = abs(arr[i])-1;
        if(arr[ind] < 0 ){
            repeating = ind + 1;
        }
        else{
            arr[ind] *= -1;
        }
    }

    for(int i  = 0; i<arr.size(); i++){
        if(arr[i] > 0){
            missing = i + 1;
        }
    }

    return {repeating, missing};
}

//OPTIMAL SOLUTION 1 (USING MATHS)  (TC:- O(N) && SC:- O(1))
/*
#Approach:

Assume the repeating number to be X and the missing number to be Y.

The steps are as follows:

1. First, find out the values of S and Sn and then calculate S - Sn (Using the above formulas).

2. Then, find out the values of S2 and S2n and then calculate S2 - S2n.

3. After performing steps 1 and 2, we will be having the values of X + Y and X - Y. Now, by substitution of values, 
   we can easily find the values of X and Y.
*/
vector<int> findTwoElement3(vector<int> arr){
    long long n = arr.size();
    long long Sn = (n*(n+1))/2;  //Sum of n natural numbers
    long long SSn = (n*(n+1)*(2*n+1))/6;    //Sum of square of n natural numbers

    long long S = 0;

    long long SS = 0;

    for(int i=0; i<n; i++){
        S += arr[i];    //Sum of numbers

        SS += (long long)arr[i]* (long long)arr[i];     //Sum of squares of numbers 
    }

    //S-Sn = X-Y:
    long long diff = S - Sn;

    // S2-S2n = X^2-Y^2:
    long long Sqdiff = SS - SSn;

    //Find X+Y = (X^2-Y^2)/(X-Y):
    long long sum = Sqdiff/diff;

    //Find X and Y: X = ((X+Y)+(X-Y))/2 and Y = X-(X-Y),
    // Here, X-Y = val1 and X+Y = val2:
    long long repeating = (diff + sum)/2;
    long long missing = sum - repeating;


    return {(int)repeating, (int)missing};

}

//OPTIMAL SOLUTION 2 (USING XOR)
vector<int> findTwoElement4(vector<int> arr){
    long long n = arr.size();

    int XOR = 0;

    for(int i = 0; i<n; i++){
        XOR = XOR ^ arr[i];

        XOR = XOR ^ i+1;
    }

    int bitNo =  0;
    while(1){
        if((XOR & (1<<bitNo)) !=0){
            break;
        }
        bitNo++;
    }

    int one = 0;
    int zero = 0;

    for(int i = 0; i<n; i++){
        //part of 1 club
        if((arr[i] & (1<<bitNo)) != 0){
            one = one ^ arr[i];
        }
        //part of 0 club
        else{
            zero = zero ^ arr[i];
        }
    }

    for(int i = 1; i<=n; i++){
        //part of 1 club
        if((i & (1<<bitNo)) != 0){
            one = one ^ i;
        }
        //part of 0 club
        else{
            zero = zero ^ i;
        }
    }

    int cnt = 0;
    for(int i = 0; i<n; i++){
        if(arr[i] == zero) cnt++;
    }

    if(cnt == 2) return {zero, one};

    return {one, zero};
}




int main(){
    vector<int> arr = {1,3,3};

    vector<int> ans = findTwoElement4(arr);

    for(auto i : ans){
        cout<<i<<" ";
    }

    return 0;
}