#include<iostream>
using namespace std;

bool check_sorted(int arr[], int size){

    //BASE CASE (IF ARRAY CONTAINS 0 OR 1 ELEMENTS, THEN ALREADY SORTED)
    if(size <=1){
        return true;
    }

    //PROCESS(COMPARE STARTING 2 ELEMENTS)
    if(arr[0] > arr[1]){
        return false;
    }
    else{

        //RECURSIVE CALL
        /*
        1. WE HAVE TO RECURSIVE CALL ARRAY, FROM NEXT ELEMENT
        2. ALSO WE HAVE TO REDUCE ITS SIZE

        FOR EXAMPLE:- ARR = [2, 4, 6, 8, 9] , SIZE = 5
                     
                     => CHECK 2<4 (TRUE)

                     => RECURSIVE CALL 
                        -> NOW OUR NEW COMPARISON ARRAY WILL BE
                            ARR = {4, 6, 8, 9}, SIZE = 4

        WE CAN SEND THIS NEW ARRAY FROM ITS NEXT ELEMENT BY INCREMENTING THE ADDRESS OF ARRAY BY ONE POSITION
        #arr+1 -> this will give the address of 2nd element
        */
        bool ans = check_sorted(arr+1, size-1);

        //RETURNING THE ANS
        return ans;
    }
}

int main(){

    int arr[] = {2,4,6,8,9};

    int size = 5;

    bool ans = check_sorted(arr, size);

    if(ans){
        cout<<"Array is sorted"<<endl;
    }
    else{
        cout<<"Array is not sorted"<<endl;
    }
    
    return 0;
}