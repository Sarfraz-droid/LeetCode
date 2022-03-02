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