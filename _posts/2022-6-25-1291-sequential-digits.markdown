---
layout: post
title: 1291-sequential-digits
date: 2022-06-25T14:20:30.297Z
---

```
1291. Sequential DigitsMediumAn&nbsp;integer has sequential digits if and only if each digit in the number is one more than the previous digit.

Return a sorted list of all the integers&nbsp;in the range [low, high]&nbsp;inclusive that have sequential digits.

&nbsp;
Example 1:
Input: low = 100, high = 300
Output: [123,234]
Example 2:
Input: low = 1000, high = 13000
Output: [1234,2345,3456,4567,5678,6789,12345]

&nbsp;
Constraints:


	10 &lt;= low &lt;= high &lt;= 10^9

 
```

##Code
 ```
  class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        int low_n = to_string(low).size();
        int high_n = to_string(high).size();
        string str = "123456789";
        vector<int> ans;
        for(int i = low_n;i<= high_n;i++){
            cout<<i<<" ";
             for(int j = 0;j<(str.size() - i+1);j++){
                 string s = str.substr(j,i);
                 int num = stoi(s);
                 cout<<num<<" ";
                 
                 if(num >= low and num <= high){
                     ans.push_back(num);
                 }
             }
            cout<<endl;
        }
        
        return ans;
    }
}; 
```
##NOTES.md
 ---
layout: post
title: 1291-sequential-digits
date: 2022-06-25T14:20:30.297Z
---

```
​ 
```
