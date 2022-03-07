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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* merge = NULL;
        ListNode* first = NULL;
        
        while(list1!=NULL and list2!=NULL)
        {
            ListNode* temp;
            if(list1->val < list2->val)
            {
                temp = new ListNode(list1->val);
                list1 = list1->next;
            }else{
                temp = new ListNode(list2->val);
                list2 = list2->next;
            }
            if(merge == NULL)
            {    
                merge = temp;
                first = temp;
            }
            else{
                merge->next = temp;
                merge = temp;
            }
        }
        
        ListNode* temp = NULL;
        if(list1!=NULL)
        {
            temp = list1;
        }else if(list2!= NULL)
        {
            temp = list2;
        }
        
        if(merge == NULL)
        {
            merge = temp;
            first = temp;
        }else{
            merge->next = temp;
        }
        
        return first;
    }
};