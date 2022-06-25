---
layout: post
title: 1305-all-elements-in-two-binary-search-trees
date: 2022-06-25T14:52:08.028Z
---

```
1305. All Elements in Two Binary Search TreesMediumGiven two binary search trees root1 and root2, return a list containing all the integers from both trees sorted in ascending order.

&nbsp;
Example 1:

Input: root1 = [2,1,4], root2 = [1,0,3]
Output: [0,1,1,2,3,4]


Example 2:

Input: root1 = [1,null,8], root2 = [8,1]
Output: [1,1,8,8]


&nbsp;
Constraints:


	The number of nodes in each tree is in the range [0, 5000].
	-105 &lt;= Node.val &lt;= 105

 
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
    
    multiset<int> st;
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        preOrder(root1);
        preOrder(root2);
        
        vector<int> ans(st.begin(),st.end());
        
        return ans;
    }
    
    void preOrder(TreeNode* root){
        if(root == NULL)
            return;
        
        preOrder(root->left);
        st.insert(root->val);
        preOrder(root->right);
        
    }
}; 
```
##NOTES.md
 ---
layout: post
title: 1305-all-elements-in-two-binary-search-trees
date: 2022-06-25T14:52:08.027Z
---

```
​ 
```
