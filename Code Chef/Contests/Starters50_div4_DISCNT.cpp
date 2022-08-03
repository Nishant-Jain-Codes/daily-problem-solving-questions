/*
Problem
Alice buys a toy with a selling price of 100100 rupees. There is a discount of xx percent on the toy. Find the amount Alice needs to pay for it.

Input Format
The first line of input will contain a single integer TT, denoting the number of test cases.
The first and only line of each test case contains a single integer, xx — the discount on the toy.
Output Format
For each test case, output on a new line the price that Alice needs to pay.

Constraints
1 \leq T \leq 1001≤T≤100
0 \leq x \lt 1000≤x<100
Sample 1:
Input
Output
4
5
9
11
21
95
91
89
79
Explanation:
Test case 11: The discount is 55 percent, i.e. 55 rupees. So, Alice will have to pay 100-5=95100−5=95 rupees.
*/
// solution 
void solution()
{
    int x;
    cin>>x;
    cout<<100-x<<endl;
}
