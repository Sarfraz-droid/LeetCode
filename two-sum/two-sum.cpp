class Solution {
public:
    static bool compare(const pair<int,int> &a,const pair<int,int> &b)   
    {
        return (a.first < b.first);
    }
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int,int>> num_part;
        for(int i = 0;i<nums.size();i++)
        {
            num_part.push_back(make_pair(nums[i],i));
        }
        int f = 0;
        int l = nums.size()-1;
        sort(num_part.begin(),num_part.end(),compare);
        while(f<l)
        {
            int s = num_part[f].first + num_part[l].first;
            cout<<s<<endl;
            if(s<target)
                f++;
            else if(s>target)
                l--;
            else
            {
                break;
            }
        }
        vector<int> ans;
        ans.push_back(num_part[f].second);
        ans.push_back(num_part[l].second);
        return ans;
    }
};