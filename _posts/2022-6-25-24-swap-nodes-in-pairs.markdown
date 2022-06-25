---
layout: post
title: 24-swap-nodes-in-pairs
date: 2022-06-25T14:20:30.333Z
---

```
24. Swap Nodes in PairsMediumGiven a&nbsp;linked list, swap every two adjacent nodes and return its head. You must solve the problem without&nbsp;modifying the values in the list's nodes (i.e., only nodes themselves may be changed.)

&nbsp;
Example 1:

Input: head = [1,2,3,4]
Output: [2,1,4,3]


Example 2:

Input: head = []
Output: []


Example 3:

Input: head = [1]
Output: [1]


&nbsp;
Constraints:


	The number of nodes in the&nbsp;list&nbsp;is in the range [0, 100].
	0 &lt;= Node.val &lt;= 100

 
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
    ListNode* swapPairs(ListNode* head) {
        
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        if(head == NULL or head->next == NULL)
            return head;
        
     
        
        ListNode* t = swapPairs(head->next->next);
        ListNode* temp = head->next;
        
        head->next = t;
        temp->next = head;

        
        return temp;
    }
}; 
```
##NOTES.md
 ---
layout: post
title: 24-swap-nodes-in-pairs
date: 2022-06-25T14:20:30.333Z
---

```
​ 
```
