---
layout: post
title: 449-serialize-and-deserialize-bst
date: 2022-06-25T14:28:05.026Z
---

```
449. Serialize and Deserialize BSTMediumSerialization is converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary search tree. There is no restriction on how your serialization/deserialization algorithm should work. You need to ensure that a binary search tree can be serialized to a string, and this string can be deserialized to the original tree structure.

The encoded string should be as compact as possible.

&nbsp;
Example 1:
Input: root = [2,1,3]
Output: [2,1,3]
Example 2:
Input: root = []
Output: []

&nbsp;
Constraints:


	The number of nodes in the tree is in the range [0, 104].
	0 &lt;= Node.val &lt;= 104
	The input tree is guaranteed to be a binary search tree.

 
```

##Code
 ```
  /**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    
    
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        
        queue<TreeNode*> q;
        
        q.push(root);
        string ans = "";
        while(!q.empty()){
            TreeNode* f = q.front();
            q.pop();
            
            if(f == NULL)
            {
                ans+="n-";
                continue;
            }
            ans+= to_string(f->val)+"-";
            q.push(f->left);
            q.push(f->right);
        }
        // mp[ans] = root;
        
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        
        if(data[0] == 'n')
            return NULL;
        
        int i = 0;
        string _s = "";
        
        while(data[i] != '-'){
            _s += data[i];
            i++;
        }
        
        i++;
        
        TreeNode* root = new TreeNode(stoi(_s));
        queue<TreeNode*> q;
        
        q.push(root);
        while(!q.empty() and i < data.size()){
            TreeNode* f = q.front();
            q.pop();
            
            TreeNode* l = NULL;
            TreeNode* r = NULL;
            
            string l_val = "";
            while(data[i] != '-'){
                l_val += data[i];
                i++;
            }
            i++;
            
            string r_val = "";
            while(data[i] != '-'){
                r_val += data[i];
                i++;
            }
            i++;
            
            if(l_val != "n"){
                // cout<<l_val<<" ";
                l = new TreeNode(stoi(l_val));
            }
            if(r_val != "n"){
                // cout<<r_val<<" ";
                r = new TreeNode(stoi(r_val));
            }
            f->left = l;
            f->right = r;
            if(l)
                q.push(l);
            
            if(r)
                q.push(r);
            // i+=2;
        }
            
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans; 
```
##NOTES.md
 ---
layout: post
title: 449-serialize-and-deserialize-bst
date: 2022-06-25T14:28:05.026Z
---

```
​ 
```
