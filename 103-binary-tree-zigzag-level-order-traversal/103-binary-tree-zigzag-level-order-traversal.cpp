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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        
        queue<TreeNode*> dq;
        dq.push(root);
        int isleft = true;
        vector<vector<int>> ans;
        
        if(!root)
            return ans;
        
        while(!dq.empty()){
            int k = dq.size();
            vector<int> temp;
            while(k--){
                TreeNode* t = dq.front();
                dq.pop();
                    
                temp.push_back(t->val);
                
                if(t->right) dq.push(t->right);
                if(t->left) dq.push(t->left);

            }
            
            if(ans.size()%2 == 0){
                reverse(temp.begin(),temp.end());
                ans.push_back(temp);
            }else{
                ans.push_back(temp);
            }

        }
        
        return ans;
        
    }
};