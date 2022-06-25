---
layout: post
title: 92-reverse-linked-list-ii
date: 2022-06-25T14:52:08.099Z
---

```
92. Reverse Linked List IIMediumGiven the head of a singly linked list and two integers left and right where left &lt;= right, reverse the nodes of the list from position left to position right, and return the reversed list.

&nbsp;
Example 1:

Input: head = [1,2,3,4,5], left = 2, right = 4
Output: [1,4,3,2,5]


Example 2:

Input: head = [5], left = 1, right = 1
Output: [5]


&nbsp;
Constraints:


	The number of nodes in the list is n.
	1 &lt;= n &lt;= 500
	-500 &lt;= Node.val &lt;= 500
	1 &lt;= left &lt;= right &lt;= n


&nbsp;
Follow up: Could you do it in one pass? 
```

##Code
 ```
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
```
##NOTES.md
 ---
layout: post
title: 92-reverse-linked-list-ii
date: 2022-06-25T14:52:08.099Z
---

```
​ 
```
