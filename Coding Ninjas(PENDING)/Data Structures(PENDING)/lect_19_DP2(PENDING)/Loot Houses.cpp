/*

A thief wants to loot houses. He knows the amount of money in each house. He cannot loot two consecutive houses. Find the maximum amount of money he can loot.
Input format :
The first line of input contains an integer value of 'n'. It is the total number of houses.

The second line of input contains 'n' integer values separated by a single space denoting the amount of money each house has.
Output format :
Print the the maximum money that can be looted.
Constraints :
0 <= n <= 10 ^ 4

Time Limit: 1 sec
Sample Input 1 :
6
5 5 10 100 10 5
Sample Output 1 :
110
Sample Input 2 :
6
10 2 30 20 3 50
Sample Output 2 :
90
Explanation of Sample Output 2 :
Looting first, third, and the last houses([10 + 30 + 50]) will result in the maximum loot, and all the other possible combinations would result in less than 90.

*/



// solution 

//DP
int solDP(int *arr,int n)
{
    if(n==0)
        return 0;
    if(n==1)
        return arr[0];
    int*dp=new int[n+1];
    dp[0]=0;
    dp[1]=arr[0];
    for(int i=2;i<=n;i++)
    {
        dp[i]=max(dp[i-1],arr[i-1]+dp[i-2]);
    }
    return dp[n];
}

//memoisation
int solMEMO(int *arr,int n,int *ans)
{
    if(n<=0)
        return 0;
    if(ans[n]!=-1)
        return ans[n];
    int a=arr[0]+solMEMO(arr+2,n-2,ans);
    int b=solMEMO(arr+1,n-1,ans);
    ans[n]= max(a,b);
    return ans[n];
}

int solMEMO(int *arr,int n)
{
    int *ans=new int[n+1];
    for(int i=0;i<=n;i++)
    {
        ans[i]=-1;
    }
    return solMEMO(arr,n,ans);
}

//recursive
int solRecusive(int *arr, int n)
{
    if(n<=0)
        return 0;
    int a=arr[0]+solRecusive(arr+2,n-2);
    int b=solRecusive(arr+1,n-1);
    return max(a,b);
}
int maxMoneyLooted(int *arr, int n)
{
    return solDP(arr,n);
}
