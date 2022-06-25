---
layout: post
title: 82-remove-duplicates-from-sorted-list-ii
date: 2022-06-25T14:52:08.096Z
---

```
82. Remove Duplicates from Sorted List IIMediumGiven the head of a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list. Return the linked list sorted as well.

&nbsp;
Example 1:

Input: head = [1,2,3,3,4,4,5]
Output: [1,2,5]


Example 2:

Input: head = [1,1,1,2,3]
Output: [2,3]


&nbsp;
Constraints:


	The number of nodes in the list is in the range [0, 300].
	-100 &lt;= Node.val &lt;= 100
	The list is guaranteed to be sorted in ascending order.

 
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
```