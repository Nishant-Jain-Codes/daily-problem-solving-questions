/*
For the given infinite supply of coins of each of denominations, D = {D0, D1, D2, D3, ...... Dn-1}. You need to figure out the total number of ways W, in which you can make the change for Value V using coins of denominations D.
Return 0 if the change isn't possible.
Input Format
The first line of the input contains an integer value N, which denotes the total number of denominations.

The second line of input contains N values, separated by a single space. These values denote the value of denomination.

The third line of the input contains an integer value, that denotes the value of V.
Output Format
Print the total total number of ways i.e. W.
Constraints :
1 <= n <= 10
1 <= V <= 1000

Time Limit: 1sec
Sample Input 1 :
3
1 2 3
4
Sample Output 1 :
4
Explanation to Sample Input 1 :
Number of ways are - 4 total i.e. (1,1,1,1), (1,1, 2), (1, 3) and (2, 2).
Sample Input 2 :
6
1 2 3 4 5 6
250
Sample Output 2 :
13868903
*/
#include <bits/stdc++.h>
using namespace std;


int countWaysToMakeChange(int den[], int n, int v)
{
    int dp[n][v+1];
    for(int i=0;i<=v;i++)
    {
        dp[0][i]=(v%den[0]==0);
    }
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<=v;j++)
        {
            int take=0,notTake=0;
                notTake = dp[i-1][j];
            if(j-den[i]>=0)
                take=dp[i][j-den[i]];
            dp[i][j]=take + notTake;
        }
    }
    return dp[n-1][v];
}

int main()
{

    int numDenominations;
    cin >> numDenominations;
    
    int *denominations = new int[numDenominations];

    for (int i = 0; i < numDenominations; i++)
    {
        cin >> denominations[i];
    }

    int value;
    cin >> value;

    cout << countWaysToMakeChange(denominations, numDenominations, value);

    delete[] denominations;
}