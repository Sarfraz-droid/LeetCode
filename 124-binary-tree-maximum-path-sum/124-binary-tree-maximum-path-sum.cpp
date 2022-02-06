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
    int maxPathSum(TreeNode* root) {    
        ans = root->val;
        maxSum(root);
        
        return ans;
    }
    
    int maxSum(TreeNode* root){
  	    if(!root){
            return 0;
   	    }
    
	    int left  = maxSum(root->left);
        left =  left < 0 ?0:left;
        int right = maxSum(root->right);
        right  = right < 0 ? 0 : right;
        
        ans = max(root->val+left + right,ans);
        
        return root->val + max(left,right);
    }

};