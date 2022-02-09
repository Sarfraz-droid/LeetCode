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
    int kthSmallest(TreeNode* root, int k) {
        TreeNode* head = root;
        ans = 0;
        inorder(root,k);        
        
        return ans;
    }
    
    void inorder(TreeNode* root,int& count){
        if(root == NULL)
            return;
        
        inorder(root->left,count);
        
        if(count >0){
            ans = root->val;
            count--;
        }
        
        inorder(root->right,count);
    }
    
    
};