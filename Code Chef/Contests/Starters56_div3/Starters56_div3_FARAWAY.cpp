/*
https://www.codechef.com/START56C/problems/FARAWAY


Problem
Chef has an array AA of size NN and an integer MM, such that 1 \leq A_i \leq M1≤A 
i
​
 ≤M for every 1 \leq i \leq N1≤i≤N.

The distance of an array BB from array AA is defined as:

d(A, B) = \sum_{i=1}^N |A_i - B_i|
d(A,B)= 
i=1
∑
N
​
 ∣A 
i
​
 −B 
i
​
 ∣
Chef wants an array BB of size NN, such that 1 \le B_i \le M1≤B 
i
​
 ≤M and the value d(A, B)d(A,B) is as large as possible, i.e, the distance of BB from AA is maximum.

Find the maximum distance for any valid array BB.

Note: |X|∣X∣ denotes the absolute value of an integer XX. For example, |-4| = 4∣−4∣=4 and |7| = 7∣7∣=7.

Input Format
The first line of input will contain a single integer TT, denoting the number of test cases.
Each test case consists of two lines of input.
The first line of each test case contains two space-separated integers NN and MM — the length of array AA and the limit on the elements of AA and BB.
The second line contains NN space-separated integers A_1, A_2, \ldots, A_NA 
1
​
 ,A 
2
​
 ,…,A 
N
​
 .
Output Format
For each test case, output on a new line the maximum distance of an array from AA.

Constraints
1 \leq T \leq 10^51≤T≤10 
5
 
1 \leq N \leq 2\cdot 10^51≤N≤2⋅10 
5
 
1 \leq M \leq 10^91≤M≤10 
9
 
1 \leq A_i \leq M1≤A 
i
​
 ≤M
The sum of NN over all test cases won't exceed 3\cdot 10^53⋅10 
5
 .
Sample 1:
Input
Output
4
2 6
3 5
4 1
1 1 1 1
5 7
2 3 4 5 6
7 24
23 7 6 16 12 4 24
7
0
21
127
Explanation:
Test case 11: The array having maximum distance from AA is B = [6, 1]B=[6,1]. Thus the distance is |3-6| + |5-1| = 3+4=7∣3−6∣+∣5−1∣=3+4=7.

Test case 22: The only array possible is B = [1,1,1,1]B=[1,1,1,1]. The distance of this array from AA is 00.

Test case 33: One of the possible arrays having maximum distance from AA is B = [7,7,1,1,1]B=[7,7,1,1,1]. Thus the distance is |2-7| + |3-7| + |4-1| + |5-1| + |6-1| = 5+4+3+4+5=21∣2−7∣+∣3−7∣+∣4−1∣+∣5−1∣+∣6−1∣=5+4+3+4+5=21.
*/

// solution 



void solution()
{
  int n;cin>>n;
  int m;cin>>m;
  int arr[n];
  int check=m/2;
  int ans=0;
  for(int i=0;i<n;i++)
  {
   int in;cin>>in;
   if(in>check)
    ans+=in-1;
    else 
    ans+=m-in;
  }
    
  co(ans);
  
  
}
