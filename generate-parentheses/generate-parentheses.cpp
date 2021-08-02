class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        brackets(n,0,0,"",ans);
        return ans;
    }
    
    void brackets(int n,int open,int close,string s,vector<string> &ans)
    {
        if(s.size() == 2*n)
        {
            ans.push_back(s);
            return;
        }
        
        if(open < n)
        {
            brackets(n,open+1,close,s+'(',ans);
        }
        if(close < open)
        {
            brackets(n,open,close+1,s+')',ans);
        }
    }
    
    
};