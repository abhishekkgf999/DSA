/*
#ZIGZAG CONVERSION

LINK:- https://leetcode.com/problems/zigzag-conversion/description/
*/

#include<bits/stdc++.h>
using namespace std;

/*
====================================================
APPROACH 1: DUMMY MATRIX SIMULATION
----------------------------------------------------
IDEA:
- Zigzag ko literally ek 2D matrix me draw kar do
- Phir row-wise read kar lo

----------------------------------------------------
STEPS:
1️⃣ numRows × s.length() ka dummy matrix banao
2️⃣ Vertical direction me characters fill karo
3️⃣ Diagonal direction me upar ki taraf fill karo
4️⃣ Matrix ko row-wise traverse karke answer banao

----------------------------------------------------
PROS:
✔ Easy to understand
✔ Zigzag clearly visualize hota hai

CONS:
❌ Extra space waste hoti hai
❌ Time & space inefficient

----------------------------------------------------
TIME COMPLEXITY:
➡ O(n²)

SPACE COMPLEXITY:
➡ O(n²)

----------------------------------------------------
*/
class Solution1 {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;

        vector<vector<char>> temp(numRows, vector<char>(s.size(), '/'));

        int row = 0, col = 0, i = 0;

        while (i < s.size()) {
            for (row = 0; row < numRows && i < s.size(); row++) {
                temp[row][col] = s[i++];
            }

            col++;                 
            row = numRows - 2;     
            while (row > 0 && i < s.size()) {
                temp[row][col] = s[i++];
                row--;
                col++;
            }
        }

        string ans = "";
        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j < s.size(); j++) {
                if (temp[i][j] != '/') {
                    ans.push_back(temp[i][j]);
                }
            }
        }

        return ans;
    }
};

/*
====================================================
APPROACH 2: PATTERN SIMULATION (OPTIMAL) ⭐
----------------------------------------------------
KEY OBSERVATION:
- Zigzag pattern repeat hota hai
- Ek cycle ki length = (numRows - 1) * 2

----------------------------------------------------
IDEA:
- Hame matrix ki zarurat nahi hai
- Sirf correct indices se characters uthao

----------------------------------------------------
PATTERN DETAILS:
1️⃣ First row & last row:
   - Direct jump by `cycleLength`

2️⃣ Middle rows:
   - Do characters milte hain per cycle:
       ➜ vertical element
       ➜ diagonal element

   Diagonal index:
   ➜ i + cycleLength - 2*row

----------------------------------------------------
STEPS:
1️⃣ Har row ke liye loop chalao
2️⃣ Har cycle me:
   - Current row ka character add karo
   - Agar middle row hai:
        diagonal character bhi add karo

----------------------------------------------------
WHY THIS WORKS?
✔ Zigzag pattern mathematical hai
✔ Index jumping se direct answer mil jata hai
✔ No extra matrix needed

====================================================
TIME & SPACE ANALYSIS
----------------------------------------------------
TIME COMPLEXITY:
➡ O(n)

SPACE COMPLEXITY:
➡ O(1) (output string excluded)

====================================================
IMPORTANT EDGE CASE:
----------------------------------------------------
- Agar numRows == 1:
  ➜ Zigzag possible nahi
  ➜ Return original string

====================================================
*/
class Solution2 {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;
        string ans = "";

        for(int row = 0; row<numRows; row++){
            int increment = (numRows-1)*2;
            for(int i = row; i<s.size(); i+= increment){
                ans += s[i];
                if((row > 0) && (row < numRows-1) && ((i+increment - 2*row) < s.size())){
                    ans += s[i + increment - 2*row];
                }
            }
        }

        return ans;
    }
};

int main(){
    string s = "PAYPALISHIRING";
    Solution2 obj;
    cout<<obj.convert(s, 4);
    return 0;
}