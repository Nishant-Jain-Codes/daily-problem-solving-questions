/*
Problem
Chef is given two arrays AA and BB of length NN each.

In one operation Chef can choose one element of AA and one element of BB and increase them by 11.

More formally: Chef can pick two integers i, ji,j (1\le i, j \le N)(1≤i,j≤N) and increment A_iA 
i
​
  and B_jB 
j
​
  by 11.

Determine the minimum number of operations required to make AA and BB equal.

Output -1−1 if it is not possible to make AA and BB equal.

Input Format
The first line of input will contain a single integer TT, denoting the number of test cases.
Each test case consists of multiple lines of input.
The first line of each test case contains a single integer NN - denoting the length of arrays AA and BB.
The second line of each test case contains NN space separated integers A_1, A_2, A_3, \dots A_NA 
1
​
 ,A 
2
​
 ,A 
3
​
 ,…A 
N
​
  - denoting the array AA.
The third line of each test case contains NN space separated integers B_1, B_2, B_3, \dots B_NB 
1
​
 ,B 
2
​
 ,B 
3
​
 ,…B 
N
​
  - denoting the array BB.
Output Format
For each test case, output the minimum number of operations to make AA and BB equal or -1−1 if they cannot be made equal.

Constraints
1 \leq T \leq 2 \cdot 10^41≤T≤2⋅10 
4
 
2 \leq N \leq 10^52≤N≤10 
5
 
1 \leq A_i, B_i \leq 10^91≤A 
i
​
 ,B 
i
​
 ≤10 
9
 
Sum of NN over all test cases do not exceed 10^510 
5
 .
Sample 1:
Input
Output
3
2
1 2
2 1
3
1 1 2
2 2 1
3
4 6 8
5 7 6
1
-1
2
Explanation:
Test case 11: We can choose i = 1i=1 and j = 2j=2 and increment A_iA 
i
​
  and B_jB 
j
​
  by 11. Thus, both arrays become [2, 2][2,2] and are equal. We require only 11 operation to make these arrays equal. It can be proven that the arrays cannot be made equal in less than one operation.

Test case 22: Both the arrays cannot be made equal using any number of operations.

Test case 33: We perform 22 operations as follows:

Choose i = 1, j = 3i=1,j=3: The arrays become A = [5, 6, 8]A=[5,6,8] and B = [5, 7, 7]B=[5,7,7].
Choose i = 2, j = 3i=2,j=3: The arrays become A = [5, 7, 8]A=[5,7,8] and B = [5, 7, 8]B=[5,7,8].
Thus, both arrays can be made equal using 22 operations.
*/
// solution 
void solution()
{
   int n;
   cin>>n;
   vector< int> A,B;
   for(int i=0;i<n;i++)//A in
   {
       int in;
       cin>>in;
       A.push_back(in);
       
   }
    for(int i=0;i<n;i++)// B in 
   {
        int in;
       cin>>in;
       B.push_back(in);
       
   }

   int max=0;
   int sum=0;
   int c[n];
   for(int i=0;i<n;i++)
   {
       c[i]=A[i]-B[i];
       sum+=c[i];
       if(c[i]>0)
        max+=c[i];
   }
        if(sum==0)
            cout<<max;
        else
            cout<<-1;
}
