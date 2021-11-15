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
    
    vector<int> sums;
    
    int sumNumbers(TreeNode* root) {
        
        if(root->left == NULL and root->right == NULL)
            return root->val;
        
        headToLeaf(root->left,root->val);
        headToLeaf(root->right,root->val);
        int ans = accumulate(sums.begin(),sums.end(),0);
        
        return ans;
    }
    
    void headToLeaf(TreeNode* root,int temp)
    {
//         Base
        if(root == NULL)
        {
            return;
        }
        
        
        temp = temp*10 + root->val;
        
        if(root->left == NULL and root->right == NULL)
        {
            sums.push_back(temp);
            cout<<temp<<endl;
            return;
        }
        
        if(root->left != NULL)
            headToLeaf(root->left,temp);
        if(root->right != NULL)
            headToLeaf(root->right,temp);
        
    }
    
};