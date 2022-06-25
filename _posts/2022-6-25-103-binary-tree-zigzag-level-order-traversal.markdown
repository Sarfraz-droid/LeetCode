---
layout: post
title: 103-binary-tree-zigzag-level-order-traversal
date: 2022-06-25T14:20:30.286Z
---

```
103. Binary Tree Zigzag Level Order TraversalMediumGiven the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).

&nbsp;
Example 1:

Input: root = [3,9,20,null,null,15,7]
Output: [[3],[20,9],[15,7]]


Example 2:

Input: root = [1]
Output: [[1]]


Example 3:

Input: root = []
Output: []


&nbsp;
Constraints:


	The number of nodes in the tree is in the range [0, 2000].
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
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        
        queue<TreeNode*> dq;
        dq.push(root);
        int isleft = true;
        vector<vector<int>> ans;
        
        if(!root)
            return ans;
        
        while(!dq.empty()){
            int k = dq.size();
            vector<int> temp;
            while(k--){
                TreeNode* t = dq.front();
                dq.pop();
                    
                temp.push_back(t->val);
                
                if(t->right) dq.push(t->right);
                if(t->left) dq.push(t->left);

            }
            
            if(ans.size()%2 == 0){
                reverse(temp.begin(),temp.end());
                ans.push_back(temp);
            }else{
                ans.push_back(temp);
            }

        }
        
        return ans;
        
    }
}; 
```
##NOTES.md
 ---
layout: post
title: 103-binary-tree-zigzag-level-order-traversal
date: 2022-06-25T14:20:30.286Z
---

```
​ 
```
