#include<bits/stdc++.h>
using namespace std;


struct compare {
    bool operator()(pair<int, int> a, pair<int, int> b) {
        return a.second > b.second;
    }
};

int main() {

    priority_queue<int> pq; //MAX HEAP BY DEFAULT
    //equivalent to:- 
    //priority_queue<Type, vector<Type>, less<Type>> pq; // Max heap (default)

    /*

    | Operation  | Function     | Description                           |
    | ---------- | ------------ | ------------------------------------- |
    | Insert     | `pq.push(x)` | Adds element `x`                      |
    | Remove top | `pq.pop()`   | Removes largest (or smallest) element |
    | Access top | `pq.top()`   | Returns top element                   |
    | Size       | `pq.size()`  | Number of elements                    |
    | Empty      | `pq.empty()` | Checks if empty                       |

    */

    pq.push(10);
    pq.push(40);
    pq.push(20);

    cout << "Top:- " << pq.top() << endl;
    while (!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }cout << endl;


    //IMPLEMENTING MIN HEAP
    priority_queue<int, vector<int>, greater<int>> pq2;
    pq2.push(10);
    pq2.push(40);
    pq2.push(20);

    cout << "Top: " << pq2.top() << endl; // 10

    while (!pq2.empty()) {
        cout << pq2.top() << " ";
        pq2.pop();
    }


    //CUSTOM COMPARATOR
    //EXAMPLE :- MIN HEAP BASED ON SECOND ELEMENT OF PAIR
    //WE CAN ALSO USE THIS AS A COMPARATOR WHILE DECLARING
    auto cmp = [](pair<int, int> a, pair<int, int> b) {
        return a.second > b.second;  // smaller second -> higher priority
        };

    // priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(cmp)> pq(cmp);

    priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq3;

    pq3.push({ 1, 30 });
    pq3.push({ 2, 10 });
    pq3.push({ 3, 20 });


    while (!pq3.empty()) {
        cout << pq3.top().first << " " << pq3.top().second << endl;
        pq3.pop();
    }


    return 0;
}