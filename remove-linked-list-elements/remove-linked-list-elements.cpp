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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* pre = NULL;
        ListNode* front = head;
        
        while(head!=NULL)
        {
            if(head->val == val)
            {
                if(pre == NULL)
                {
                    front = front->next;
                    head = head->next;
                }
                else
                {   
                    pre->next = head->next;
                    // pre = head;
                    head = head->next;

                }
            }else
            {
                pre = head;
                head = head->next;

            }
            
        }
        
        
        return front;
    }
};