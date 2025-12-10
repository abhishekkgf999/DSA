/*
#ONLINE STOCK SPAN

LINK:- https://leetcode.com/problems/online-stock-span/
*/

#include<bits/stdc++.h>
using namespace std;

//MY SOLUTION
class StockSpanner {
public:
    int ind;
    stack<int> st;
    vector<int> temp;
    StockSpanner() {
        ind = 0;
    }

    int next(int price) {
        // Push the current price first
        temp.push_back(price);

        // Pop while the current price is greater or equal
        while (!st.empty() && price >= temp[st.top()]) {
            st.pop();
        }

        int ans = (st.empty()) ? ind + 1 : ind - st.top();
        st.push(ind);
        ind++;
        return ans;
    }
};


//OPTIMAL SOLUTION
class StockSpanner {
public:
    int index;
    stack<pair<int,int>> st;
    StockSpanner() {
        index =-1; 
        // st.clear();
    }
    
    int next(int price) {
        index+=1;
        int ans;
        while(!st.empty() && st.top().first<= price )
        {
            st.pop();
        }
        ans = index - (st.empty()? -1: st.top().second);
        st.push({price,index});
        return ans;
    }
};

int main() {

    return 0;
}