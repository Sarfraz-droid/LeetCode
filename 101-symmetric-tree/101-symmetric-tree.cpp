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
        if(root == NULL)
            return true;
        
        return symm(root->left,root->right);
        
    }
    
    bool symm(TreeNode* left,TreeNode* right){
        if(left == NULL and right == NULL)
            return true;
        else if(left == NULL or right == NULL)
            return false;
        
        
        if(left->val != right->val){
            return false;   
        }
        
        bool a_left = symm(left->left,right->right);
        bool a_right = symm(left->right,right->left);
        
        return a_left and a_right;
    }
    
};