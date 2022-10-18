/*
https://www.codechef.com/LP2TO302/problems/CNTSORT


Given an array AA of NN integers, such that 1 \le A[i] \le 1001≤A[i]≤100,,

sort AA in non-decreasing/ascending order, and display the elements of the sorted array.

Input:
The first line contains an integer TT, denoting the number of test cases.
The first line of each test case contains an integer NN, the number of elements in AA.
The next line contains NN space-separated integers, denoting the elements of array AA.
Output:
For each test case, display the elements of the sorted array, in a new line, separated by a space.

Constraints
1 \le T \le 31≤T≤3
1 \le N \le 10^61≤N≤10 
6
 
1 \le A[i] \le 1001≤A[i]≤100
Sample Input:
2
5
7 2 9 10 1
4
3 7 7 3
```### Sample Output:
1 2 7 9 10 3 3 7 7

The sample outputs are the sorted orders of the input arrays respectively, 
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
    sort(a,a+n);
    for(auto x:a)
    cout<<x<<" ";
  
  
  
}
//CODE ENDS HERE----------------------------------------------------------------------------------------------
