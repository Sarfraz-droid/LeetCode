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
                cout<<t->val<<" - "<<r->val<<endl;
                t->next = r;
                t = r;
                if(r->left) q.push(r->left);                
                if(r->right) q.push(r->right);
                    
            }
        }
        
        return root;
    }
};