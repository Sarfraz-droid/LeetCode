---
layout: post
title: 21-merge-two-sorted-lists
date: 2022-06-25T14:52:08.047Z
---

```
21. Merge Two Sorted ListsEasyYou are given the heads of two sorted linked lists list1 and list2.

Merge the two lists in a one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.

&nbsp;
Example 1:

Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]


Example 2:

Input: list1 = [], list2 = []
Output: []


Example 3:

Input: list1 = [], list2 = [0]
Output: [0]


&nbsp;
Constraints:


	The number of nodes in both lists is in the range [0, 50].
	-100 &lt;= Node.val &lt;= 100
	Both list1 and list2 are sorted in non-decreasing order.

 
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* merge = NULL;
        ListNode* first = NULL;
        
        while(list1!=NULL and list2!=NULL)
        {
            ListNode* temp;
            if(list1->val < list2->val)
            {
                temp = new ListNode(list1->val);
                list1 = list1->next;
            }else{
                temp = new ListNode(list2->val);
                list2 = list2->next;
            }
            if(merge == NULL)
            {    
                merge = temp;
                first = temp;
            }
            else{
                merge->next = temp;
                merge = temp;
            }
        }
        
        ListNode* temp = NULL;
        if(list1!=NULL)
        {
            temp = list1;
        }else if(list2!= NULL)
        {
            temp = list2;
        }
        
        if(merge == NULL)
        {
            merge = temp;
            first = temp;
        }else{
            merge->next = temp;
        }
        
        return first;
    }
}; 
```
##NOTES.md
 ---
layout: post
title: 21-merge-two-sorted-lists
date: 2022-06-25T14:52:08.047Z
---

```
​ 
```
