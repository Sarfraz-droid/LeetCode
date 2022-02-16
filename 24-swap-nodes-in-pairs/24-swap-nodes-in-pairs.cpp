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
        ListNode* front = head;
        
        while(head!= NULL and head->next != NULL){
            int t = head->val;
            head->val = head->next->val;
            head->next->val = t;
            head = head->next->next;
        }
        
        return front;
    }
};