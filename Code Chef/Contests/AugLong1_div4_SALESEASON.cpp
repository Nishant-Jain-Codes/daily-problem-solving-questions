/*
Problem
It's the sale season again and Chef bought items worth a total of XX rupees. The sale season offer is as follows:

if X \le 100X≤100, no discount.
if 100 \lt X \le 1000100<X≤1000, discount is 2525 rupees.
if 1000 \lt X \le 50001000<X≤5000, discount is 100100 rupees.
if X \gt 5000X>5000, discount is 500500 rupees.
Find the final amount Chef needs to pay for his shopping.

Input Format
The first line of input will contain a single integer TT, denoting the number of test cases.
Each test case consists of single line of input containing an integer XX.
Output Format
For each test case, output on a new line the final amount Chef needs to pay for his shopping.

Constraints
1 \leq T \leq 1001≤T≤100
1 \leq X \leq 100001≤X≤10000
Sample 1:
Input
Output
4
15
70
250
1000
15
70
225
975
Explanation:
Test case 11: Since X \le 100X≤100, there is no discount.

Test case 33: Here, X = 250X=250. Since 100 \lt 250 \le 1000100<250≤1000, discount is of 2525 rupees. Therefore, Chef needs to pay 250-25 = 225250−25=225 rupees.

accepted
Accepted
13836
total-Submissions
Submissions
20657
*/

// solution 
void solution()
{
   int x;
   cin>>x;
   if(x>5000)
   {
       cout<<x-500;
   }
   else if(x>1000)
   {
       cout<<x-100;
   }
   else if(x>100)
   {
       cout<<x-25;
   }
   else 
   {
       cout<<x;
   }
}
