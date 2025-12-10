/*
#TOWER OF HANOI

LINK:- https://www.geeksforgeeks.org/problems/tower-of-hanoi-1587115621/1

*/

#include<bits/stdc++.h>
using namespace std;

int towerOfHanoi(int n, int from, int to, int aux) {
        if(n <= 1)return n;
        
        int move1 = towerOfHanoi(n-1, from, aux, to);
     
        int move2 = towerOfHanoi(n-1, aux, to, from);
        
        return move1 + 1 + move2;
        
    }    

int main(){
    cout<<towerOfHanoi(3, 1, 2, 3);
    return 0;
}