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
    ListNode* rotateRight(ListNode* head, int k) {
        int n = lengthOfList(head);
        if(n == 0)
            return NULL;
        if(n == 1)
            return head;
        int pos = n - k%n;
        if(pos == n)
        {
            return head;
        }
        ListNode* first = head;
        ListNode* temp = head;
        ListNode* start = head;
        while(temp->next!=NULL){
            pos--;
            if(pos == 0){
                ListNode* t = temp->next;
                start = t;
                temp->next = NULL;
                temp = t;
            }else{
                temp = temp->next;
            }
        }
        
        temp->next = head;
        return start;
    }
    
    int lengthOfList(ListNode* head){
        int n = 0;
        while(head!=NULL){
            n++;
            head = head->next;
        }
        
        return n;
    }
};