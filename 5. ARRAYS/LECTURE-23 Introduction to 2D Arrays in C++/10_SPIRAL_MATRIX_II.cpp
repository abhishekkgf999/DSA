#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> generateMatrix(int n)
{
    vector<vector<int>> arr(n, vector<int>(n));
    int num = 1;
    int top = 0, bottom = n - 1, left = 0, right = n - 1;
    while (top <= bottom && left <= right)
    {
        for (int i = left; i <= right; i++)
        {
            arr[top][i] = num++;
        }
        top++;
        for (int i = top; i <= bottom; i++)
        {
            arr[i][right] = num++;
        }
        right--;
        if (left <= right)
        {
            for (int i = right; i >= left; i--)
            {
                arr[bottom][i] = num++;
            }
        }
        bottom--;
        if (top <= bottom)
        {
            for (int i = bottom; i >= top; i--)
            {
                arr[i][left] = num++;
            }
        }
        left++;
    }
    return arr;
}

int main()
{
    cout<<"Enter an integer:- "<<endl;
    int n;
    cin>>n;

    vector<vector<int>> ans = generateMatrix(n);
    for(int i=0; i<n; i++){     
        for(int j=0; j<n; j++){    
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}