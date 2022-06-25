---
layout: post
title: cousins-in-binary-tree
date: 2022-06-25T14:20:30.441Z
---

```
993. Cousins in Binary TreeEasyGiven the root of a binary tree with unique values and the values of two different nodes of the tree x and y, return true if the nodes corresponding to the values x and y in the tree are cousins, or false otherwise.

Two nodes of a binary tree are cousins if they have the same depth with different parents.

Note that in a binary tree, the root node is at the depth 0, and children of each depth k node are at the depth k + 1.

&nbsp;
Example 1:

Input: root = [1,2,3,4], x = 4, y = 3
Output: false


Example 2:

Input: root = [1,2,3,null,4,null,5], x = 5, y = 4
Output: true


Example 3:

Input: root = [1,2,3,null,4], x = 2, y = 3
Output: false


&nbsp;
Constraints:


	The number of nodes in the tree is in the range [2, 100].
	1 &lt;= Node.val &lt;= 100
	Each node has a unique value.
	x != y
	x and y are exist in the tree.

 
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
    int ad,bd;
    bool isCousins(TreeNode* root, int x, int y) {
        ad = -1;
        bd = -1;
        
        getDepth(root,x,y,0);
        cout<<ad<<" "<<bd<<"\n";
        
        if(ad == bd && ad != -1 && bd != -1)
            return true;
        else 
            return false;
        
    }
    
    
    void getDepth(TreeNode* root,int a,int b,int depth)
    {
        if(root == nullptr)
            return;
        
        bool found = false;
        if(root->left!= nullptr)
        {
            cout<<root->left->val<<" ";
            if(root->left->val == a)
            {       
                ad = depth;
                found = true;
            }
            else if(root->left->val == b)
            {    
                bd = depth;
                found = true;
            }
            
        }
        if(root->right != nullptr)
        {
            cout<<root->right->val;                
            if(root->right->val == a && found == false)
            {
                ad = depth;
                found = true;
            }
            else if(root->right->val == b && found == false)
            {
                bd = depth;
                found = true;
            }
        }  
        cout<<endl;
        
        if(!found)
        {
            getDepth(root->right,a,b,depth+1);
            getDepth(root->left,a,b,depth+1);
        }
    }
    
    int findDepth(TreeNode* root)
    {
        if(root == nullptr)
            return 0;
        
        return 1 + max(findDepth(root->left),findDepth(root->right));
    }
}; 
```