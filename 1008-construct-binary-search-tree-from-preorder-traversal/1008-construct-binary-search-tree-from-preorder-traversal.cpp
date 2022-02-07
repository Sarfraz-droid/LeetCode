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
    
    int pre = 0;
    int size = 0;
    TreeNode* bstFromPreorder(vector<int>& preorder) {      
        size = preorder.size();
        pre = 0;
        
        TreeNode* root = new TreeNode(preorder[pre]);
        pre++;
        root->left = helper(preorder,INT_MIN,root->val);    
        root->right = helper(preorder,root->val,INT_MAX);

        return root;
    }
    
    TreeNode* helper(vector<int>& preorder,int mid,int last){
        if(pre == size or preorder[pre] > last or preorder[pre] < mid){
            return NULL;   
        }
        
        
        
        TreeNode* root = new TreeNode(preorder[pre]);
        pre++;
        
        root->left = helper(preorder,INT_MIN,root->val);
        root->right = helper(preorder,root->val,last);
        
        return root;        
    }
    
};