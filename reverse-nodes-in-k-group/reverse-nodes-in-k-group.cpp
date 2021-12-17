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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* h = head;
        ListNode* front = NULL;
        
        cout<<ListLen(head)<<"\n";
        while(head!= NULL)
        {
            ListNode* prev = NULL;
            int l = k;
            
            if(ListLen(head) < k)
            {
                front->next = head;
                print(h);
                return h;
            }
            
            while(l--)
            {
//                 if(head == NULL)
//                 {
                    
//                     front->next = prev;
//                     print(h);
//                     return h;
//                 }
                ListNode* temp = head;
                head = head->next;
                temp->next = prev;
                prev = temp;
            }
            
            
            
            if(front == NULL)
            {
                front = prev;
                h = prev;
            }else
            {
                front->next = prev;
            
            }
            while(front->next !=NULL)
            {
                front=front->next;
            }
            // print(front);
            // cout<<endl;
        }
        
        return h;
        
        
    }
    
    void print(ListNode* head){
        while(head!=NULL)
        {
            cout<<head->val<<",";
            head = head->next;
        }
    }
    
    int ListLen(ListNode* head){
        int l = 0;
        
        while(head!=NULL){
            l++;
            head=head->next;
        }
        
        return l;
    }
};