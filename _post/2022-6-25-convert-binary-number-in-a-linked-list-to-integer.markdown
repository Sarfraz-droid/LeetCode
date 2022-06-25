---
layout: post
title: convert-binary-number-in-a-linked-list-to-integer
date: 2022-06-25T14:23:55.812Z
---

```
1290. Convert Binary Number in a Linked List to IntegerEasyGiven head which is a reference node to&nbsp;a singly-linked list. The value of each node in the linked list is either 0 or 1. The linked list holds the binary representation of a number.

Return the decimal value of the number in the linked list.

&nbsp;
Example 1:

Input: head = [1,0,1]
Output: 5
Explanation: (101) in base 2 = (5) in base 10


Example 2:

Input: head = [0]
Output: 0


Example 3:

Input: head = [1]
Output: 1


Example 4:

Input: head = [1,0,0,1,0,0,1,1,1,0,0,0,0,0,0]
Output: 18880


Example 5:

Input: head = [0,0]
Output: 0


&nbsp;
Constraints:


	The Linked List is not empty.
	Number of nodes&nbsp;will not exceed 30.
	Each node's value is either&nbsp;0 or 1.
 
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
    
    int pos;
    int num;
    
    void LtoIn(ListNode* head)
    {
        if(head == NULL)
            return;
        LtoIn(head->next);
        
        num += head->val*(1<<pos);
        pos++;

    }
    
    int getDecimalValue(ListNode* head) {
        pos = 0;
        num = 0;
        LtoIn(head);
        
        return num;
    }
}; 
```