---
layout: post
title: iterator-for-combination
date: 2022-06-25T14:20:30.449Z
---

```
[Discussion Post (created on 14/10/2021 at 14:25)](https://leetcode.com/problems/iterator-for-combination/discuss/1577530/C%2B%2B-Recursive-Approach-oror-99.95-faster-oror-Detailed-Explanation)  
1286. Iterator for CombinationMediumDesign the CombinationIterator class:


	CombinationIterator(string characters, int combinationLength)&nbsp;Initializes the object with&nbsp;a string&nbsp;characters&nbsp;of sorted distinct lowercase English letters and a number&nbsp;combinationLength as arguments.
	next()&nbsp;Returns the next combination of length combinationLength&nbsp;in lexicographical order.
	hasNext()&nbsp;Returns true&nbsp;if and only if&nbsp;there exists a next combination.


&nbsp;
Example 1:

Input
["CombinationIterator", "next", "hasNext", "next", "hasNext", "next", "hasNext"]
[["abc", 2], [], [], [], [], [], []]
Output
[null, "ab", true, "ac", true, "bc", false]

Explanation
CombinationIterator itr = new CombinationIterator("abc", 2);
itr.next();    // return "ab"
itr.hasNext(); // return True
itr.next();    // return "ac"
itr.hasNext(); // return True
itr.next();    // return "bc"
itr.hasNext(); // return False


&nbsp;
Constraints:


	1 &lt;= combinationLength &lt;=&nbsp;characters.length &lt;= 15
	All the characters of characters are unique.
	At most 104&nbsp;calls will be made to next and hasNext.
	It's guaranteed that all&nbsp;calls&nbsp;of the function next&nbsp;are valid.

 
```

##Code
 ```
  struct Node{
    string val;
    Node* next;
};


class CombinationIterator {
    string str;
    int length;
    int curr = -1;
    int comb_len;
    vector<string> combinations;
public:
    CombinationIterator(string characters, int combinationLength) {
        str  = characters;
        length = combinationLength;
        
        generateCombinations("",0);
        curr = -1;
        comb_len = combinations.size();
    }
    
    
    string next() {
        if(curr == comb_len - 1)
        {
            return "";
        }
        
        curr++;
        
        return combinations[curr];
    }
    
    bool hasNext() {
        return curr != comb_len -1;
    }
    
    void generateCombinations(string current,int pos){
        if(current.size() == length)
        {
            cout<<current<<"\n";
            combinations.push_back(current);
            return;
        }
        
        for(int i = pos;i<str.size();i++)
        {
            current.push_back(str[i]);
            generateCombinations(current,i+1);
            current.pop_back();
        }
        
    }
};



/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */ 
```