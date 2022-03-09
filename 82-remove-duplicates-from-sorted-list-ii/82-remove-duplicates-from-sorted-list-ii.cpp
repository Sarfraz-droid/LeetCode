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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* root = new ListNode();
        ListNode* front = root;
      
        if(head == NULL){
            return head;
        }
        
        ListNode* prev = head;
        head = head->next;
    
        
        while(head != NULL){
            
            if(prev == NULL or head == NULL)
                break;
            
            if(head->val == prev->val){
                // cout<<"\nFOUND SAME : "<<head->val<<" "<<prev->val<<" ";
                while(head!=NULL and head->val == prev->val){
                    head = head->next;
                }
                
                if(head == NULL)
                {
                    prev = NULL;
                    break;
                }
                prev = head;
                head = prev->next;
                // if(head!=NULL and prev!=NULL)
                //     cout<<prev->val<<" - "<<head->val<<endl;
            }else{
                ListNode* temp = new ListNode(prev->val);
                
                root->next = temp;
                root = temp;
                
                prev= head;
                head=head->next;
            }
        }
        
        if(prev!= NULL){
            ListNode* temp = new ListNode(prev->val);
            root->next = temp;
            root = temp;
        }
        
        return front->next;
    }
};