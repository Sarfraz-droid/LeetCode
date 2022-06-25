---
layout: post
title: design-browser-history
date: 2022-06-25T14:20:30.442Z
---

```
1472. Design Browser HistoryMediumYou have a browser of one tab where you start on the homepage and you can visit another url, get back in the history number of steps or move forward in the history number of steps.

Implement the BrowserHistory class:


	BrowserHistory(string homepage) Initializes the object with the homepage&nbsp;of the browser.
	void visit(string url)&nbsp;Visits&nbsp;url from the current page. It clears up all the forward history.
	string back(int steps)&nbsp;Move steps back in history. If you can only return x steps in the history and steps &gt; x, you will&nbsp;return only x steps. Return the current url&nbsp;after moving back in history at most steps.
	string forward(int steps)&nbsp;Move steps forward in history. If you can only forward x steps in the history and steps &gt; x, you will&nbsp;forward only&nbsp;x steps. Return the current url&nbsp;after forwarding in history at most steps.


&nbsp;
Example:

Input:
["BrowserHistory","visit","visit","visit","back","back","forward","visit","forward","back","back"]
[["leetcode.com"],["google.com"],["facebook.com"],["youtube.com"],[1],[1],[1],["linkedin.com"],[2],[2],[7]]
Output:
[null,null,null,null,"facebook.com","google.com","facebook.com",null,"linkedin.com","google.com","leetcode.com"]

Explanation:
BrowserHistory browserHistory = new BrowserHistory("leetcode.com");
browserHistory.visit("google.com");       // You are in "leetcode.com". Visit "google.com"
browserHistory.visit("facebook.com");     // You are in "google.com". Visit "facebook.com"
browserHistory.visit("youtube.com");      // You are in "facebook.com". Visit "youtube.com"
browserHistory.back(1);                   // You are in "youtube.com", move back to "facebook.com" return "facebook.com"
browserHistory.back(1);                   // You are in "facebook.com", move back to "google.com" return "google.com"
browserHistory.forward(1);                // You are in "google.com", move forward to "facebook.com" return "facebook.com"
browserHistory.visit("linkedin.com");     // You are in "facebook.com". Visit "linkedin.com"
browserHistory.forward(2);                // You are in "linkedin.com", you cannot move forward any steps.
browserHistory.back(2);                   // You are in "linkedin.com", move back two steps to "facebook.com" then to "google.com". return "google.com"
browserHistory.back(7);                   // You are in "google.com", you can move back only one step to "leetcode.com". return "leetcode.com"


&nbsp;
Constraints:


	1 &lt;= homepage.length &lt;= 20
	1 &lt;= url.length &lt;= 20
	1 &lt;= steps &lt;= 100
	homepage and url consist of&nbsp; '.' or lower case English letters.
	At most 5000&nbsp;calls will be made to visit, back, and forward.

 
```

##Code
 ```
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
```