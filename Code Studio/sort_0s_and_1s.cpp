/*

Problem Statement
You are given an array ‘A’ of size ‘N’ containing only 0s and 1s. You have to sort the array by traversing the array only once.
For Example:
For the following array:
[0 1 1 1 0 0 1]

The output should be [0 0 0 1 1 1 1].
Note:
You have to sort the array in place.
Input Format:
The first line will contain a single integer ‘T’ denoting the number of test cases. Then the test cases follow.

The first line of each test case will contain a single integer ‘N’, denoting the size of the array.

The second line of each test case will contain ‘N’ space-separated integers, denoting the elements of the array.
Output Format:
For each test case, print the input array after sorting it.
Note:
You are not required to print anything; it has already been taken care of. Just implement the function.
Constraints:
1 <= T <= 5
1 <= N <= 10^5
A[i] = 0 or 1

Time Limit: 1 sec.
Sample Input 1:
2
4
1 0 1 0 
6
0 1 1 0 0 0
Sample Output 1:
0 0 1 1
0 0 0 0 1 1
Explanation For Sample Output 1:
For the first test case, the sorted array will be [0 0 1 1].

For the second test case, the sorted array will be [0 0 0 0 1 1].
Sample Input 2:
2
10
0 1 1 0 1 0 1 1 0 0
8
1 1 1 0 0 1 0 1
Sample Output 2:
0 0 0 0 0 1 1 1 1 1
0 0 0 1 1 1 1 1
*/

// solution 

void sort0and1(int size, vector<int> &arr){
    
    int n0 = 0;
    for(int i = 0 ; i<size ; i++)
    {
        if(arr[i]==0)
        {
            n0++;
        }
    }
    for(int i = 0;i<size;i++)
    {
        if(i<n0)
        {
            arr[i]=0;
        }
        else
        {
            arr[i]=1;
        }
    }
}
