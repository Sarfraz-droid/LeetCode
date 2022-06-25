---
layout: post
title: 236-lowest-common-ancestor-of-a-binary-tree
date: 2022-06-25T14:20:30.332Z
---

```
236. Lowest Common Ancestor of a Binary TreeMediumGiven a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

&nbsp;
Example 1:

Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
Output: 3
Explanation: The LCA of nodes 5 and 1 is 3.


Example 2:

Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
Output: 5
Explanation: The LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA definition.


Example 3:

Input: root = [1,2], p = 1, q = 2
Output: 1


&nbsp;
Constraints:


	The number of nodes in the tree is in the range [2, 105].
	-109 &lt;= Node.val &lt;= 109
	All Node.val are unique.
	p != q
	p and q will exist in the tree.

 
```

##Code
 ```
  /**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* ans;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(LCA(root,p,q)){
            return ans;
        }else{
            return NULL;
        }
    }

    bool LCA(TreeNode* root,TreeNode* p,TreeNode* q){
        if(root == NULL){
            return false;
        }
        
        bool left = LCA(root->left,p,q);
        bool right = LCA(root->right,p,q);

        
        if(root == p or root == q){        
        
            if(left or right){
                ans = root;
            }
            
            return true;
        }

        
        
        if(left == true and right == true){
            ans = root;
            return true;
        }
        
        return left or right;
        
    }
    
}; 
```
##NOTES.md
 ---
layout: post
title: 236-lowest-common-ancestor-of-a-binary-tree
date: 2022-06-25T14:20:30.332Z
---

```
​ 
```
