class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        set<ListNode*> st;
        int pos = 1;
        while(head != NULL){
            
            if(st.find(head) != st.end()){
                return head;
            }
            
            st.insert(head);
            pos++;
            head = head->next;
        }
        
        return NULL;
    }
};