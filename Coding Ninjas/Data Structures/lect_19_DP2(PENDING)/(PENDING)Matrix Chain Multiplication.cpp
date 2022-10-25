/*
Given a chain of matrices A1, A2, A3,.....An, you have to figure out the most efficient way to multiply these matrices. In other words, determine where to place parentheses to minimize the number of multiplications.
You will be given an array p[] of size n + 1. Dimension of matrix Ai is p[i - 1]*p[i]. You need to find minimum number of multiplications needed to multiply the chain.
Input Format:
The first line of input contains an integer, that denotes the value of n. The following line contains n+1 integers, that denote the value of elements of array p[].
Output Format:
The first and only line of output prints the minimum number of multiplication needed.
Constraints :
1 <= n <= 100
Time limit: 1 second
Sample Input 1:
3
10 15 20 25
Sample Output 1:
8000
Sample Output Explanation:
There are two ways to multiply the chain - A1*(A2*A3) or (A1*A2)*A3.
If we multiply in order- A1*(A2*A3), then number of multiplications required are 11250.
If we multiply in order- (A1*A2)*A3, then number of multiplications required are 8000.
Thus minimum number of multiplications required are 8000. 
*/


//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
int multAns(int *arr,int si,int ei,int **dp){

    if(si==ei||si==ei-1)
        return 0;
    int ans=INT_MAX;
    for(int k=si+1;k<ei;k++)
    {   int m1,m2,m3;
        if(dp[si][k]!=-1)
            m1=dp[si][k];
        else 
        {
            m1=multAns(arr,si,k,dp);
            dp[si][k]=m1;
        }
        if(dp[k][ei]!=-1)
            m2=dp[k][ei];
        else 
        {
            m2=multAns(arr,k,ei,dp);
            dp[k][ei]=m2;
        }
        m3 = arr[si]*arr[k]*arr[ei];
        int sc=m1+m2+m3;
        ans=min(ans,sc);
    }    
    return ans;
}
int matrixChainMultiplication(int* arr, int n) {
    // Write your code here
    int **dp= new int* [n+1];
    for(int i=0;i<=n;i++)
    {
        dp[i]=new int[n+1];
        for(int j=0;j<=n;j++)
        {
            dp[i][j]=-1;
        }
    }
    int ans=multAns(arr,0,n,dp);
    for(int i=0;i<=n;i++)
        delete [] dp[i];
    delete []dp;
    return ans;
}
int main() {
    int n;
    cin >> n;
    int* arr = new int[n];

    for (int i = 0; i <= n; i++) {
        cin >> arr[i];
    }

    cout << matrixChainMultiplication(arr, n);

    delete[] arr;
}