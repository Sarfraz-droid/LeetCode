---
layout: post
title: Matrix Chain Multiplication - GFG
date: 2022-06-25T14:20:30.416Z
---

```
# Matrix Chain Multiplication
## Hard 

                Given a sequence of matrices, find the most efficient way to multiply these matrices together.&nbsp;The efficient way is the one that involves&nbsp;the least number of&nbsp;multiplications. 

The dimensions of the matrices are given in an array arr[]&nbsp;of&nbsp;size&nbsp;N (such that N = number of matrices + 1) where the ith matrix has the dimensions&nbsp;(arr[i-1]&nbsp;x arr[i]).

Example 1:

Input: N = 5
arr =  { 40, 20, 30, 10, 30 } 
Output: 26000
Explaination: There are 4 matrices of dimension 
40x20, 20x30, 30x10, 10x30. Say the matrices are 
named as A, B, C, D. Out of all possible combinations,
the most efficient way is (A*(B*C))*D. 
The number of operations are -
20*30*10 + 40*20*10 + 40*10*30 = 26000.


Example 2:

Input: N = 4
arr =  { 10, 30, 5, 60 } 
Output: 4500
Explaination: The matrices have dimensions 
10*30, 30*5, 5*60. Say the matrices are A, B 
and C. Out of all possible combinations,the
most efficient way is (A*B)*C. The 
number of multiplications are -
10*30*5 + 10*5*60 = 4500.


Your Task:
You do not need to take input or print anything. Your task is to complete the function matrixMultiplication() which takes the value N and the array arr[] as input parameters and returns the minimum number of multiplication operations needed to be performed.


Expected Time Complexity: O(N3)
Expected Auxiliary Space: O(N2)


Constraints:&nbsp;
2 ≤ N ≤ 100
1 ≤ arr[i] ≤ 500
 
             
```

##Code
 ```
  // { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public: 
public:
    int  dp[1001][1001];
    int solve(int a[], int i, int j)
    {
        if (i==j) return 0;
        if (dp[i][j]!=-1) return dp[i][j];
        dp[i][j] = INT_MAX;
        for (int k = i; k < j; k++)
        {
            dp[i][j] = min(dp[i][j] , solve(a,i,k)  +
                                      solve(a,k+1,j)  +
                                      a[i-1]*a[k]*a[j]);
        }
        return dp[i][j];
    }
    int matrixMultiplication(int n, int a[])
    {
         memset(dp, -1, sizeof dp);
        return solve(a,1,n-1);
    }
};
  
  
  
// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}  // } Driver Code Ends 
```