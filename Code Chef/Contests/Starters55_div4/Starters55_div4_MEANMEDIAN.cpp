/*
https://www.codechef.com/START55D/problems/MEANMEDIAN



Problem
Chef has two numbers XX and YY. Chef wants to find three integers A, B,A,B, and CC such that:

-1000 \le A, B, C \le 1000−1000≤A,B,C≤1000
mean([A, B, C]) = Xmean([A,B,C])=X
median([A, B, C]) = Ymedian([A,B,C])=Y
Can you help Chef find such three integers?

As a reminder, mean([P, Q, R]) = \frac{P + Q + R}{3}mean([P,Q,R])= 
3
P+Q+R
​
  and median([P, Q, R])median([P,Q,R]) is the element at the 2^{nd}2 
nd
  (middle) position after we sort [P, Q, R][P,Q,R] in non-decreasing order.

Input Format
The first line contains a single integer TT — the number of test cases. Then the test cases follow.
The first and only line of each test case contains two space-separated integers XX and YY — the required mean and median of the three integers.
Output Format
For each test case, output three integers A, B, CA,B,C which satisfy the given conditions.

It is guaranteed that an answer always exists under the given constraints.

If multiple answers exist, output any.

Constraints
1 \leq T \leq 10^51≤T≤10 
5
 
-100 \le X, Y \le 100−100≤X,Y≤100
Sample 1:
Input
Output
3
5 5
67 100
4 5
5 5 5
0 100 101
0 5 7
Explanation:
Test Case 1: mean([5, 5, 5]) = \frac{5 + 5 + 5}{3} = 5mean([5,5,5])= 
3
5+5+5
​
 =5, median([5, 5, 5]) = 5median([5,5,5])=5.

Test Case 2: mean([0, 100, 101]) = \frac{0 + 100 + 101}{3} = \frac{201}{3} = 67mean([0,100,101])= 
3
0+100+101
​
 = 
3
201
​
 =67, median([0, 100, 101]) = 100median([0,100,101])=100.

Test Case 3: mean([0, 5, 7]) = \frac{0 + 5 + 7}{3} = 4mean([0,5,7])= 
3
0+5+7
​
 =4, median([0, 5, 7]) = 5median([0,5,7])=5.
*/


// solution 
void solution()
{
    int x;cin>>x;
    
    int y;cin>>y;
    
    int a,b,c=1000;
    int d=(3*x)-y;
    b=y;
    for(;c>=d;c--)
    {
        if(d%c==0)
            break;
    }
    a=d-c;
    cout<<a<<" "<<b<<" "<<c<<" "<<endl;
}
