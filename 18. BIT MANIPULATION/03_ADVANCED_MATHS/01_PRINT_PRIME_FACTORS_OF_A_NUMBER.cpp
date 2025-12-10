/*
#PRINT PRIME FACTORS OF A NUMBER

LINK:- https://www.geeksforgeeks.org/problems/prime-factors5052/1
*/

#include<bits/stdc++.h>
using namespace std;

class Solution1 {
public:
    vector<int> primeFac(int n) {
        // code here
        vector<int> res;

        for (int i = 2; i <= n; i++) {
            if (n % i == 0) {
                res.push_back(i);
                while (n % i == 0) n = n / i;
            }
        }

        return res;
    }
};


class Solution2 {
public:
    vector<int> primeFac(int n) {
        // code here
        vector<int> res;

        for (int i = 2; i <= sqrt(n); i++) {
            if (n % i == 0) {
                res.push_back(i);
                while (n % i == 0) n = n / i;
            }
        }

        if (n != 1)res.push_back(n);

        return res;
    }
};

// Helper function to print the vector
void printVector(vector<int>& vec) {
    for (int x : vec) {
        cout << x << " ";
    }
    cout << endl;
}

int main() {
    Solution1 sol1;
    Solution2 sol2;
    int n1 = 60;
    int n2 = 13195;
    int n3 = 97; // A prime number

    cout << "Testing with n = 60:" << endl;
    vector<int> res1_sol1 = sol1.primeFac(n1);
    cout << "Solution 1 Output: ";
    printVector(res1_sol1);
    vector<int> res1_sol2 = sol2.primeFac(n1);
    cout << "Solution 2 Output: ";
    printVector(res1_sol2);
    cout << "---" << endl;

    cout << "Testing with n = 13195:" << endl;
    vector<int> res2_sol1 = sol1.primeFac(n2);
    cout << "Solution 1 Output: ";
    printVector(res2_sol1);
    vector<int> res2_sol2 = sol2.primeFac(n2);
    cout << "Solution 2 Output: ";
    printVector(res2_sol2);
    cout << "---" << endl;

    cout << "Testing with n = 97 (a prime number):" << endl;
    vector<int> res3_sol1 = sol1.primeFac(n3);
    cout << "Solution 1 Output: ";
    printVector(res3_sol1);
    vector<int> res3_sol2 = sol2.primeFac(n3);
    cout << "Solution 2 Output: ";
    printVector(res3_sol2);
    cout << "---" << endl;

    return 0;
}