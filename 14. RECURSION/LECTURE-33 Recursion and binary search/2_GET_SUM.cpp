#include<iostream>
using namespace std;

int getSum(int arr[], int size){ 

    //BASE CASE (IF SIZE BECOME 0 THAN WE HAVE TO SIMPLY RETURN 0 -> NO ELEMNENTS IN ARRAY)
    if(size == 0){
        return 0;
    }

    //RECURSIVE CALL + PROCESS
    /*
    
    1. WE SIMPLY STORE THE SUM IN A VARAIABLE BY ADDING ALWAYS 1ST ELEMENT IN VARIABLE
    2. WE RECURSIVELY MOVE OUR ARRAY, AND START FROM NEXT ELEMENT BY PASSING THE ARRAY FROM ITS NEXT INDEX BY INCREASING THE ARRAY (arr + 1)
       AND DECREASING THE SIZE OF ARRAY 
    
    */
    int ans = arr[0] + getSum(arr+1, size-1);


    //RETURNING THE ANS
    return ans;
}

int main(){

    int arr[5] = {6,2,5,1,6};

    int size = 5;

    cout<<getSum(arr, size);
    
    return 0;
}