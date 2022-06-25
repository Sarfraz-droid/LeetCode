---
layout: post
title: path-sum-ii
date: 2022-06-25T14:52:08.144Z
---

```
[Discussion Post (created on 6/10/2021 at 18:57)](https://leetcode.com/problems/path-sum-ii/discuss/1562771/Simple-Recursive-Approach)  
113. Path Sum IIMediumGiven the root of a binary tree and an integer targetSum, return all root-to-leaf paths where the sum of the node values in the path equals targetSum. Each path should be returned as a list of the node values, not node references.

A root-to-leaf path is a path starting from the root and ending at any leaf node. A leaf is a node with no children.

&nbsp;
Example 1:

Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
Output: [[5,4,11,2],[5,8,4,5]]
Explanation: There are two paths whose sum equals targetSum:
5 + 4 + 11 + 2 = 22
5 + 8 + 4 + 5 = 22


Example 2:

Input: root = [1,2,3], targetSum = 5
Output: []


Example 3:

Input: root = [1,2], targetSum = 0
Output: []


&nbsp;
Constraints:


	The number of nodes in the tree is in the range [0, 5000].
	-1000 &lt;= Node.val &lt;= 1000
	-1000 &lt;= targetSum &lt;= 1000

 
```

##Code
 ```
  /**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> temp;
        find_sum(root,targetSum,temp,0);
        
        return ans;
    }
    
    void find_sum(TreeNode* root,int targetSum,vector<int> temp,int curr)
    {
        

        if(root == NULL)
            return;
        
        temp.push_back(root->val);
        
        curr = curr+root->val;
        find_sum(root->left,targetSum,temp,curr);
        find_sum(root->right,targetSum,temp,curr);
        if(curr == targetSum and root->left == NULL and root->right == NULL)
            ans.push_back(temp);
        
        
        
    }
}; 
```