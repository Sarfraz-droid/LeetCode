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
    vector<int> vec;
    int kthSmallest(TreeNode* root, int k) {
        TreeNode* head = root;
        vec.clear();
        
        inorder(root);
        
        return vec[k-1];
        
    }
    
    void inorder(TreeNode* root){
        if(root == NULL)
            return;
        
        inorder(root->left);
        vec.push_back(root->val);
        inorder(root->right);
    }
    
    
};