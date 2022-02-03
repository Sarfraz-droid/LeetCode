/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };,int h
 */
class Solution {
public:
    
    vector<bool> hash;
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        hash.resize(101);
        
        rightView(root,ans,0,0);
        return ans;
        
    }
    
    void rightView(TreeNode* root,vector<int>& ans,int col,int h){
        if(root==NULL)
            return;
        
        if(hash[h] != false)
        {
            cout<<"\nFound : "<<h<<" : "<<root->val;
        }else{
            cout<<"\nAdded : "<<h<<" : "<<root->val;
            ans.push_back(root->val);
            hash[h] = true;
        }
        
        rightView(root->right,ans,col+1,h+1);
        rightView(root->left,ans,col-1,h+1);
        
    }
};