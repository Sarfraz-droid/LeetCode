---
layout: post
title: 376-wiggle-subsequence
date: 2022-06-25T14:20:30.340Z
---

```
376. Wiggle SubsequenceMediumA wiggle sequence is a sequence where the differences between successive numbers strictly alternate between positive and negative. The first difference (if one exists) may be either positive or negative. A sequence with one element and a sequence with two non-equal elements are trivially wiggle sequences.


	For example, [1, 7, 4, 9, 2, 5] is a wiggle sequence because the differences (6, -3, 5, -7, 3) alternate between positive and negative.
	In contrast, [1, 4, 7, 2, 5] and [1, 7, 4, 5, 5] are not wiggle sequences. The first is not because its first two differences are positive, and the second is not because its last difference is zero.


A subsequence is obtained by deleting some elements (possibly zero) from the original sequence, leaving the remaining elements in their original order.

Given an integer array nums, return the length of the longest wiggle subsequence of nums.

&nbsp;
Example 1:

Input: nums = [1,7,4,9,2,5]
Output: 6
Explanation: The entire sequence is a wiggle sequence with differences (6, -3, 5, -7, 3).


Example 2:

Input: nums = [1,17,5,10,13,15,10,5,16,8]
Output: 7
Explanation: There are several subsequences that achieve this length.
One is [1, 17, 10, 13, 10, 16, 8] with differences (16, -7, 3, -3, 6, -8).


Example 3:

Input: nums = [1,2,3,4,5,6,7,8,9]
Output: 2


&nbsp;
Constraints:


	1 &lt;= nums.length &lt;= 1000
	0 &lt;= nums[i] &lt;= 1000


&nbsp;
Follow up: Could you solve this in O(n) time?
 
```

##Code
 ```
  struct Node{
    bool isIncreasing;
    int val;
    
    Node(bool a,int b){
        isIncreasing = a;
        val = b;
    }
    
};

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        stack<Node*> st;
        int n = nums.size();
        int i = 0;
        while(i<n)
        {
            if(st.size() == 0){
                st.push(new Node(false,nums[i]));
                i++;
            }else if(st.size() == 1){
                Node* top = st.top();
                if(top->val != nums[i]){
                    bool type = nums[i] > top->val;
                    st.push(new Node(type,nums[i]));
                }
                i++;
            }else{            
                Node* top = st.top();            
                if(top->isIncreasing){
                    if(top->val <= nums[i]){
                        st.pop();
                        top->val = nums[i];
                        st.push(top);
                    }else{
                        st.push(new Node(false,nums[i]));
                    }
                }else{
                    if(top->val >= nums[i]){
                        st.pop();
                        top->val = nums[i];
                        st.push(top);
                    }else{
                        st.push(new Node(true,nums[i]));
                    }
                }
                i++;
            }
        }
        
        return st.size();
    }
}; 
```
##NOTES.md
 ---
layout: post
title: 376-wiggle-subsequence
date: 2022-06-25T14:20:30.340Z
---

```
​ 
```
