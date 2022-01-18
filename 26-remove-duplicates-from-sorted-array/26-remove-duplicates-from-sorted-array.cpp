class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        unordered_map<int,int> mp;

        int count = 0;
        for(int i = 0;i<nums.size();i++)
        {
            if(mp[nums[i]] == 0)
            {
                count++;
                mp[nums[i]]++;
            }else
            {
                cout<<nums[i]<<" ";
                auto it = nums.begin()+i;
                cout<<*it;
                nums.erase(it);
                i--;
            }
        }
        return count;
    }
};
