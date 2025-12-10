/*
#COUNT OF SUBSTRINGS CONTAINING EVERY VOWEL AND K CONSONANTS II

LINK:- https://leetcode.com/problems/count-of-substrings-containing-every-vowel-and-k-consonants-ii/description/
*/


#include<bits/stdc++.h>
using namespace std;

/*
## Core Algorithm: Sliding Window + Precomputation

### Key Constraints
1. All 5 vowels present: mp.size() == 5
2. Exactly K consonants: cons == k

### Precomputation Logic: Next Consonant Array

vector<int> nextCons(n);  // nextCons[i] = next consonant position after i

Logic: For each position i, find where next consonant appears
- Traverse right to left to build this information
- Used to count valid substring extensions

### Phase 1: Maintain Constraint cons ≤ k

Logic: Basic constraint maintenance - can't have >k consonants

### Phase 2: Count Valid Subarrays (Perfect Window)

Logic: When window satisfies both constraints:
- Current window [i,j] is valid
- Can extend to any position before next consonant
- idx - j gives number of valid extensions

### Counting Logic: Why idx - j?
If window [i,j] is valid and next consonant is at idx:
- Valid subarrays: [i,j], [i,j+1], ..., [i,idx-1]
- Count = (idx-1) - j + 1 = idx - j

## Key Implementation Insights

Two-phase shrinking:
1. Maintain feasibility: cons ≤ k
2. Extract solutions: When mp.size() == 5 && cons == k

Why separate phases?
- Phase 1: Get to feasible region
- Phase 2: Count all solutions from current left boundary

Precomputation benefit:
- Instantly know how far we can extend current valid window
- Avoids nested loops for counting extensions


## Key Points
- Precomputation: Next consonant positions for counting extensions
- Two constraints: All vowels AND exactly k consonants  
- Efficient counting: Use precomputed data to avoid nested loops

Time: O(n) | Space: O(1) for map + O(n) for preprocessing

*/
class Solution {
public:
    bool isVowel(char& ch) {
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')return true;
        return false;
    }
    long long countOfSubstrings(string word, int k) {
        int n = word.length();
        unordered_map<char, int> mp;

        vector<int> nextCons(n);
        int lastConsIdx = n;
        for (int i = n - 1; i >= 0; i--) {
            nextCons[i] = lastConsIdx;
            if (!isVowel(word[i])) {
                lastConsIdx = i;
            }
        }

        int i = 0, j = 0;
        long long count = 0;
        int cons = 0;
        while (j < n) {
            char ch = word[j];
            if (isVowel(ch)) {
                mp[ch]++;
            }
            else {
                cons++;
            }

            while (cons > k) {
                char ch = word[i];
                if (isVowel(ch)) {
                    mp[ch]--;
                    if (mp[ch] == 0) {
                        mp.erase(ch);
                    }
                }
                else {
                    cons--;
                }
                i++;
            }

            while (mp.size() == 5 && cons == k) {
                int idx = nextCons[j];
                count += idx - j;
                char ch = word[i];
                if (isVowel(ch)) {
                    mp[ch]--;
                    if (mp[ch] == 0) {
                        mp.erase(ch);
                    }
                }
                else {
                    cons--;
                }
                i++;
            }

            j++;
        }
        return count;
    }
};

int main() {
    Solution sol;

    // Example 1
    string word1 = "aeiouu";
    int k1 = 0;
    cout << "Word: \"" << word1 << "\", k: " << k1 << endl;
    cout << "Number of substrings: " << sol.countOfSubstrings(word1, k1) << endl << endl;

    // Example 2
    string word2 = "aeiouyieaou";
    int k2 = 1;
    cout << "Word: \"" << word2 << "\", k: " << k2 << endl;
    cout << "Number of substrings: " << sol.countOfSubstrings(word2, k2) << endl << endl;

    // Example 3
    string word3 = "uzxaeioubc";
    int k3 = 2;
    cout << "Word: \"" << word3 << "\", k: " << k3 << endl;
    cout << "Number of substrings: " << sol.countOfSubstrings(word3, k3) << endl << endl;

    return 0;
}