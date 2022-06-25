---
layout: post
title: Nth node from end of linked list - GFG
date: 2022-06-25T14:52:08.105Z
---

```
# Nth node from end of linked list
## Easy 

                Given a linked list consisting of L nodes and given a number N. The task is to find the Nth node from the end of the linked list.

Example 1:

Input:
N = 2
LinkedList: 1-&gt;2-&gt;3-&gt;4-&gt;5-&gt;6-&gt;7-&gt;8-&gt;9
Output: 8
Explanation: In the first example, there
are 9 nodes in linked list and we need
to find 2nd node from end.&nbsp;2nd node
from end os 8.&nbsp;&nbsp;


Example 2:

Input:
N = 5
LinkedList: 10-&gt;5-&gt;100-&gt;5
Output: -1
Explanation: In the second example, there
are 4 nodes in the linked list and we
need to find 5th from the end.&nbsp;Since 'n'
is more than the number of nodes in the
linked list, the output is -1.

Your Task:
The task is to complete the function getNthFromLast() which takes two arguments: reference to head and N and you need to return Nth from the end or -1 in case node doesn't exist..

Note:
Try to solve in single traversal.

Expected Time Complexity:&nbsp;O(N).
Expected Auxiliary Space:&nbsp;O(1).

Constraints:
1 &lt;= L &lt;= 106
1 &lt;= N &lt;= 106
 
             
```

##Code
 ```
  // { Driver Code Starts
// C program to find n'th Node in linked list
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;

/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};


/* Function to get the nth node from the last of a linked list*/
int getNthFromLast(struct Node* head, int n);



/* Driver program to test above function*/
int main()
{
  int T,i,n,l,k;

    cin>>T;

    while(T--){
    struct Node *head = NULL,  *tail = NULL;

        cin>>n>>k;
        int firstdata;
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }

    cout<<getNthFromLast(head, k)<<endl;
    }
    return 0;
}// } Driver Code Ends


/* struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

//Function to find the data of nth node from the end of a linked list.

int Calc_Len(Node *x)
{
    int n = 0;
    while(x != NULL)
    {
        x = x->next;
        n++;
    }
    return n;
}
int getNthFromLast(Node *head, int n)
{
    int ans = -1;
    n = Calc_Len(head) -n;
    while(head!=NULL and n>=0)
    {
        
        ans = head->data;
        if(head!=NULL)
            head = head->next;
        n--;
        
    }
    
    return ans;
}
 
```