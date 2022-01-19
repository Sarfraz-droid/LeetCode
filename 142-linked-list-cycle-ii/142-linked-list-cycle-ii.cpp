class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) break;
        }
        
        
        slow = head;
        
        if(fast == NULL or fast->next == NULL)
            return NULL;
        
        while(slow !=fast){
            slow = slow->next;
            fast=fast->next;
        }
        
        return slow;
    }
};