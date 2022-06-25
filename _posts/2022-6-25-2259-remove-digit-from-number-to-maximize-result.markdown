---
layout: post
title: 2259-remove-digit-from-number-to-maximize-result
date: 2022-06-25T14:28:04.976Z
---

```
2259. Remove Digit From Number to Maximize ResultEasyYou are given a string number representing a positive integer and a character digit.

Return the resulting string after removing exactly one occurrence of digit from number such that the value of the resulting string in decimal form is maximized. The test cases are generated such that digit occurs at least once in number.

&nbsp;
Example 1:

Input: number = "123", digit = "3"
Output: "12"
Explanation: There is only one '3' in "123". After removing '3', the result is "12".


Example 2:

Input: number = "1231", digit = "1"
Output: "231"
Explanation: We can remove the first '1' to get "231" or remove the second '1' to get "123".
Since 231 &gt; 123, we return "231".


Example 3:

Input: number = "551", digit = "5"
Output: "51"
Explanation: We can remove either the first or second '5' from "551".
Both result in the string "51".


&nbsp;
Constraints:


	2 &lt;= number.length &lt;= 100
	number consists of digits from '1' to '9'.
	digit is a digit from '1' to '9'.
	digit occurs at least once in number.

 
```

##Code
 ```
  class Solution {
public:
    string removeDigit(string number, char digit) {
        int index_to_del = -1;
        string before = "";
        int n = number.size();
        for(int i = 0;i<n;i++){
            if(number[i] == digit){
                if(before == ""){
                    before = number;
                    before.erase(i,1);
                }else{
                    string str = number;
                    str.erase(i,1);
                    
                    if(str > before){
                        before = str;
                    }
                }
            }
        }
        
        return before;
    }
}; 
```