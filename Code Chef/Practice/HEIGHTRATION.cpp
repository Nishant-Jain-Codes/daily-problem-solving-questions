/*
Problem
In a recent breakthrough in mathematics, the proof utilized a concept called Height.

Consider a fraction \frac{a}{b} 
b
a
​
 . Its Height is defined as the maximum of its numerator and denominator. So, for example, the Height of \frac{3}{19} 
19
3
​
  would be 1919, and the Height of \frac{27}{4} 
4
27
​
  would be 2727.

Given aa and bb, find the Height of \frac{a}{b} 
b
a
​
 .

Input Format
The only line of input contains two integers, aa and bb.

Output Format
Output a single integer, which is the Height of \frac{a}{b} 
b
a
​
 .

Constraints
1 \leq a, b \leq 1001≤a,b≤100
aa and bb do not have any common factors.
Sample 1:
Input
Output
3 19
19
Explanation:
The maximum of \{3, 19\}{3,19} is 1919. Hence the Height of \frac{3}{19} 
19
3
​
  is 1919.

Sample 2:
Input
Output
27 4
27
Explanation:
The maximum of \{27, 4\}{27,4} is 2727. Hence the Height of \frac{27}{4} 
4
27
​
  is 2727.
*/
// solution 
void solution()
{
   int a,b;
   cin>>a>>b;
   cout<<max(a,b);
}
