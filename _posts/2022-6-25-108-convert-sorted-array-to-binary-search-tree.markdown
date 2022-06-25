---
layout: post
title: 108-convert-sorted-array-to-binary-search-tree
date: 2022-06-25T14:28:04.950Z
---

```
108. Convert Sorted Array to Binary Search TreeEasyGiven an integer array nums where the elements are sorted in ascending order, convert it to a height-balanced binary search tree.

A height-balanced binary tree is a binary tree in which the depth of the two subtrees of every node never differs by more than one.

&nbsp;
Example 1:

Input: nums = [-10,-3,0,5,9]
Output: [0,-3,9,-10,null,5]
Explanation: [0,-10,5,null,-3,null,9] is also accepted:



Example 2:

Input: nums = [1,3]
Output: [3,1]
Explanation: [1,3] and [3,1] are both a height-balanced BSTs.


&nbsp;
Constraints:


	1 &lt;= nums.length &lt;= 104
	-104 &lt;= nums[i] &lt;= 104
	nums is sorted in a strictly increasing order.

 
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
    TreeNode* helper(vector<int>& nums,int s,int e){
        if(s>e){
            return NULL;
        }
        int mid=(s+e)/2;
        TreeNode *root=new TreeNode();
        root->val=nums[mid];
        TreeNode *lefty=helper(nums,s,mid-1);
        TreeNode* righty=helper(nums,mid+1,e);
        root->left=lefty;
        root->right=righty;
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n=nums.size();
        return helper(nums,0,n-1);
    }
}; 
```
##NOTES.md
 ---
layout: post
title: 108-convert-sorted-array-to-binary-search-tree
date: 2022-06-25T14:28:04.950Z
---

```
​ 
```
