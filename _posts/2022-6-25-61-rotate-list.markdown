---
layout: post
title: 61-rotate-list
date: 2022-06-25T14:20:30.402Z
---

```
61. Rotate ListMediumGiven the head of a linked&nbsp;list, rotate the list to the right by k places.

&nbsp;
Example 1:

Input: head = [1,2,3,4,5], k = 2
Output: [4,5,1,2,3]


Example 2:

Input: head = [0,1,2], k = 4
Output: [2,0,1]


&nbsp;
Constraints:


	The number of nodes in the list is in the range [0, 500].
	-100 &lt;= Node.val &lt;= 100
	0 &lt;= k &lt;= 2 * 109

 
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
    ListNode* rotateRight(ListNode* head, int k) {
        int n = lengthOfList(head);
        if(n == 0)
            return NULL;
        else if(n == 1)
            return head;
        int pos = n - k%n;
        if(pos == n)
        {
            return head;
        }
        ListNode* first = head;
        ListNode* temp = head;
        ListNode* start = head;
        while(temp->next!=NULL){
            pos--;
            if(pos == 0){
                ListNode* t = temp->next;
                start = t;
                temp->next = NULL;
                temp = t;
            }else{
                temp = temp->next;
            }
        }
        
        temp->next = head;
        return start;
    }
    
    int lengthOfList(ListNode* head){
        int n = 0;
        while(head!=NULL){
            n++;
            head = head->next;
        }
        
        return n;
    }
}; 
```
##NOTES.md
 ---
layout: post
title: 61-rotate-list
date: 2022-06-25T14:20:30.402Z
---

```
​ 
```
