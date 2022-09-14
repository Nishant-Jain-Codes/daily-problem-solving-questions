/*
https://www.codechef.com/LP2TO301/problems/INDIPERM


Problem
You are given an integer NN. Construct an array PP of size NN such that:

PP is a permutation of the first NN natural numbers, i.e, each integer 1, 2, 3, \ldots N1,2,3,…N occurs exactly once in PP. For example, [1, 3, 2][1,3,2] is a permutation of size 33, but [1, 3, 4][1,3,4] and [2, 1, 2][2,1,2] are not.
PP is indivisible. PP is said to be indivisible if ii does not divide P_iP 
i
​
  for every index 2 \leq i \leq N2≤i≤N.
It can be proven that under the given constraints, there always exists an indivisible permutation. If there are multiple, you may print any of them.

Input Format
The first line of input contains a single integer TT, denoting the number of test cases. The description of TT test cases follows.
The first and only line of each test case contains a single integer NN, denoting the size of the indivisible permutation you must construct.
Output Format
For every test case, print a single line containing NN space-separated integers. These integers must form an indivisible permutation.
Constraints
1 \leq T \leq 6001≤T≤600
2 \leq N \leq 10^52≤N≤10 
5
 
Sum of NN over all test cases does not exceed 2 \cdot 10^52⋅10 
5
 
Sample 1:
Input
Output
4
2
3
4
5
2 1 
1 3 2 
1 3 4 2 
4 5 2 3 1 
Explanation:
For the last test case:
P_2 = 5P 
2
​
 =5 is not divisible by 22
P_3 = 2P 
3
​
 =2 is not divisible by 33
P_4 = 3P 
4
​
 =3 is not divisible by 44
P_5 = 1P 
5
​
 =1 is not divisible by 55
Since ii does not divide P_iP 
i
​
  for every index 2\leq i\leq N2≤i≤N, the permutation is indivisible.
*/

// solution 



void solution()
{
  int n;cin>>n;
  for(int i=1;i<=n;i++)
  {
     if(i==1)
        cout<<n<<" ";
        else 
        cout<<i-1<<" ";
  }
  cout<<endl;
    
  
  
  
}
