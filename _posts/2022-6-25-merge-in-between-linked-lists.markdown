---
layout: post
title: merge-in-between-linked-lists
date: 2022-06-25T14:28:05.082Z
---

```
1669. Merge In Between Linked ListsMediumYou are given two linked lists: list1 and list2 of sizes n and m respectively.

Remove list1's nodes from the ath node to the bth node, and put list2 in their place.

The blue edges and nodes in the following figure incidate the result:

Build the result list and return its head.

&nbsp;
Example 1:

Input: list1 = [0,1,2,3,4,5], a = 3, b = 4, list2 = [1000000,1000001,1000002]
Output: [0,1,2,1000000,1000001,1000002,5]
Explanation: We remove the nodes 3 and 4 and put the entire list2 in their place. The blue edges and nodes in the above figure indicate the result.


Example 2:

Input: list1 = [0,1,2,3,4,5,6], a = 2, b = 5, list2 = [1000000,1000001,1000002,1000003,1000004]
Output: [0,1,1000000,1000001,1000002,1000003,1000004,6]
Explanation: The blue edges and nodes in the above figure indicate the result.


&nbsp;
Constraints:


	3 &lt;= list1.length &lt;= 104
	1 &lt;= a &lt;= b &lt; list1.length - 1
	1 &lt;= list2.length &lt;= 104

 
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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* head2 = list2;
        ListNode* head = new ListNode(list1->val);
        ListNode* front = head;
        list1 = list1->next;
        int i = 1;
        
        while(list2->next!=NULL)
        {
            list2 = list2->next;
        }
        
        bool found = false;
        while(list1 != NULL)
        {       
            cout<<list1->val<<" ";
            if(i == a)
            {
                front->next = head2;
                front = list2;
                while(i != b)
                {    
                    list1 = list1->next;
                    i++;
                }
                // cout<<list1->val<<" ";
            }else
            {
                front->next = new ListNode(list1->val);
                front = front->next;
            }
            i++;
            
            list1 = list1->next;
        }
        
        return head;
        
    }
}; 
```