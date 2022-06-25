---
layout: post
title: remove-nth-node-from-end-of-list
date: 2022-06-25T14:20:30.516Z
---

```
19. Remove Nth Node From End of ListMediumGiven the head of a linked list, remove the nth node from the end of the list and return its head.

&nbsp;
Example 1:

Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]


Example 2:

Input: head = [1], n = 1
Output: []


Example 3:

Input: head = [1,2], n = 1
Output: [1]


&nbsp;
Constraints:


	The number of nodes in the list is sz.
	1 &lt;= sz &lt;= 30
	0 &lt;= Node.val &lt;= 100
	1 &lt;= n &lt;= sz


&nbsp;
Follow up: Could you do this in one pass?
 
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head;
        ListNode* front = head;
        
        while(n-- && fast!=NULL)
        {
            fast = fast->next;
        }
        
        if(fast == NULL)
        {
            front = NULL;
            return head->next;
        }
        
        while(fast->next!=NULL)
        {
            fast = fast->next;
            front = front->next;
        }
        
        if(front->next->next != NULL)
            front->next = front->next->next;
        else
            front->next = NULL;
        
        return head;
    }
    
}; 
```