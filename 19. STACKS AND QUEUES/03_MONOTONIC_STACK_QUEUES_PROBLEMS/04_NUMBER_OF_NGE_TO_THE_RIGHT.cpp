/*
#NUMBER OF NGE'S TO THE RIGHT

LINK:- https://www.geeksforgeeks.org/problems/number-of-nges-to-the-right/1
*/

#include<bits/stdc++.h>
using namespace std;

/*
Implementation
1. Initialize an empty list named ans to store the results.
2. Iterate through each index i in the range from 0 to q-1.
3. Inside the loop, retrieve the current element curr from the arr list using the index indices[i].
4. Initialize an empty stack named st to store elements greater than curr.
5. Initialize a variable r with the value n - 1, representing the last index of the arr list.
6. Enter a while loop, which runs until r is greater than the current index indices[i].
7. Inside the loop, check if the element at index r in the arr list is greater than curr.
8. If the condition is true, append the element at index r to the stack st.
9. Decrement the value of r by 1 in each iteration.
10. After exiting the while loop, append the length of the stack st to the ans list.
11. Once all iterations are completed, return the ans list containing the count of next greater elements for each index specified in the indices list.
*/

class Solution {
public:

    vector<int> count_NGE(int n, vector<int>& arr, int q, vector<int>& indices) {
        //write your code here
        vector<int> ans(q);
        for (int i = 0; i < q; i++) {
            int curr = arr[indices[i]];
            stack<int> st;
            int r = n - 1;
            while (r > indices[i]) {
                if (arr[r] > curr) {
                    st.push(arr[r]);
                }
                r--;
            }
            ans[i] = st.size();
        }
        return ans;

    }

};

int main() {
    Solution sol;

    // Example 1
    int n1 = 7;
    vector<int> arr1 = { 3, 4, 2, 7, 5, 8, 10 };
    int q1 = 3;
    vector<int> indices1 = { 0, 3, 5 };
    vector<int> result1 = sol.count_NGE(n1, arr1, q1, indices1);

    cout << "Array: {3, 4, 2, 7, 5, 8, 10}" << endl;
    cout << "Queries: {0, 3, 5}" << endl;
    cout << "Output: {";
    for (size_t i = 0; i < result1.size(); ++i) {
        cout << result1[i] << (i == result1.size() - 1 ? "" : ", ");
    }
    cout << "}" << endl << endl; // Expected: {5, 2, 1}

    // Example 2
    int n2 = 4;
    vector<int> arr2 = { 1, 2, 3, 4 };
    int q2 = 2;
    vector<int> indices2 = { 0, 1 };
    vector<int> result2 = sol.count_NGE(n2, arr2, q2, indices2);

    cout << "Array: {1, 2, 3, 4}" << endl;
    cout << "Queries: {0, 1}" << endl;
    cout << "Output: {";
    for (size_t i = 0; i < result2.size(); ++i) {
        cout << result2[i] << (i == result2.size() - 1 ? "" : ", ");
    }
    cout << "}" << endl; // Expected: {3, 2}

    return 0;
}
