---
layout: post
title: different-ways-to-add-parentheses
date: 2022-06-25T14:20:30.443Z
---

```
241. Different Ways to Add ParenthesesMediumGiven a string expression of numbers and operators, return all possible results from computing all the different possible ways to group numbers and operators. You may return the answer in any order.

&nbsp;
Example 1:

Input: expression = "2-1-1"
Output: [0,2]
Explanation:
((2-1)-1) = 0 
(2-(1-1)) = 2


Example 2:

Input: expression = "2*3-4*5"
Output: [-34,-14,-10,-10,10]
Explanation:
(2*(3-(4*5))) = -34 
((2*3)-(4*5)) = -14 
((2*(3-4))*5) = -10 
(2*((3-4)*5)) = -10 
(((2*3)-4)*5) = 10


&nbsp;
Constraints:


	1 &lt;= expression.length &lt;= 20
	expression consists of digits and the operator '+', '-', and '*'.
	All the integer values in the input expression are in the range [0, 99].

 
```

##Code
 ```
  class Solution {
public:
    int toInt(string s) {
        
        int sum = 0;
        for (auto t : s) {
            sum = sum * 10 + (t - '0');
        }
        return sum;
    } 
    
    vector<int> diffWaysToCompute(string &input) {
        
        vector<int> answer;
        for (int i = 0; i < input.size(); i++) {
            if (input[i] == '-' ||
                input[i]  == '*' ||
                input[i]  == '+' ) {
                string part1 = input.substr(0, i);
                string part2 = input.substr(i + 1);
                vector<int> part1Ret = diffWaysToCompute(part1);
                vector<int> part2Ret = diffWaysToCompute(part2);
                for (auto p1 :   part1Ret) {
                    for (auto p2 :   part2Ret) {
                        int sum = 0;
                        switch (input[i]) {
                            case '+': sum = p1 + p2;
                                break;
                            case '-': sum = p1 - p2;
                                break;
                            case '*': sum = p1 * p2;
                                break;
                        }
                        answer.push_back(sum);
                    }
                }
            }
        }
        if (answer.size() == 0) {
            answer.push_back(toInt(input));
        }
        sort(answer.begin(), answer.end());
        return answer;
    }
}; 
```