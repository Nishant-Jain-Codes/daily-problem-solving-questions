/*
Problem
Chef has recently introduced a feature which allows you to open any user’s submitted code (not just your own), and ask an AI to explain that code in English. For example, you can go to https://www.codechef.com/viewsolution/70530506 and click on "Analyse This Code".

But there is a restriction that the feature works only on codes which are at most 10001000 characters long. Given the number of characters, CC, in a particular code, output whether the feature is available on this code or not.

Input Format
The only line of input will contain a single integer CC, denoting the number of characters in the code.

Output Format
Output a single line which contains either "Yes", if the feature is available on this code, or "No", if not.

You may print each character of the string in either uppercase or lowercase (for example, the strings NO, nO, No, and no will all be treated as identical).

Constraints
1 \leq C \leq 100001≤C≤10000
Sample 1:
Input
Output
50
Yes
Explanation:
The code's length is only 5050, and 50 \le 100050≤1000. So, the feature is available, and the answer is "Yes".

Sample 2:
Input
Output
1000
Yes
Explanation:
The code's length is 10001000, and 1000 \le 10001000≤1000. So, the feature is available, and the answer is "Yes".

Sample 3:
Input
Output
1001
No
Explanation:
The code's length is 10011001, and 1001 \nleq 10001001≰1000. So, the feature is not available, and the answer is "No".


*/

// solution 

void solution()
{
   int c;
   cin>>c;
   if(c<=1000)
    cout<<"YES";
    else 
    cout<<"NO";
}
