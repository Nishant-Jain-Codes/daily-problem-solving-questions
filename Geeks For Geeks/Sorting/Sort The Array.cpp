/*
Given a random set of numbers, Print them in sorted order.

Example 1:

Input:
N = 4
arr[] = {1, 5, 3, 2}
Output: {1, 2, 3, 5}
Explanation: After sorting array will 
be like {1, 2, 3, 5}.
Example 2:

Input:
N = 2
arr[] = {3, 1}
Output: {1, 3}
Explanation: After sorting array will
be like {3, 1}.
Your Task:  
You don't need to read input or print anything. Your task is to complete the function sortArr() which takes the list of integers and the size N as inputs and returns the modified list.

Expected Time Complexity: O(N * log N)
Expected Auxiliary Space: O(1)

Constraints:
1 ≤ N, A[i] ≤ 105
*/

// solution 
vector<int> sortArr(vector<int>arr, int n){
    //complete the function here
    sort(arr.begin(),arr.end());
    return arr;
    }
