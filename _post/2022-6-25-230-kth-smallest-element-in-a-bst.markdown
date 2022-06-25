---
layout: post
title: 230-kth-smallest-element-in-a-bst
date: 2022-06-25T14:23:55.706Z
---

```
230. Kth Smallest Element in a BSTMediumGiven the root of a binary search tree, and an integer k, return the kth smallest value (1-indexed) of all the values of the nodes in the tree.

&nbsp;
Example 1:

Input: root = [3,1,4,null,2], k = 1
Output: 1


Example 2:

Input: root = [5,3,6,2,4,null,null,1], k = 3
Output: 3


&nbsp;
Constraints:


	The number of nodes in the tree is n.
	1 &lt;= k &lt;= n &lt;= 104
	0 &lt;= Node.val &lt;= 104


&nbsp;
Follow up: If the BST is modified often (i.e., we can do insert and delete operations) and you need to find the kth smallest frequently, how would you optimize?
 
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
    int ans;
    int kthSmallest(TreeNode* root, int k) {
        TreeNode* head = root;
        ans = 0;
        inorder(root,k);        
        
        return ans;
    }
    
    void inorder(TreeNode* root,int& count){
        if(root == NULL)
            return;
        
        inorder(root->left,count);
        
        if(count >0){
            ans = root->val;
            count--;
        }
        
        inorder(root->right,count);
    }
    
    
}; 
```
##NOTES.md
 ---
layout: post
title: 230-kth-smallest-element-in-a-bst
date: 2022-06-25T14:23:55.706Z
---

```
​ 
```
