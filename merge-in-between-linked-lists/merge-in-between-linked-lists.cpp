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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* head2 = list2;
        ListNode* head = new ListNode(list1->val);
        ListNode* front = head;
        list1 = list1->next;
        int i = 1;
        
        while(list2->next!=NULL)
        {
            list2 = list2->next;
        }
        
        bool found = false;
        while(list1 != NULL)
        {       
            cout<<list1->val<<" ";
            if(i == a)
            {
                front->next = head2;
                front = list2;
                while(i != b)
                {    
                    list1 = list1->next;
                    i++;
                }
                // cout<<list1->val<<" ";
            }else
            {
                front->next = new ListNode(list1->val);
                front = front->next;
            }
            i++;
            
            list1 = list1->next;
        }
        
        return head;
        
    }
};