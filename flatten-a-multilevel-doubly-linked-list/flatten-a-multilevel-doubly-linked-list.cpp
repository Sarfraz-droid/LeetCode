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