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
    TreeNode* ans;
    void flatten(TreeNode* root) {
        
        if(root==NULL)
            return;
        
        ans = new TreeNode();
        TreeNode* head = ans;       
        
        FlattenTree(root);

        root->left = NULL;
        root->right = head->right->right;
        
    }
    
    void FlattenTree(TreeNode* root){
        if(root == NULL)
            return;
        
        ans->right = new TreeNode(root->val);
        ans = ans->right;
        FlattenTree(root->left);
        FlattenTree(root->right);
    }
};