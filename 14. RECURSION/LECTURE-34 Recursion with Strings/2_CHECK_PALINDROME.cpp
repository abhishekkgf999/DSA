#include<iostream>
#include<string>
using namespace std;

bool check_Palindrome(string str, int start, int end){

    if(start > end){
        return true;
    }

    if(str[start] != str[end]){
        return false;
    }

    return  check_Palindrome(str, start+1, end-1);

}

int main(){
    string str = "abccdba";
    bool ans = check_Palindrome(str, 0, str.length()-1);

    if(ans){
        cout<<"String is palindrome";
    }
    else{
        cout<<"String is not palindrome";
    }
    return 0;
}