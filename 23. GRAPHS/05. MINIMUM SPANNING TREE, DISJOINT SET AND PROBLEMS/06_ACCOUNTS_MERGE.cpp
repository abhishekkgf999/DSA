/*
====================================================
ACCOUNTS MERGE
LeetCode:
https://leetcode.com/problems/accounts-merge/
====================================================

💡 PROBLEM SUMMARY
----------------------------------------------------
- Given:
    • Multiple accounts

Each account contains:
    [Name, Email1, Email2, ...]

----------------------------------------------------
Important:

✔ Names may be same
✔ Emails uniquely identify a person

Goal:
✔ Merge all accounts belonging
  to the same person

✔ Return emails in sorted order

====================================================
CORE OBSERVATION ⭐
----------------------------------------------------
Name is NOT reliable.

Example:
----------------------------------------------------
John
John

may represent:
✔ same person
✔ different persons

----------------------------------------------------
But email is unique.

If two accounts contain:
    same email

Then:
✔ both accounts belong to
  the same person

====================================================
MAIN INTUITION
----------------------------------------------------
Think of each account index
as a node.

Example:

0 -> John
1 -> Mary
2 -> John

----------------------------------------------------
If:

Account 0 and Account 2
share an email

Then:
✔ connect them

This becomes:
✔ Connected Components problem

====================================================
WHY DSU ?
----------------------------------------------------
We need to:

✔ Merge accounts
✔ Detect accounts belonging
  to same person

DSU efficiently provides:

✔ findUPar()
✔ unionBySize()

====================================================
STEP 1: MAP EMAIL → ACCOUNT ⭐
----------------------------------------------------
We need relation:

    Email → Account Index

Example:

abc@gmail.com → 0

----------------------------------------------------
While traversing accounts:

CASE 1:
----------------------------------------------------
Email not seen before

✔ Store:
      mail → current index

----------------------------------------------------

CASE 2:
----------------------------------------------------
Email already exists

Meaning:
✔ same email found again

Therefore:
✔ same person

So:
✔ union current account
  with previous account

====================================================
AFTER UNION OPERATIONS
----------------------------------------------------
Accounts sharing emails become:

✔ one connected component

Each component:
✔ one person

====================================================
STEP 2: COLLECT EMAILS OF SAME PERSON
----------------------------------------------------
Now map contains:

    mail → account index

----------------------------------------------------
For every email:

✔ Find ultimate parent
  of associated account

✔ Store email under
  that parent

Example:

Parent 0:
    abc@gmail.com
    xyz@gmail.com

Parent 3:
    pqr@gmail.com

====================================================
WHY FIND ULTIMATE PARENT AGAIN ?
----------------------------------------------------
Because:

Stored account index may not be
the final representative.

----------------------------------------------------
After DSU merges:

✔ ultimate parent identifies
  actual merged component

====================================================
STEP 3: BUILD FINAL ANSWER
----------------------------------------------------
For every component:

✔ Sort emails

✔ Insert:
      Name first

✔ Then append all emails

----------------------------------------------------
Skip empty components because:

✔ They were merged into
  some other parent

====================================================
APPROACH
----------------------------------------------------

STEP 1:
✔ Create DSU

----------------------------------------------------

STEP 2:
✔ Map email → account index

----------------------------------------------------

STEP 3:
✔ If email repeats:
      union accounts

----------------------------------------------------

STEP 4:
✔ Group emails according to
      ultimate parent

----------------------------------------------------

STEP 5:
✔ Sort emails

----------------------------------------------------

STEP 6:
✔ Build final merged accounts

====================================================
IMPORTANT CONDITIONS
----------------------------------------------------
✔ Same email = same person
✔ Same name ≠ same person
✔ Emails must be sorted
✔ DSU merges repeated-email accounts
✔ Skip empty merged groups

====================================================
TIME & SPACE COMPLEXITY
----------------------------------------------------
Let:

N = accounts
M = total emails

----------------------------------------------------
TIME:
➡ O(M log M)

(primarily due to sorting emails)

----------------------------------------------------
SPACE:
➡ O(M)

====================================================
KEY TAKEAWAY
----------------------------------------------------
Whenever problem involves:

✔ merging entities
✔ shared identifiers
✔ grouping related records

Think:

✔ Connected Components
✔ Disjoint Set Union (DSU)

Core Observation:

✔ Email uniquely identifies person

Therefore:

✔ Same email ⇒ Same component

====================================================
*/

#include<bits/stdc++.h>
using namespace std;

class DisJointSet{

    vector<int> parent, size;

public:

    DisJointSet(int n){

        parent.resize(n, 0);
        size.resize(n, 1);

        for(int i = 0; i < n; i++){
            parent[i] = i;
        }
    }

    int findUPar(int node){

        if(parent[node] == node){
            return node;
        }

        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int u, int v){

        int ult_u = findUPar(u);
        int ult_v = findUPar(v);

        if(ult_u == ult_v){
            return;
        }

        if(size[ult_u] < size[ult_v]){

            parent[ult_u] = ult_v;
            size[ult_v] += size[ult_u];

        }
        else{

            parent[ult_v] = ult_u;
            size[ult_u] += size[ult_v];
        }
    }
};

class Solution {
public:

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {

        int n = accounts.size();

        DisJointSet ds(n);

        unordered_map<string, int> mpp;

        for(int i = 0; i < n; i++){

            for(int j = 1; j < accounts[i].size(); j++){

                string mail = accounts[i][j];

                if(mpp.find(mail) == mpp.end()){

                    mpp[mail] = i;

                }
                else{

                    ds.unionBySize(i, mpp[mail]);
                }
            }
        }

        vector<string> mergedMail[n];

        for(auto it : mpp){

            string mail = it.first;

            int node = ds.findUPar(it.second);

            mergedMail[node].push_back(mail);
        }

        vector<vector<string>> ans;

        for(int i = 0; i < n; i++){

            if(mergedMail[i].size() == 0){
                continue;
            }

            sort(mergedMail[i].begin(), mergedMail[i].end());

            vector<string> temp;

            temp.push_back(accounts[i][0]);

            for(auto it : mergedMail[i]){
                temp.push_back(it);
            }

            ans.push_back(temp);
        }

        return ans;
    }
};

int main(){
    
    return 0;
}