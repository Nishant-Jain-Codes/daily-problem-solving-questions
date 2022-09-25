/*

Given a positive integer 'n', find and return the minimum number of steps that 'n' has to take to get reduced to 1. You can perform any one of the following 3 steps:
1.) Subtract 1 from it. (n = n - ­1) ,
2.) If its divisible by 2, divide by 2.( if n % 2 == 0, then n = n / 2 ) ,
3.) If its divisible by 3, divide by 3. (if n % 3 == 0, then n = n / 3 ).  
Write brute-force recursive solution for this.
Input format :
The first and the only line of input contains an integer value, 'n'.
Output format :
Print the minimum number of steps.
Constraints :
1 <= n <= 200

Time Limit: 1 sec
Sample Input 1 :
4
Sample Output 1 :
2 
Explanation of Sample Output 1 :
For n = 4
Step 1 :  n = 4 / 2  = 2
Step 2 : n = 2 / 2  =  1 
Sample Input 2 :
7
Sample Output 2 :
3
Explanation of Sample Output 2 :
For n = 7
Step 1 :  n = 7 ­- 1 = 6
Step 2 : n = 6  / 3 = 2 
Step 3 : n = 2 / 2 = 1  

*/

// solution 



#include<bits/stdc++.h>
// dynamic proggramming 
int countMinStepsToOne(int n)
{
    int *ans = new int[n+1];
    ans[0]=0;
    ans[1]=0;
    ans[2]=1;
    for(int i=3;i<=n;i++)
    {
        int a=INT_MAX;
        int b=INT_MAX;
        int c=INT_MAX;
        if(i%3==0)
            a=1+ans[i/3];
        if(i%2==0)
            b=1+ans[i/2];
        
            c=1+ans[i-1];
        ans[i]=min(a,min(b,c));
    }
    return ans[n];
}


// memoisation
int countHelper(int *arr,int n)
{
    if(n<=1)
        return 0;
    //check if output exists;
    if(arr[n]!=-1)
        return arr[n];
    int a=INT_MAX;
    int b=INT_MAX;
    int c=INT_MAX;
    if(n%2==0)
        a=1+countHelper(arr,n/2);
    if(n%3==0)
        b=1+countHelper(arr,n/3);
    c=1+countHelper(arr,n-1);
    int ans=min(a,min(b,c));
    arr[n]=ans;
    return ans;
}

int countMinStepsToOne(int n)
{
    int * arr=new int[n+1];
    for(int i=0;i<=n;i++)
    {
        arr[i]=-1;
    }
    return countHelper(arr,n);
}


// brute force-recursion 
int countMinStepsToOne(int n)
{
	//Write your code here
    if(n==1)
        return 0;
    int a=INT_MAX,b=INT_MAX,c=INT_MAX;
    if(n%2==0)
        a=1+countMinStepsToOne(n/2);
    if(n%3==0)
        b=1+countMinStepsToOne(n/3);
    c=1+countMinStepsToOne(n-1);
    
    return min(a,min(b,c));
}

