---
layout: post
title: 116-populating-next-right-pointers-in-each-node
date: 2022-06-25T14:52:08.021Z
---

```
116. Populating Next Right Pointers in Each NodeMediumYou are given a perfect binary tree where all leaves are on the same level, and every parent has two children. The binary tree has the following definition:

struct Node  { 
  int val;
  Node *left;
  Node *right;
  Node *next;
 } 


Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

&nbsp;
Example 1:

Input: root = [1,2,3,4,5,6,7]
Output: [1,#,2,3,#,4,5,6,7,#]
Explanation: Given the above perfect binary tree (Figure A), your function should populate each next pointer to point to its next right node, just like in Figure B. The serialized output is in level order as connected by the next pointers, with '#' signifying the end of each level.


Example 2:

Input: root = []
Output: []


&nbsp;
Constraints:


	The number of nodes in the tree is in the range [0, 212 - 1].
	-1000 &lt;= Node.val &lt;= 1000


&nbsp;
Follow-up:


	You may only use constant extra space.
	The recursive approach is fine. You may assume implicit stack space does not count as extra space for this problem.

 
```

##Code
 ```
  /*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*> q;
        
        if(root == NULL)
            return root;
        
        q.push(root);
        
        while(!q.empty()){
            Node* t = q.front();
            q.pop();
            int k = q.size();
            
            if(t->left) q.push(t->left);
            if(t->right) q.push(t->right);

            while(k--){
                Node* r = q.front();
                q.pop();
                // cout<<t->val<<" - "<<r->val<<endl;
                t->next = r;
                t = r;
                if(r->left) q.push(r->left);                
                if(r->right) q.push(r->right);
                    
            }
        }
        
        return root;
    }
}; 
```
##NOTES.md
 ---
layout: post
title: 116-populating-next-right-pointers-in-each-node
date: 2022-06-25T14:52:08.021Z
---

```
​ 
```
