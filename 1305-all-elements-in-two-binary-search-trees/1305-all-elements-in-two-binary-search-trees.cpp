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
    
    multiset<int> st;
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        preOrder(root1);
        preOrder(root2);
        
        vector<int> ans(st.begin(),st.end());
        
        return ans;
    }
    
    void preOrder(TreeNode* root){
        if(root == NULL)
            return;
        
        preOrder(root->left);
        st.insert(root->val);
        preOrder(root->right);
        
    }
};