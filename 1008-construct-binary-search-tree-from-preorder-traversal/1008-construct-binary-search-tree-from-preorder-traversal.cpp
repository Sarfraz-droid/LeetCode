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
        // cout<<pre<<" "<<size<<"\n";
        if(pre == size)
            return root;
        root->left = helper(preorder,INT_MIN,root->val);
        
        // cout<<"\n------\n"<<preorder[pre]<<"\n------\n";
        root->right = helper(preorder,root->val,INT_MAX);

        return root;
    }
    
    TreeNode* helper(vector<int>& preorder,int mid,int last){
        
        if(pre == size)
            return NULL;
        cout<<mid<<" "<<last<<"\n";
        
        if(pre == size or preorder[pre] > last or preorder[pre] < mid){
            return NULL;   
        }
        
        
        cout<<preorder[pre]<<" - "<<mid<<" "<<last<<"\n";
        
        TreeNode* root = new TreeNode(preorder[pre]);
        pre++;
        
        root->left = helper(preorder,INT_MIN,root->val);
        root->right = helper(preorder,root->val,last);
        
        return root;        
    }
    
};