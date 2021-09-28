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
    
    int pos;
    int num;
    
    void LtoIn(ListNode* head)
    {
        if(head == NULL)
            return;
        LtoIn(head->next);
        
        num += head->val*(1<<pos);
        pos++;

    }
    
    int getDecimalValue(ListNode* head) {
        pos = 0;
        num = 0;
        LtoIn(head);
        
        return num;
    }
};