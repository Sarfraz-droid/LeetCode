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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head;
        ListNode* front = head;
        
        while(n-- && fast!=NULL)
        {
            fast = fast->next;
        }
        
        if(fast == NULL)
        {
            front = NULL;
            return head->next;
        }
        
        while(fast->next!=NULL)
        {
            fast = fast->next;
            front = front->next;
        }
        
        if(front->next->next != NULL)
            front->next = front->next->next;
        else
            front->next = NULL;
        
        return head;
    }
    
};