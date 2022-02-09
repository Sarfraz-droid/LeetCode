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
    bool findTarget(TreeNode* root, int k) {
        unordered_map<int,int> mp;
        inorder(root,mp);
        
        for(auto x : mp){
            if((k-x.first) == x.first){
                if(x.second > 1)
                    return true;
            }else{
                if(mp.find(k-x.first) != mp.end()){
                    return true;
                }
            }
        }
        
        
        return false;
    }
    
    void inorder(TreeNode* root,unordered_map<int,int>& mp){
        if(root == NULL)
            return;
        
        inorder(root->left,mp);
        mp[root->val]++;
        inorder(root->right,mp);
    }
};