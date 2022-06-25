---
layout: post
title: pascals-triangle
date: 2022-06-25T14:23:55.827Z
---

```
118. Pascal's TriangleEasyGiven an integer numRows, return the first numRows of Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:

&nbsp;
Example 1:
Input: numRows = 5
Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
Example 2:
Input: numRows = 1
Output: [[1]]

&nbsp;
Constraints:


	1 &lt;= numRows &lt;= 30

 
```

##Code
 ```
  class Solution {
public:
    
    void AnsCalc(int i,int numRows,vector<vector<int>>& ans)
    {
        if(i == (numRows))
            return;
        // cout<<"i : "<<i<<endl;
        // for(int l = 0;l<ans.size();l++)
        // {
        //     for(int p =0;p<ans[l].size();p++)
        //         cout<<ans[l][p]<<" ";
        //     cout<<endl;
        // }
        // cout<<endl;
        
        vector<int> temp;
        int k = ans.size()-1;
        
        temp.push_back(ans[k][0]);
        
        for(int j = 0;j<(i-1);j++)
        {
            temp.push_back(ans[k][j]+ans[k][j+1]);
        }

        temp.push_back(ans[k][i-1]);
        
        ans.push_back(temp);
        
        AnsCalc(i+1,numRows,ans);
        
    }
    
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        ans.push_back({1});
        
        AnsCalc(1,numRows,ans);
        
        return ans;
    }
}; 
```