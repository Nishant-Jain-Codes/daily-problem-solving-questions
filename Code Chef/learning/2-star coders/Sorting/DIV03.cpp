/*
https://www.codechef.com/LP2TO302/problems/DIV03


Daanish as always is busy creating and solving his favourite and interesting graph problems. Chef assigns each problem a difficulty — an integer between 11 and 1010. For each valid ii, there are A_iA 
i
​
  problems with difficulty ii.

A participant hacked Daanish's account and got access to the problem proposal document. He can delete up to KK problems from the document in order to reduce the difficulty of the contest for himself and his friends. Find the smallest possible value of the difficulty of the most difficult problem which remains after removing KK problems.

Input
The first line of the input contains a single integer TT denoting the number of test cases. The description of TT test cases follows.
The first line of each test case contains 1010 space-separated integers A_1, A_2, \ldots, A_{10}A 
1
​
 ,A 
2
​
 ,…,A 
10
​
 .
The second line contains a single integer KK.
Output
For each test case, print a single line containing one integer — the minimum difficulty of the most difficult remaining problem.

Constraints
1 \leq T \leq 2 \cdot 10^41≤T≤2⋅10 
4
 
0 \leq A_i \leq 10^80≤A 
i
​
 ≤10 
8
  for each valid ii
A_1 + A_2 + \ldots + A_{10} \gt 0A 
1
​
 +A 
2
​
 +…+A 
10
​
 >0
0 \leq K \lt A_1 + A_2 + \ldots + A_{10}0≤K<A 
1
​
 +A 
2
​
 +…+A 
10
​
 
Subtasks
Subtask #1 (100 points): original constraints

Sample 1:
Input
Output
5
1 10 1 5 3 2 4 9 0 100
100
2 0 1 0 0 0 0 0 0 10
12
2 0 1 0 0 0 0 10 0 0
0
2 0 1 0 0 0 0 0 0 10
10
1 10 1 5 3 2 4 9 0 100
125
8
1
8
3
2
Explanation:
Example case 1: The participant can remove all 100100 problems with difficulty 1010. Then, there are no problems with difficulties 99 and 1010, so the maximum difficulty among remaining problems is 88.

Example case 2: The participant can remove all problems with difficulties 33 and 1010 and any one of the problems with difficulty 11. Then, the only problem left has difficulty 11.

Example case 3: The participant cannot remove any problem. The document does not contain any problems with difficulties 99 or 1010, so the maximum difficulty of a problem is 88.
*/



// CODE STARTS HERE-------------------------------------------------------------------------------------------
// space complexity : O(n)
// time complexity :  O(n)
void solution()
{
    int n=10;
    int a[n];
    in(a,n);
    int k;cin>>k;
    int ei=n-1;
    int i;
    for(i=n-1;i>=0;i--)
    {
        if(k>=a[i])
        {
            
            k-=a[i];
            a[i]=0;
        }
        else
        {
            a[i]-=k;
            k=0;
            break;
            
        }
        
        
    }
  co(i+1);
  
  
}
//CODE ENDS HERE----------------------------------------------------------------------------------------------
