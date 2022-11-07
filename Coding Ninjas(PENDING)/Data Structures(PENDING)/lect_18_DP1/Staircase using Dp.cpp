/*

*/

// solution


#include<bits/stdc++.h>
using namespace std;
#define int             long long int
#define m  1000000007

int recursiveSol(int n)
{
	if(n==0)
        return 1;
    else if(n<0)
        return 0;
    
        return recursiveSol(n-3)+recursiveSol(n-2)+recursiveSol(n-1);
   
    
}

int memoHelper(int *arr,int n)
{
    if(n<0)
        return 0;
    if(n==0)
        return 1;
    if(arr[n]!=-1)
        return arr[n];
    int ans=(memoHelper(arr,n-3)%m)+(memoHelper(arr,n-2)%m)+(memoHelper(arr,n-1)%m);
    arr[n]=ans%m;
    return ans;
}
int memoisataionSol(int n)
{
    int *arr=new int[n+1];
    for(int i=0;i<=n;i++)
        arr[i]=-1;
    return memoHelper(arr,n);
}

int dpSolution(int n)
{
    if(n<0)
		return 0;
    if(n==0)
        return 1;
    int *arr=new int[n+1];
    arr[0]=1;
    arr[1]=1;
    arr[2]=2;
    for(int i=3;i<=n;i++)
    {
        arr[i]=(arr[i-1]%m)+(arr[i-2]%m)+(arr[i-3]%m);
    }
    return arr[n]%m;
    
}

int solution(int n)
{
    // recursive solution O(2^n) - exponential complexity 
    return recursiveSol(n);
    
    //memoisation solution O(N)
    return memoisataionSol(n);
    
    //DP solution O(N)
    return dpSolution(n);
}




int32_t main(){
    
    // write your code here
    int t;cin>>t;
    while(t--)
    {	int n;
     cin>>n;
     
        int s =solution(n)%m;
     cout<<s<<endl;
    }
    return 0;
}
