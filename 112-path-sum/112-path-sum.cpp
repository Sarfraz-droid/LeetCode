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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == NULL)
            return false;
        targetSum -= root->val;
        bool ans = false;
        
        if(root->left == NULL and root->right == NULL)
            return targetSum == 0;
        
        if(root->left){
            ans = ans or helper(root->left,targetSum);
        }
        
        if(root->right){
            ans = ans or helper(root->right,targetSum);
        }
        
        return ans;
    }
    
    bool helper(TreeNode* root, int targetSum){
        if(root->left == NULL and root->right == NULL)
            return (targetSum-root->val) == 0;
        
        bool ans = false;
        
        if(root->left != NULL){
            ans= ans or helper(root->left,targetSum- root->val);
        }
        
        if(root->right != NULL){
            ans= ans or helper(root->right,targetSum- root->val);
        }
        
        return ans;
    }
};