---
layout: post
title: Floyd Warshall - GFG
date: 2022-06-25T14:20:30.414Z
---

```
# Floyd Warshall
## Medium 

                The problem is to find shortest distances between every pair of vertices in a given edge weighted directed Graph. The Graph is represented as adjancency matrix, and the matrix denotes the weight of the edegs (if it exists) else -1. Do it in-place.
&nbsp;

Example 1:

Input: matrix =  {  { 0,25 } , { -1,0 }  } 
Output:  {  { 0,25 } , { -1,0 }  } 
Explanation: The shortest distance between
every pair is already given(if it exists).


Example 2:

Input: matrix =  {  { 0,1,43 } , { 1,0,6 } , { -1,-1,0 }  } 
Output:  {  { 0,1,7 } , { 1,0,6 } , { -1,-1,0 }  } 
Explanation: We can reach 3 from 1 as 1-&gt;2-&gt;3
and the cost will be 1+6=7 which is less than 
43.


&nbsp;

Your Task:
You don't need to read, return or print anything. Your task is to complete the function&nbsp;shortest_distance()&nbsp;which takes the matrix as input parameter and modify the distances for every pair in-place.
&nbsp;

Expected Time Complexity:&nbsp;O(n3)
Expected Space Compelxity:&nbsp;O(1)
&nbsp;

Constraints:
1 &lt;= n &lt;= 100
 
             
```

##Code
 ```
  // { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution {
  public:
	void shortest_distance(vector<vector<int>>&matrix){
	    // Code here
	    int n = matrix.size();
	    for(int k = 0;k<n;k++){
	        for(int i = 0;i<n;i++){
	            for(int j = 0;j<n;j++){
	                if(matrix[i][k] == -1 or matrix[k][j] == -1)
	                    continue;
	                
	                if(matrix[i][j] == -1)
	                    matrix[i][j] = matrix[i][k] + matrix[k][j];
	                else if(matrix[i][k] + matrix[k][j] < matrix[i][j]){
	                    matrix[i][j] = matrix[i][k] + matrix[k][j];
	                }
	            }
	        }
	    }
	    
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>matrix(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> matrix[i][j];
			}
		}
		Solution obj;
		obj.shortest_distance(matrix);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cout << matrix[i][j] << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}  // } Driver Code Ends 
```