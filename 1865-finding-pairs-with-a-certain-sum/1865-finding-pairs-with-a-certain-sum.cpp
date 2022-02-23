class FindSumPairs {
public:
    vector<int> nums1;
    vector<int> nums2;
    unordered_map<int,int> mp2;
    FindSumPairs(vector<int>& n1, vector<int>& n2) {
        nums1 = n1;
        nums2 = n2;
        for(auto x : n2) mp2[x]++;
    }
    
    void add(int index, int val) {
        mp2[nums2[index]]--;
        nums2[index] += val;
        mp2[nums2[index]]++;
    }
    
    int count(int tot) {
        int c = 0;
        
        for(auto x : nums1)
        {
            int rem = tot - x;
            
            c += mp2[rem];
        }
        
        return c;
    }
};
/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */