/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        multiset<int> st;
        while(head!=NULL){
            st.insert(head->val);
            head = head->next;
        }
        
        ListNode* front = new ListNode();
        ListNode* f = front;
        for(auto x: st){
            ListNode* temp = new ListNode(x);
            
            front->next = temp;
            front = front->next;
        }
        
        return f->next;
    }
};