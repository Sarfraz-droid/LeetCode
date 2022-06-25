---
layout: post
title: remove-linked-list-elements
date: 2022-06-25T14:52:08.147Z
---

```
203. Remove Linked List ElementsEasyGiven the head of a linked list and an integer val, remove all the nodes of the linked list that has Node.val == val, and return the new head.

&nbsp;
Example 1:

Input: head = [1,2,6,3,4,5,6], val = 6
Output: [1,2,3,4,5]


Example 2:

Input: head = [], val = 1
Output: []


Example 3:

Input: head = [7,7,7,7], val = 7
Output: []


&nbsp;
Constraints:


	The number of nodes in the list is in the range [0, 104].
	1 &lt;= Node.val &lt;= 50
	0 &lt;= val &lt;= 50

 
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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* pre = NULL;
        ListNode* front = head;
        
        while(head!=NULL)
        {
            if(head->val == val)
            {
                if(pre == NULL)
                {
                    front = front->next;
                    head = head->next;
                }
                else
                {   
                    pre->next = head->next;
                    // pre = head;
                    head = head->next;

                }
            }else
            {
                pre = head;
                head = head->next;

            }
            
        }
        
        
        return front;
    }
}; 
```