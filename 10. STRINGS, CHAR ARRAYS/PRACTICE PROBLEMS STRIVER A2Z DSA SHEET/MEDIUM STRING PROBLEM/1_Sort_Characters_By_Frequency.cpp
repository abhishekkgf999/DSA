/*

#SORT CHARACTERS BY FREQUENCY

LINK:- https://leetcode.com/problems/sort-characters-by-frequency/description/

*/


#include<bits/stdc++.h>
using namespace std;


//MY SOLUTION
string frequencySort(string s) {
        vector<int> freq(256, 0);

        for(auto ch : s){
            int ind = int(ch);  //EXPLICIT TYPECASTING
            freq[ind]++;
        }
        string ans = "";
        
        while(ans.length() != s.size()){
            int maxInd = -1;
            int maxFreq = -1;
            for(int i = 0; i<256; i++){
                if(freq[i] > maxFreq){
                    maxInd = i;
                    maxFreq = freq[i];
                }
            }

            while(maxFreq--){
                if(maxInd >= 65 && maxInd<= 90){
                    ans += (maxInd-65) + 'A';
                }
                else{
                    ans += (maxInd - 97) + 'a';
                }
            }

            freq[maxInd] = 0;
        }


        return ans;
    }

//OPTIMAL SOLUTION (TC:- O(len of string))
string frequencySort_optimalSolution(string s) {
        vector<pair<int, char>> hash('z'+1, {0,0}); //vector<data type> name (size, default initializer);

        for(char ch : s){
            hash[ch] = {hash[ch].first+1, ch};
        }

        sort(hash.begin(), hash.end());

        string res = "";
        for(auto p : hash){
            //string(frequency, character) is to create a string, with given frequency and that 
            //character is repeated with given frequency time
            res = string(p.first, p.second) + res;
        }

        return res;
    }

int main(){
    string s = "tree";
    string ans = frequencySort(s);
    cout<<ans;
    return 0;
}