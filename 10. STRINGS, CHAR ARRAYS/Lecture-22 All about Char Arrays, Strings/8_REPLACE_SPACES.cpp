/*
#REPLACE SPACES (MARK FOR REVISION)

LINK:-  https://www.codingninjas.com/studio/problems/replace-spaces_1172172?leftPanelTab=1
*/

#include<bits/stdc++.h>
using namespace std;

//taking extra space(TIME COMPLEXITY:- O(N), SPACE COMPLEXITY:- O(N))
string replaceSpaces1(string &str){
	int n = str.size();
    string newStr;

    for (int i = 0; i < n; i++) {
        if (str[i] == ' ') {
            newStr += "@40"; 
        } else {
            newStr += str[i]; 
        }
    }

    return newStr;
}

//OPTIMIZED SOLUTION(taking no extra space)(TIME COMPLEXITY:- O(N), SPACE COMPLEXITY:- O(1))
string replaceSpaces2(string &str){
	int n = str.size();
	int countspace = 0;
	for(int i=0; i<n; i++){
		if(str[i]==' '){
			countspace++;
		}
	}

	int newlength = n + 2*(countspace);

	str.resize(newlength);

	int index = newlength-1;

	for(int i = n-1; i>=0; i--){
		if(str[i]==' '){
			str[index--] = '0';
			str[index--] = '4';
			str[index--] = '@';
		}
		else{
			str[index] = str[i];
			index--;
		}
	}
	return str;

}


int main(){
    string s;
    cout<<"enter your string"<<endl;
    getline(cin, s);
    cout<<replaceSpaces2(s)<<endl;
    return 0;
}