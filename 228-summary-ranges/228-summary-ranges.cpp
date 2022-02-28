class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        int l = -1,r = -1;
        
        for(int i =0;i<nums.size();i++){
            if(l == -1){
                l = i;
                continue;
            }
            
            if(r == -1){
                if(nums[l]+1 == nums[i]){
                    r = i;
                }else{
                    ans.push_back(to_string(nums[l]));
                    l = i;
                }
            }else{
                if(nums[r]+1 == nums[i]){
                    r = i;
                }else{
                    ans.push_back(to_string(nums[l])+"->"+to_string(nums[r]));
                    l = i;
                    r = -1;
                }
            }
        }
        
        
        if(r == -1 and l != -1){
            ans.push_back(to_string(nums[l]));
        }else if(r != -1 and l != -1){
            ans.push_back(to_string(nums[l])+"->"+to_string(nums[r]));
        }
        
        return ans;
    }
};