/*
Problem
There are 22 trains AA and BB and NN stations in a line from 11 to NN in order. There is also an array PP of length N-1N−1 such that P_iP 
i
​
  (1\le i \lt N)(1≤i<N) denotes the amount of time any train takes to go from the ii-th station to the (i+1)(i+1)-th station.

Initially, both trains are at station 11. Train AA departs from station 11 and stops directly at station NN. For safety purposes, it is maintained that train BB cannot depart from station ii unless train AA has already reached station (i+1)(i+1) (1 \le i \lt N)(1≤i<N).

Find the minimum time after which train BB reaches station NN, once train AA departs from station 11.

Input Format
The first line of input will contain a single integer TT, denoting the number of test cases.
Each test case consists of two lines of input.
The first line of each test case contains an integer NN, denoting number of stations.
The next line contains N-1N−1 space-separated integers, P_1,P_2,\ldots ,P_{N-1}P 
1
​
 ,P 
2
​
 ,…,P 
N−1
​
 .
Output Format
For each test case, output on a new line the minimum time after which train BB reaches station NN.

Constraints
1 \leq T \leq 1001≤T≤100
2 \leq N \leq 10^52≤N≤10 
5
 
1 \leq P_i \leq 10^31≤P 
i
​
 ≤10 
3
 
The sum of NN over all test cases won't exceed 10^510 
5
 .
Sample 1:
Input
Output
3
2
4
3
3 5
4
5 2 6
8
13
19
Explanation:
Test case 11: AA reaches station 22 at t=4t=4 and at this time BB departs from station 11 and reaches station 22 at t=4+4=8t=4+4=8.

Test case 22: Following is the timeline of two trains-

At t=3t=3, AA reaches station 22 and BB departs from station 11.
At t=6t=6, BB reaches station 22 but AA has not yet reached station 33, so train BB will wait at station 22.
At t=8t=8, AA reaches station 33 and BB departs from station 22.
At t=8+5=13t=8+5=13, train BB reaches station 33.
*/
// solution 
void solution()
{
   int n;
   cin>>n;
    int A[n]={0},B[n]={0},diff;
    int sum;
    for(int i=1;i<n;i++)
    {
        int in;
        cin>>in;
        sum+=in;
        A[i]=sum;
        B[i]=in;
    }
    int i=0;
    for(;i<n-1;i++)
    {
        diff=A[i+1]-B[i];
        if(diff>0)
            B[i+1] += B[i]+diff;
        else
            B[i+1] += B[i];
    }
    cout<<B[i];
}
