---
layout: post
title: 1382-balance-a-binary-search-tree
date: 2022-06-25T14:20:30.301Z
---

```
1382. Balance a Binary Search TreeMediumGiven the root of a binary search tree, return a balanced binary search tree with the same node values. If there is more than one answer, return any of them.

A binary search tree is balanced if the depth of the two subtrees of every node never differs by more than 1.

&nbsp;
Example 1:

Input: root = [1,null,2,null,3,null,4,null,null]
Output: [2,1,3,null,null,null,4]
Explanation: This is not the only correct answer, [3,1,4,null,2] is also correct.


Example 2:

Input: root = [2,1,3]
Output: [2,1,3]


&nbsp;
Constraints:


	The number of nodes in the tree is in the range [1, 104].
	1 &lt;= Node.val &lt;= 105

 
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
    vector<int> vec;
    int n;
    
        
    void inorder(TreeNode* root){
        if(!root)
            return;
        
        inorder(root->left);        
        vec.push_back(root->val);
        inorder(root->right);
    }
    
    TreeNode* makeTree(int f,int l){
        if(f > l)
            return NULL;
        
        int mid = (f+l)/2;
        
        TreeNode* temp = new TreeNode(vec[mid]);
        temp->left = makeTree(f,mid-1);
        temp->right = makeTree(mid+1,l);
        
        return temp;
        
    }
        
    TreeNode* balanceBST(TreeNode* root) {
        if(!root)
            return NULL;
        
        inorder(root);
        n = vec.size();
        
        
        return makeTree(0,n-1);
    }
}; 
```
##NOTES.md
 ---
layout: post
title: 1382-balance-a-binary-search-tree
date: 2022-06-25T14:20:30.301Z
---

```
​ 
```
