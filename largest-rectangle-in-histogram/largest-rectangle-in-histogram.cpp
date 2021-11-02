class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int res = 0;
        vector<int> stack {-1};
        heights.push_back(0);
        for (int i = 0; i < heights.size(); ++i)
        {
            while(stack.size() > 1 && heights[i] < heights[stack.back()])
            {
                int h = heights[stack.back()];
                stack.pop_back();
                res = max(res, (i - stack.back() - 1) * h);
            }
            stack.push_back(i);
        }
        return res;
    }
};