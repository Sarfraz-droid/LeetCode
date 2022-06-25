---
layout: post
title: 199-binary-tree-right-side-view
date: 2022-06-25T14:20:30.323Z
---

```
199. Binary Tree Right Side ViewMediumGiven the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

&nbsp;
Example 1:

Input: root = [1,2,3,null,5,null,4]
Output: [1,3,4]


Example 2:

Input: root = [1,null,3]
Output: [1,3]


Example 3:

Input: root = []
Output: []


&nbsp;
Constraints:


	The number of nodes in the tree is in the range [0, 100].
	-100 &lt;= Node.val &lt;= 100

 
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
 * };,int h
 */
class Solution {
public:
    
    vector<bool> hash;
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        hash.resize(101);
        
        rightView(root,ans,0,0);
        return ans;
        
    }
    
    void rightView(TreeNode* root,vector<int>& ans,int col,int h){
        if(root==NULL)
            return;
        
        if(!hash[h])
        {
            ans.push_back(root->val);
            hash[h] = true;
        }
        
        rightView(root->right,ans,col+1,h+1);
        rightView(root->left,ans,col-1,h+1);
        
    }
}; 
```
##NOTES.md
 ---
layout: post
title: 199-binary-tree-right-side-view
date: 2022-06-25T14:20:30.323Z
---

```
​ 
```
