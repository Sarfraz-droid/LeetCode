class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int i = 0,j = 0;
        vector<vector<int>> vec(r,vector<int>(c));
        
        if(mat.size()*mat[0].size() !=  r*c)
            return mat;
        
        for(int m = 0;m<mat.size();m++)
        {
            for(int n = 0;n<mat[0].size();n++)
            {
                if(j == c)
                {
                    i++;
                    j = 0;
                }
                    
                vec[i][j] = mat[m][n];
                j++;
            }
                
        }
        
        return vec;
    }
};