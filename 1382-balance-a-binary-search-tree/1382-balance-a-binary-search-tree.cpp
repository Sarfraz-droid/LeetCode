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
    int n;
    
        
    void inorder(TreeNode* root){
        if(!root)
            return;
        
        inorder(root->left);        
        vec.push_back(root->val);
        inorder(root->right);
    }
    
    TreeNode* makeTree(int f,int l){
        if(f > l)
            return NULL;
        
        int mid = (f+l)/2;
        
        TreeNode* temp = new TreeNode(vec[mid]);
        temp->left = makeTree(f,mid-1);
        temp->right = makeTree(mid+1,l);
        
        return temp;
        
    }
        
    TreeNode* balanceBST(TreeNode* root) {
        if(!root)
            return NULL;
        
        inorder(root);
        n = vec.size();
        
        
        return makeTree(0,n-1);
    }
};