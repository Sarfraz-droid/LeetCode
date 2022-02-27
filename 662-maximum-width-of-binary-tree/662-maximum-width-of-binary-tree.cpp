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
    int widthOfBinaryTree(TreeNode* root) {
        
        queue<pair<TreeNode*,long long>> q;
        
        q.push({root,0});
        int maxAns = 1;
        
        
        
        while(!q.empty()){
            int k = q.size();
            long long f = -1,l = -1;
            int size = q.size();    
            long long levelMin = q.front().second;
            // cout<<q.size()<<" : ";
            
            while(k--){
                
                TreeNode* temp = q.front().first;
                long long curr = q.front().second - levelMin;
                q.pop();
                
                cout<<k<<":"<<size<<"-"<<curr<<" ";
                
                if(k == size-1)
                    f = curr;
                else if(k == 0)
                    l = curr;
                
                
                
                if(temp->left)
                    q.push({temp->left,curr*2+1});

                if(temp->right)
                    q.push({temp->right,curr*2+2});
            }
            cout<<"    "<<f<<" "<<l;
            cout<<endl;
            if(f != -1 and l != -1)
            { 
                long long t = l-f+1;
                maxAns = maxAns > t ? maxAns : t;
            }
        }
        
        return maxAns;
    }
};