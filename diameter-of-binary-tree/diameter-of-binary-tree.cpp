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
    int d;
    
    int maxdia(TreeNode* root)
    {
        if(root == NULL)
            return 0;
        int left = maxdia(root->left);
        int right = maxdia(root->right);
        
        d = max(d,left+right);
        
        return max(left,right) + 1;
        
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        d = 0;
        
        maxdia(root);
        
        return d;
        
    }
};