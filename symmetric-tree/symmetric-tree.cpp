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
    bool isSymmetric(TreeNode* root) {
        return findSymmetry(root->left,root->right);
    }
    
    bool findSymmetry(TreeNode* left,TreeNode* right)
    {
        if(left == NULL and right == NULL)
            return true;
        else if(left == NULL or right == NULL)
            return false;
        
        
        return findSymmetry(left->left,right->right) and left->val == right->val and findSymmetry(left->right,right->left);
    }
};