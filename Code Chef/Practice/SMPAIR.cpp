/*
https://www.codechef.com/LP2TO302/problems/SMPAIR?tab=statement


You are given a sequence a1, a2, ..., aN. Find the smallest possible value of ai + aj, where 1 ≤ i < j ≤ N.

Input
The first line of the input contains an integer T denoting the number of test cases. The description of T test cases follows. 

The first line of each description consists of a single integer N.

The second line of each description contains N space separated integers - a1, a2, ..., aN respectively.

Output
For each test case, output a single line containing a single integer - the smallest possible sum for the corresponding test case.

Constraints
T = 105, N = 2 : 13 points.
T = 105, 2 ≤ N ≤ 10 : 16 points.
T = 1000, 2 ≤ N ≤ 100 : 31 points.
T = 10, 2 ≤ N ≤ 105 : 40 points.
1 ≤ ai ≤ 106
Sample 1:
Input
Output
1
4
5 1 3 4
4
Explanation:
Here we pick a2 and a3. Their sum equals to 1 + 3 = 4.
*/


// solution 


// CODE STARTS HERE-------------------------------------------------------------------------------------------
// space complexity : O(n)
// time complexity :  O(n)
void solution()
{
  int n;cin>>n;
    int arr[n];
    in(arr,n);
    int min1 = INT_MAX;
    int min2 = INT_MAX;
    int index=-1;
    for(int i=0;i<n;i++)
    {
        if(min1>arr[i])
        {
            min1=arr[i];
            index=i;
        }
    }
    arr[index]=INT_MAX;
    for(int i=0;i<n;i++)
    {
        if(min2>arr[i])
        {
            min2=arr[i];
            
        }
    }
    co(min1+min2);
  
  
  
}
//CODE ENDS HERE----------------------------------------------------------------------------------------------
