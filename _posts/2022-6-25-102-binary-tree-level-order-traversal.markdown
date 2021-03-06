---
layout: post
title: 102-binary-tree-level-order-traversal
date: 2022-06-25T14:28:04.947Z
---

```
102. Binary Tree Level Order TraversalMediumGiven the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).

&nbsp;
Example 1:

Input: root = [3,9,20,null,null,15,7]
Output: [[3],[9,20],[15,7]]


Example 2:

Input: root = [1]
Output: [[1]]


Example 3:

Input: root = []
Output: []


&nbsp;
Constraints:


	The number of nodes in the tree is in the range [0, 2000].
	-1000 &lt;= Node.val &lt;= 1000

 
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> ans;
        
        if(root == NULL)
            return ans;
        
        q.push(root);
        
        while(!q.empty()){
            vector<int> temp;
            
            int k = q.size();
            
            while(k--){
                TreeNode* t = q.front();
                q.pop();
                
                temp.push_back(t->val);
                
                if(t->left != NULL) q.push(t->left);
                if(t->right != NULL) q.push(t->right);
                
            }
         
            ans.push_back(temp);
        }
        
        return ans;
    }
}; 
```
##NOTES.md
 ---
layout: post
title: 102-binary-tree-level-order-traversal
date: 2022-06-25T14:28:04.946Z
---

```
​ 
```
