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
    void flatten(TreeNode* root) {
        if(root == NULL)
            return;
        
        TreeNode* ans = new TreeNode(root->val);
        TreeNode* temp = ans;
        FlattenTree(root->left,temp);
        FlattenTree(root->right,temp);
        
        root->left = NULL;
        root->right = ans->right;
    }
    
    void ChangeTree(TreeNode* root,TreeNode* ans)
    {

        
    }
    
    void inorder(TreeNode* ans)
    {
        if(ans == NULL)
            return;
        
        inorder(ans->left);
        cout<<ans->val<<" ";
        inorder(ans->right);
    }
    
    
    void FlattenTree(TreeNode* root,TreeNode* &ans)
    {
        if(root == NULL)
            return;
        
        
        ans->right = new TreeNode(root->val);
        ans = ans->right;
        FlattenTree(root->left,ans);       
        
        FlattenTree(root->right,ans);
        
    }
};