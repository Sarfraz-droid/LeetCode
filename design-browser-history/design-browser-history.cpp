class node{
public:
    string val;
    node* back;
    node* next;
    
    node(string obj)
    {
        val = obj;
        back = NULL;
        next = NULL;
    }
};

class BrowserHistory {
public:
    node* head;
    BrowserHistory(string homepage) {
        head = new node(homepage);
    }
    
    void visit(string url) {
        node* temp = new node(url);
        head->next = temp;
        temp->back = head;
        cout<<head->val<<" "<<head->next->val<<endl;
        head = temp;
        
    }
    
    string back(int steps) {
        while(steps--)
        {
            if(head->back == NULL)
                return head->val;
            head = head->back;
        }
        return head->val;
    }
    
    string forward(int steps) {
        while(steps--)
        {
            if(head->next == NULL)
                return head->val;
            head = head->next;
        }
        
        if(head == NULL)
            return "";
        else
            return head->val;
        
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */