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
    bool isBalanced(TreeNode* root) {
        return checkBalance(root);
    }
    
    bool checkBalance(TreeNode* root){
        if(root == NULL)
            return true;
        
        int l = treeHeight(root->left);
        int r = treeHeight(root->right);
        
        bool rightCheck = checkBalance(root->right);
        bool leftCheck = checkBalance(root->left);
        
        
        return abs(l-r)<=1 and rightCheck and leftCheck;
    }
    
    int treeHeight(TreeNode* root)
    {
        
        if(root == NULL)
            return 0;
        return 1 + max(treeHeight(root->left),treeHeight(root->right));
    }
};