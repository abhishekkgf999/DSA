/*
#STRING COMPRESSION (MARK FOR REVISION)

LINK:- https://leetcode.com/problems/string-compression/description/
*/

#include<bits/stdc++.h>
using namespace std;

int compress(vector<char>& chars) {
        int i=0;
        int ansIndex = 0;
        int n = chars.size();
        while(i<n){
            int j = i+1;
            while(j<n && chars[i] == chars[j]){
                j++;
            }

            chars[ansIndex++] = chars[i];

            int count = j-i;
            if(count>1){
                string num = to_string(count);
                for(char ch : num){
                    chars[ansIndex++] = ch;
                }
            }
            i = j;
        }
        return ansIndex;
    }

int main(){
    vector<char> chars;
    int n;
    cout<<"Enter the number of elements in array:- ";
    cin>>n;
    cout<<"enter the elements:- ";
    for(int i=0; i<n; i++){
        char element;
        cin>>element;
        chars.push_back(element);
    }

    cout<<"Given array length after compression is:- "<<compress(chars);
    
    return 0;
}

