//POINTERS FOR CHAR ARRAYS

#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[5] = {1,2,3,4,5};

    char ch[6] = "abcde";

    //If we print arr, then we got address
    cout<<arr<<endl;

    //ATTENTION HERE!
    //If we print ch, then we got entire character string
    cout<<ch<<endl;

    //prints entire string
    char *c = &ch[0];
    cout<<"ch pointer prints entire stirng: "<<c<<endl;

    /*
    => Printing p directly outputs the address of temp, but since p points to a character (char), cout treats it as a C-style string.

    => As a result, it starts printing characters from temp until it encounters a null character (\0).

    => If there is no null character in the subsequent memory, unexpected behavior or garbage values may be printed.
    */
    char temp = 'z';
    char *p = &temp;
    cout<<p<<endl;

    return 0;
}