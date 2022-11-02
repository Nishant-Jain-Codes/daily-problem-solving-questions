/*
https://www.codechef.com/LP2TO302/problems/SRTCHK?tab=statement


Sort Checker
You are given an array AA and an array BB of the same size. You have to print yes if BB is the sorted version of AA and no otherwise.

Input
First line contains a single integer TT, the number of testcases.
The first line of each testcase contains a single integer nn, the number of elements in the arrays.
The second line of each testcase contains nn space separated integers denoting the array AA.
The third line of each testcase contains nn space separated integers denoting the array BB.
Output
Print one line for each testcase, yes or no.

Constraints
1 \leq T \leq 10^51≤T≤10 
5
 
1 \le n \le 10^51≤n≤10 
5
 
The sum of nn over all test cases does not exceed 10^510 
5
 .
Sample Input
3
4
1 3 2 2
1 2 3 4
4
1 3 2 2
1 2 3 2
4
1 3 2 2
1 2 2 3
```### Sample Output
no no yes

### Explanation

All three testcases have the same array $A$, and the sorted version of $A$ is $\{1, 2, 2, 3\}$.

Therefore only the third testcase contains **yes**, rest contain **no**.
*/

// solution 


// CODE STARTS HERE-------------------------------------------------------------------------------------------
// space complexity : O(n)
// time complexity :  O(nlogn)
void solution()
{
  int n;cin>>n;
    int a[n];
    in(a,n);
    int b[n];
    in(b,n);
    sort(a,a+n);
    bool ans = true;
    for(int i=0;i<n;i++)
    {
        if(a[i]!=b[i])
        {
            ans=false;
            break;
        }
    }
    
    if(!ans)
    cout<<"no ";
    else 
    cout<<"yes ";
  
  
  
}
//CODE ENDS HERE----------------------------------------------------------------------------------------------
