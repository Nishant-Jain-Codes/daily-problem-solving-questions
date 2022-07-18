/*
Problem Statement
You are given an array “ARR” of size N. Your task is to find out the sum of maximum and minimum elements in the array.
Follow Up:
Can you do the above task in a minimum number of comparisons?
Input Format:
The first line of input contains a single integer T, representing the number of test cases.
Then the T test cases follow. 

The first line of each test case contains a single integer N representing the size of the array 'ARR'.

The second line of each test case contains N space separated integers representing the elements of the array “arr”.
Output Format:
For each test case, print the sum of the maximum and minimum element of the array 'ARR'.
Note:
You do not need to print anything. It has already been taken care of. Just implement the given function.
Constraints:
1 <= T <= 10
1 <= N <= 10^5 
-10^9 <= ARR[i] <= 10^9

Time limit: 1 second
Sample Input 1:
2
7
1 2 4 5 6 6 6 
6
-1 -4 5 8 9 3
Sample Output 1:
7
5
Explanation For Sample Input 1:
For the first test case, the maximum element in the array is 6 and the minimum element in the array is 1.

For the second test case, the maximum element in the array is 9 and the minimum element in the array is -4.
Sample Input 2:
2
5
3 3 3 3 3 
1
-1
Sample Output 2:
6
-2
*/

// solution 
#include <bits/stdc++.h>
int sumOfMaxMin(int arr[], int n){
	// Write your code here.
    sort(arr, arr + n);
    return arr[0]+arr[--n];
}
