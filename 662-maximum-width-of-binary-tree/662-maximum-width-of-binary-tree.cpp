class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
       int maxWidth=0; //maximum width
        
        if(!root)
            return maxWidth;
        
        
        queue<pair<TreeNode* ,int>>que;//this will store a pair of node value with its index
        que.push({root,0});
        
        while(!que.empty()){
            
            int size=que.size();
            int levelMinIndex=que.front().second ; 
            int levelfirstIndex=-1,levellastIndex=-1;
            
            for(int i=0;i<size;i++){
                long long levelCurrIndex=que.front().second -levelMinIndex;
                TreeNode* node=que.front().first;
                que.pop();
                if(i==0)
                   levelfirstIndex=levelCurrIndex;
                if(i==size-1)
                    levellastIndex=levelCurrIndex;
                if(node->left)
                    que.push({node->left ,2*levelCurrIndex + 1});
                if(node->right)
                    que.push({node->right ,2*levelCurrIndex + 2});
            }
            
            maxWidth = max(maxWidth ,levellastIndex-levelfirstIndex+1 );
        }
        
        return maxWidth;
    }
};