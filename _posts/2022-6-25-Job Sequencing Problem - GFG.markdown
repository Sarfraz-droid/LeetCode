---
layout: post
title: Job Sequencing Problem - GFG
date: 2022-06-25T14:52:08.104Z
---

```
# Job Sequencing Problem
## Medium 

                Given a set of N jobs where each jobi&nbsp;has a deadline and profit associated with it. 

Each job takes 1 unit of time to complete and only one job can be scheduled at a time. We earn the profit associated with job if and only if the job is completed by its deadline. 

Find the number of jobs done and the&nbsp;maximum profit.

Note: Jobs will be given in the form (Jobid, Deadline,&nbsp;Profit) associated with that Job.


Example 1:

Input:
N = 4
Jobs =  { (1,4,20),(2,1,10),(3,1,40),(4,1,30) } 
Output:
2 60
Explanation:
Job1&nbsp;and Job3 can be done with
maximum profit of 60 (20+40).


Example 2:

Input:
N = 5
Jobs =  { (1,2,100),(2,1,19),(3,2,27),
&nbsp;       (4,1,25),(5,1,15) } 
Output:
2 127
Explanation:
2 jobs can be done with
maximum profit of 127 (100+27).


Your Task :
You don't need to read input or print anything. Your task is to complete the function JobScheduling() which takes an integer N and an array of Jobs(Job id, Deadline,&nbsp;Profit) as input and returns the count of jobs and maximum profit.


Expected Time Complexity: O(NlogN)
Expected Auxilliary Space: O(N)


Constraints:
1 &lt;= N &lt;= 105
1 &lt;= Deadline &lt;= 100
1 &lt;= Profit &lt;= 500
 
             
```

##Code
 ```
  // { Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


 // } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    
    static bool customsort(Job &a,Job &b){
        return a.profit > b.profit;

    }
    
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        int n_job = 0,profit = 0;
        
        sort(arr,arr+n,customsort);

        vector<bool> acc(101);
        
        for(int i = 0;i<n;i++){
            for(int j = arr[i].dead;j>0;j--){
                if(acc[j] == false){
                    acc[j] = true;
                    n_job++;
                    profit+= arr[i].profit;
                    break;
                }
            }
        }
    
        return {n_job,profit};
    } 
};

// { Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}


  // } Driver Code Ends 
```