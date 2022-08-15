/*
Problem
You are given a positive integer XX. Your task is to tell whether there exist two positive integers aa and bb (a \gt 0, b \gt 0)(a>0,b>0) such that

2\cdot a + 2\cdot b + a\cdot b = X
2⋅a+2⋅b+a⋅b=X
If there exist positive integers aa and bb satisfying the above condition print YES, otherwise print NO.

Input Format
The first line of input will contain a single integer TT, denoting the number of test cases.
Each test case consists of single line containing a positive integer XX.
Output Format
For each test case, output on a new line YES or NO.

You may print each character of the string in either uppercase or lowercase (for example, the strings yes, YES, Yes, and yeS will all be treated as identical).

Constraints
1 \leq T \leq 1001≤T≤100
1 \leq X \leq 10^91≤X≤10 
9
 
Sample 1:
Input
Output
4
2
5
6
12
NO
YES
NO
YES
Explanation:
Test case 11: There do not exist any positive integers aa and bb such that 2\cdot a + 2\cdot b + a\cdot b = 22⋅a+2⋅b+a⋅b=2.

Test case 22: Let a=1a=1 and b=1b=1, then 2\cdot a+2\cdot b+a\cdot b=52⋅a+2⋅b+a⋅b=5.

Test case 33: There do not exist any positive integers aa and bb such that 2\cdot a + 2\cdot b + a\cdot b = 62⋅a+2⋅b+a⋅b=6.

Test case 44: Let a=2a=2 and b=2b=2, then 2\cdot a+2\cdot b+a\cdot b=122⋅a+2⋅b+a⋅b=12.
*/

// solution 

void solution()
{
   int x;
   cin>>x;
   bool ans=false;
   if(x<5)
    ans = false;
   else
   {
       for(int i=1;i*i<x;i++)
       {
           int temp = x-(2*i);
           if(temp%(2+i)==0)
            {
                ans=true;
                break;
            }
       }
   }
   if(ans)
    cout<<"YES";
    else 
        cout<<"NO";
}
