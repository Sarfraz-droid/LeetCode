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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
        if(left == right)
            return head;
        
        ListNode* front = head;
        int count = 0;
        ListNode* r1 = NULL;
        ListNode* r2 = NULL;
        ListNode* l1 = NULL;
        ListNode* l2 = NULL;
        
        while(head != NULL){
            count++;
            if((count) == (left-1)){
                r1 = head;
            }
            
            if(count == left){
                r2 = head;
            }
            
            if(count == (right+1)){
                l2 = head;
            }
            
            if(count == right)
                l1 = head;
            
            head = head->next;
        }
        
        
        if(r1 == NULL and l2 == NULL)
        {
            ListNode* prev = NULL;   
            while(r2 != l1){
            
                ListNode* temp = r2->next;
                r2->next = prev;
                prev = r2;
                r2 = temp;
            }
            
            l1->next = prev;
            
            return l1;
        }else if(r1 == NULL){
            
            ListNode* prev = NULL;   
            
            ListNode* rev = r2;
            
            while(r2 != l1){            
                ListNode* temp = r2->next;
                r2->next = prev;
                prev = r2;
                r2 = temp;
            }
            
            l1->next = prev;
            
            rev->next = l2;
            
            return l1;
        }
        
        // cout<<r1->val<<" "<<r2->val<<"\n";
        // cout<<l1->val<<" "<<l2->val<<"\n";
        ListNode* rev = r2;
        ListNode* prev = NULL;
        while(rev != l1){
            
            ListNode* temp = rev->next;
            rev->next = prev;
            prev = rev;
            rev = temp;
        }
        
        l1->next = prev;
     
        PrintList(front); 
        PrintList(l1);
        
        // cout<<r1->val<<" "<<r2->val<<"\n";
        // cout<<l1->val<<" "<<l2->val<<"\n";
        
        r1->next = l1;
        PrintList(front);
        
        r2->next = l2;
        PrintList(front);

        
        return front;
        
    }
    
    void PrintList(ListNode* list){
        while(list!= NULL){
            cout<<list->val<<" ";
            
            list= list->next;
        }
        
        cout<<endl;
    }
    
    
    
    
};