---
layout: post
title: Fractional Knapsack - GFG
date: 2022-06-25T14:23:55.790Z
---

```
# Fractional Knapsack
## Medium 

                Given weights and values of N items, we need to put these items in a knapsack of capacity W to get the maximum total value in the knapsack.
Note: Unlike 0/1 knapsack, you are allowed to break&nbsp;the item.&nbsp;

&nbsp;

Example 1:

Input:
N = 3, W = 50
values[] =  { 60,100,120 } 
weight[] =  { 10,20,30 } 
Output:
240.00
Explanation:Total maximum value of item
we can have is 240.00 from the given
capacity of sack. 


Example 2:

Input:
N = 2, W = 50
values[] =  { 60,100 } 
weight[] =  { 10,20 } 
Output:
160.00
Explanation:
Total maximum value of item
we can have is 160.00 from the given
capacity of sack.

&nbsp;

Your Task :
Complete the function&nbsp;fractionalKnapsack() that receives maximum capacity , array of structure/class&nbsp;and size n and returns a double value representing the maximum value in knapsack.
Note:&nbsp;The details of structure/class is defined in the comments above the given function.


Expected Time Complexity : O(NlogN)
Expected Auxilliary Space: O(1)


Constraints:
1 &lt;= N &lt;= 105
1 &lt;= W &lt;= 105
 
             
```

##Code
 ```
  // { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


 // } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
   public:
   
   static bool comp(Item p1,Item p2){
       double v1 = (double)p1.value/(double)p1.weight;
       double v2 = (double)p2.value/(double)p2.weight;
       return v1 > v2;
   }
   
   //Function to get the maximum total value in the knapsack.
   double fractionalKnapsack(int W, Item arr[], int n)
   {
       sort(arr,arr+n,comp);
   double ans = 0;
       for(int i=0;i<n;i++){
           if(W>=arr[i].weight){
               ans+=arr[i].value;
               W-=arr[i].weight;
               continue;
           }
           double vw = (double)arr[i].value/(double)arr[i].weight;
           ans+=vw*W;
           W=0;
           break;
       }
       return ans;
   }
       
};

// { Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}  // } Driver Code Ends 
```