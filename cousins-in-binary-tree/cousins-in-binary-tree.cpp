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
    int ad,bd;
    bool isCousins(TreeNode* root, int x, int y) {
        ad = -1;
        bd = -1;
        
        getDepth(root,x,y,0);
        cout<<ad<<" "<<bd<<"\n";
        
        if(ad == bd && ad != -1 && bd != -1)
            return true;
        else 
            return false;
        
    }
    
    
    void getDepth(TreeNode* root,int a,int b,int depth)
    {
        if(root == nullptr)
            return;
        
        bool found = false;
        if(root->left!= nullptr)
        {
            cout<<root->left->val<<" ";
            if(root->left->val == a)
            {       
                ad = depth;
                found = true;
            }
            else if(root->left->val == b)
            {    
                bd = depth;
                found = true;
            }
            
        }
        if(root->right != nullptr)
        {
            cout<<root->right->val;                
            if(root->right->val == a && found == false)
            {
                ad = depth;
                found = true;
            }
            else if(root->right->val == b && found == false)
            {
                bd = depth;
                found = true;
            }
        }  
        cout<<endl;
        
        if(!found)
        {
            getDepth(root->right,a,b,depth+1);
            getDepth(root->left,a,b,depth+1);
        }
    }
    
    int findDepth(TreeNode* root)
    {
        if(root == nullptr)
            return 0;
        
        return 1 + max(findDepth(root->left),findDepth(root->right));
    }
};