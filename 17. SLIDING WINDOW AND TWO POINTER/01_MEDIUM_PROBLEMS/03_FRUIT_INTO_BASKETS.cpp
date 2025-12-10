/*
#FRUITS INTO BASKETS

LINK:- https://leetcode.com/problems/fruit-into-baskets/description/
*/

#include<bits/stdc++.h>
using namespace std;


/*
Logic: When constraint violated (>2 types), shrink from left until valid again

Remove fruits from left until one fruit type is completely eliminated
Continue until exactly 2 types remain
*/
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> mpp;
        int i = 0, j = 0;
        int max_fruits = 0;
        while (j < fruits.size()) {
            mpp[fruits[j]]++;
            while (mpp.size() > 2) {
                mpp[fruits[i]]--;
                if (mpp[fruits[i]] == 0) {
                    mpp.erase(fruits[i]);
                }
                i++;
            }

            max_fruits = max(max_fruits, j - i + 1);
            j++;
        }

        return max_fruits;
    }
};

int main() {
    Solution sol;

    // Test Case 1: Standard case
    vector<int> fruits1 = { 1, 2, 1 };
    cout << "Input: ";
    for (int fruit : fruits1) cout << fruit << " ";
    cout << endl;
    cout << "Maximum fruits: " << sol.totalFruit(fruits1) << endl;
    cout << "---------------------------------------" << endl;

    // Test Case 2: Example with three unique fruits
    vector<int> fruits2 = { 0, 1, 2, 2 };
    cout << "Input: ";
    for (int fruit : fruits2) cout << fruit << " ";
    cout << endl;
    cout << "Maximum fruits: " << sol.totalFruit(fruits2) << endl;
    cout << "---------------------------------------" << endl;

    // Test Case 3: Another example
    vector<int> fruits3 = { 1, 2, 3, 2, 2, 1 };
    cout << "Input: ";
    for (int fruit : fruits3) cout << fruit << " ";
    cout << endl;
    cout << "Maximum fruits: " << sol.totalFruit(fruits3) << endl;
    cout << "---------------------------------------" << endl;

    // Test Case 4: Empty list
    vector<int> fruits4 = {};
    cout << "Input: Empty list" << endl;
    cout << "Maximum fruits: " << sol.totalFruit(fruits4) << endl;
    cout << "---------------------------------------" << endl;

    // Test Case 5: Single type of fruit
    vector<int> fruits5 = { 4, 4, 4, 4 };
    cout << "Input: ";
    for (int fruit : fruits5) cout << fruit << " ";
    cout << endl;
    cout << "Maximum fruits: " << sol.totalFruit(fruits5) << endl;

    return 0;
}