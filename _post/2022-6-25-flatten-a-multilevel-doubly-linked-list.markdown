---
layout: post
title: flatten-a-multilevel-doubly-linked-list
date: 2022-06-25T14:23:55.817Z
---

```
430. Flatten a Multilevel Doubly Linked ListMediumYou are given a doubly linked list which in addition to the next and previous pointers, it could have a child pointer, which may or may not point to a separate doubly linked list. These child lists may have one or more children of their own, and so on, to produce a multilevel data structure, as shown in the example below.

Flatten the list so that all the nodes appear in a single-level, doubly linked list. You are given the head of the first level of the list.

&nbsp;
Example 1:

Input: head = [1,2,3,4,5,6,null,null,null,7,8,9,10,null,null,11,12]
Output: [1,2,3,7,8,11,12,9,10,4,5,6]
Explanation:

The multilevel linked list in the input is as follows:



After flattening the multilevel linked list it becomes:




Example 2:

Input: head = [1,2,null,3]
Output: [1,3,2]
Explanation:

The input multilevel linked list is as follows:

  1---2---NULL
  |
  3---NULL


Example 3:

Input: head = []
Output: []


&nbsp;

How&nbsp;multilevel linked list is represented in test case:

We use the&nbsp;multilevel linked list from Example 1 above:

 1---2---3---4---5---6--NULL
         |
         7---8---9---10--NULL
             |
             11--12--NULL

The serialization of each level is as follows:

[1,2,3,4,5,6,null]
[7,8,9,10,null]
[11,12,null]


To serialize all levels together we will add nulls in each level to signify no node connects to the upper node of the previous level. The serialization becomes:

[1,2,3,4,5,6,null]
[null,null,7,8,9,10,null]
[null,11,12,null]


Merging the serialization of each level and removing trailing nulls we obtain:

[1,2,3,4,5,6,null,null,null,7,8,9,10,null,null,11,12]

&nbsp;
Constraints:


	The number of Nodes will not exceed 1000.
	1 &lt;= Node.val &lt;= 105

 
```

##Code
 ```
  /*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        Node* front = head;
        
        if(head == NULL)
        {
            return NULL;
        }
        
        while(head != NULL)
        {
            Node* child= NULL;
            
            Node* nexthead = head->next;
            Node* temp = head;
            
            if(temp->child != NULL)
            {
                child = flatten(temp->child);
            }
        
            if(child != NULL)
            {
                // cout<<child->val<<" "<<temp->val<<"\n";
                
                temp->next = child;
                child->prev = temp;
                
                while(child->next != NULL)
                    child = child->next;
                
                child->next = nexthead;
                if(nexthead != NULL)
                    nexthead->prev = child;

            }
                
            head->child = NULL;
                
            head = nexthead;
        }
        
//         Node* checknext = front;
//         while(checknext!=NULL)
//         {
//             cout<<checknext->val<<" ";
//             checknext = checknext->next;
//         }
//         cout<<endl;
        
        
        
//         Node* checkback = head;
//         while(checkback!= NULL)
//         {
//             cout<<checkback->val<<" ";
//             checkback = checkback->prev;
//         }
        
//         cout<<endl;

        
        
        
        return front;
        
    }
}; 
```