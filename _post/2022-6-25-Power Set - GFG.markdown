---
layout: post
title: Power Set - GFG
date: 2022-06-25T14:23:55.793Z
---

```
# Power Set
## Easy 

                Given a string S find&nbsp;all possible subsequences&nbsp;of the string in lexicographically-sorted order.

Example 1:

Input : str = "abc"
Output: a ab abc ac b bc c
Explanation : There are 7 substrings that 
can be formed from abc.


Example 2:

Input: str = "aa"
Output: a a aa
Explanation : There are 3 substrings that 
can be formed from aa.


Your Task:
You don't need to read ot print anything. Your task is to complete the function&nbsp;AllPossibleStrings()&nbsp;which takes S as input parameter and returns a list of all possible substrings(non-empty) that can be formed from S in lexicographically-sorted order.
&nbsp;

Expected Time Complexity:&nbsp;O(2n) where n is the length of the string
Expected Space Complexity :&nbsp;O(n * 2n)
&nbsp;

Constraints:&nbsp;
1 &lt;= Length of string &lt;= 16
 
             
```

##Code
 ```
  // { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
		vector<string> AllPossibleStrings(string s){
		    // Code here
		    string curr;
		    vector<string> ans;
		    
		    Permute(ans,curr,s,0);

            sort(ans.begin(),ans.end());
		    return ans;
		}
		
		void Permute(vector<string> &ans,string curr,string s,int pos){
		    if(curr.size() > 0)
		        ans.push_back(curr);
		        
		    for(int i = pos;i<s.size();i++){
		        curr.push_back(s[i]);
		        Permute(ans,curr,s,i+1);
		        curr.pop_back();
		    }
		}
		
		
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}  // } Driver Code Ends 
```