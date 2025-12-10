/*
#SQUARE ROOT OF A NUMBER

!!Problem statement:-

==> You are given a positive integer 'n'.

    Your task is to find and return its square root. If 'n' is not a perfect square,
    then return the floor value of sqrt(n).

Ex:- Given:-  'n' = 7;
     Output:- 2

Explanation:- The square root of the number 7 lies between 2 and 3, so the floor value
              is 2.

Ex:- Given:-  'n' = 100;
     Output:- 10

Explanation:- The square root of the given number 100 is 10.

Constraints:

0 <= n <= 10 ^ 9

Time Limit: 1 sec.

Expected Time Complexity:
Try solving this in O(log(n)).
*/
int floorSqrt(int n)
{
    
    long long int ans=-1;

    long long int left = 0, right = n;
    long long int mid = left + (right-left)/2;
    while(left<=right){
        if((mid*mid)==n){return mid;}
        if((mid*mid)>n){
            right = mid-1;
        }
        else if((mid*mid)<n){
            ans = mid;
            left = mid+1;
        }
        mid = left + (right-left)/2;
    }
    return ans;
}
