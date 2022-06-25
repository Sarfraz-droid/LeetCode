---
layout: post
title: sum-root-to-leaf-numbers
date: 2022-06-25T14:52:08.151Z
---

```
[Discussion Post (created on 16/10/2021 at 1:27)](https://leetcode.com/problems/sum-root-to-leaf-numbers/discuss/1580116/100-Simple-C%2B%2B-Solution)  
129. Sum Root to Leaf NumbersMediumYou are given the root of a binary tree containing digits from 0 to 9 only.

Each root-to-leaf path in the tree represents a number.


	For example, the root-to-leaf path 1 -&gt; 2 -&gt; 3 represents the number 123.


Return the total sum of all root-to-leaf numbers. Test cases are generated so that the answer will fit in a 32-bit integer.

A leaf node is a node with no children.

&nbsp;
Example 1:

Input: root = [1,2,3]
Output: 25
Explanation:
The root-to-leaf path 1-&gt;2 represents the number 12.
The root-to-leaf path 1-&gt;3 represents the number 13.
Therefore, sum = 12 + 13 = 25.


Example 2:

Input: root = [4,9,0,5,1]
Output: 1026
Explanation:
The root-to-leaf path 4-&gt;9-&gt;5 represents the number 495.
The root-to-leaf path 4-&gt;9-&gt;1 represents the number 491.
The root-to-leaf path 4-&gt;0 represents the number 40.
Therefore, sum = 495 + 491 + 40 = 1026.


&nbsp;
Constraints:


	The number of nodes in the tree is in the range [1, 1000].
	0 &lt;= Node.val &lt;= 9
	The depth of the tree will not exceed 10.

 
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
    
    vector<int> sums;
    
    int sumNumbers(TreeNode* root) {
        
        if(root->left == NULL and root->right == NULL)
            return root->val;
        
        headToLeaf(root->left,root->val);
        headToLeaf(root->right,root->val);
        int ans = accumulate(sums.begin(),sums.end(),0);
        
        return ans;
    }
    
    void headToLeaf(TreeNode* root,int temp)
    {
//         Base
        if(root == NULL)
        {
            return;
        }
        
        
        temp = temp*10 + root->val;
        
        if(root->left == NULL and root->right == NULL)
        {
            sums.push_back(temp);
            cout<<temp<<endl;
            return;
        }
        
        if(root->left != NULL)
            headToLeaf(root->left,temp);
        if(root->right != NULL)
            headToLeaf(root->right,temp);
        
    }
    
}; 
```