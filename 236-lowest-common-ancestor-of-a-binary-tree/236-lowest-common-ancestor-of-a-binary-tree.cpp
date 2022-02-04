/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* ans;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(LCA(root,p,q)){
            return ans;
        }else{
            return NULL;
        }
    }

    bool LCA(TreeNode* root,TreeNode* p,TreeNode* q){
        if(root == NULL){
            return false;
        }
        
        bool left = LCA(root->left,p,q);
        bool right = LCA(root->right,p,q);

        
        if(root == p or root == q){        
        
            if(left or right){
                ans = root;
            }
            
            return true;
        }

        
        
        if(left == true and right == true){
            ans = root;
            return true;
        }
        
        return left or right;
        
    }
    
};