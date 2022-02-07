class Solution {
public:
    int findIndex(vector<int> &arr,int strt,int end,int value)    //returns the index of value inside inorder array
    {
        for(int i=strt;i<=end;i++)
            {
                if(arr[i] == value)
                return i;
            }
            return -1;   
    }
    
    int preOrderIndex=0;
    
    TreeNode *createTree(vector<int> &preOrderarr,vector<int> &inOrderarr,int start,int end){
     
        if(start > end )
            return NULL;

        TreeNode *node = new TreeNode(preOrderarr[preOrderIndex]);
        preOrderIndex++;
        int rootIndex = findIndex(inOrderarr,start,end,node->val);
   
        //divide the inorder array into 2 parts based on root index and correspondingly call recursive calls
        //calling of left and right sequence matters here.
        node->left = createTree(preOrderarr,inOrderarr,start,rootIndex-1);
        node->right  = createTree(preOrderarr,inOrderarr,rootIndex+1,end);

        return node;
    }
    
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        int n = inorder.size();
        return createTree(preorder,inorder,0,n-1);
        
    }
};