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
    vector<vector<int>> ans;
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> temp;
        find_sum(root,targetSum,temp,0);
        
        return ans;
    }
    
    void find_sum(TreeNode* root,int targetSum,vector<int> temp,int curr)
    {
        

        if(root == NULL)
            return;
        
        temp.push_back(root->val);
        
        curr = curr+root->val;
        find_sum(root->left,targetSum,temp,curr);
        find_sum(root->right,targetSum,temp,curr);
        if(curr == targetSum and root->left == NULL and root->right == NULL)
            ans.push_back(temp);
        
        
        
    }
};