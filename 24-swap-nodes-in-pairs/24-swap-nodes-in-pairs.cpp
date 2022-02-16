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
    ListNode* swapPairs(ListNode* head) {
        
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        if(head == NULL or head->next == NULL)
            return head;
        
     
        
        ListNode* t = swapPairs(head->next->next);
        ListNode* temp = head->next;
        
        head->next = t;
        temp->next = head;

        
        return temp;
    }
};