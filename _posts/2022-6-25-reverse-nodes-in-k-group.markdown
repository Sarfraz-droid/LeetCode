---
layout: post
title: reverse-nodes-in-k-group
date: 2022-06-25T14:28:05.117Z
---

```
25. Reverse Nodes in k-GroupHardGiven the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

You may not alter the values in the list's nodes, only nodes themselves may be changed.

&nbsp;
Example 1:

Input: head = [1,2,3,4,5], k = 2
Output: [2,1,4,3,5]


Example 2:

Input: head = [1,2,3,4,5], k = 3
Output: [3,2,1,4,5]


&nbsp;
Constraints:


	The number of nodes in the list is n.
	1 &lt;= k &lt;= n &lt;= 5000
	0 &lt;= Node.val &lt;= 1000


&nbsp;
Follow-up: Can you solve the problem in O(1) extra memory space?
 
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
```