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
    int postIndex = 0;
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        postIndex = postorder.size()-1;
        
        return makeTree(inorder,postorder,0,inorder.size()-1);
        
    }
    
    TreeNode* makeTree(vector<int>& inorder,vector<int>& postorder,int start,int end){
        if(start > end)
            return NULL;
        TreeNode* node = new TreeNode(postorder[postIndex]);
        postIndex--;        
        int mid = midIndex(inorder,start,end,node->val);        
        if(mid!=-1){
            node->right = makeTree(inorder,postorder,mid+1,end);
            node->left = makeTree(inorder,postorder,start,mid-1);
        }
        
        return node;
    }
    
    int midIndex(vector<int>& inorder,int start,int end,int val){
        for(int i = start;i<=end;i++){
            if(val == inorder[i])
                return i;
        }
        
        return -1;
    }
    
    
};