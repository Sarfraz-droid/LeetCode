class Solution {
public:
    
    void AnsCalc(int i,int numRows,vector<vector<int>>& ans)
    {
        if(i == (numRows))
            return;
        // cout<<"i : "<<i<<endl;
        // for(int l = 0;l<ans.size();l++)
        // {
        //     for(int p =0;p<ans[l].size();p++)
        //         cout<<ans[l][p]<<" ";
        //     cout<<endl;
        // }
        // cout<<endl;
        
        vector<int> temp;
        int k = ans.size()-1;
        
        temp.push_back(ans[k][0]);
        
        for(int j = 0;j<(i-1);j++)
        {
            temp.push_back(ans[k][j]+ans[k][j+1]);
        }

        temp.push_back(ans[k][i-1]);
        
        ans.push_back(temp);
        
        AnsCalc(i+1,numRows,ans);
        
    }
    
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        ans.push_back({1});
        
        AnsCalc(1,numRows,ans);
        
        return ans;
    }
};