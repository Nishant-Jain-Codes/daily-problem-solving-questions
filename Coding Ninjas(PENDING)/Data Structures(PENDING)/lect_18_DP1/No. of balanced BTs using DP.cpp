/*

Given an integer h, find the possible number of balanced binary trees of height h. You just need to return the count of possible binary trees which are balanced.
This number can be huge, so, return output modulus 10^9 + 7.
Time complexity should be O(h).
Input Format :
The first and only line of input contains an integer, that denotes the value of h. Here, h is the height of the tree.
Output Format :
The first and only line of output contains the count of balanced binary trees modulus 10^9 + 7.
Constraints :
1 <= h <= 10^6
Time Limit: 1 sec
Sample Input 1:
3
Sample Output 1:
15
Sample Input 2:
4
Sample Output 2:
315

*/
// solution 


#include<bits/stdc++.h>

// dynamic programming O(n)
int balancedBTs(int n)
{
    if(n<=1)
        return 1;
    int *arr=new int[n+1];
    arr[0]=1,arr[1]=1;
     int m=(int)pow(10,9)+7;
    for(int i=2;i<=n;i++)
    {
        int x=arr[i-1];
     	int y=arr[i-2];
        int temp1=(int)(((long)(x)*x)%m);
        int temp2=(int)((2*(long)(x)*y)%m);
        int ans=(temp1+temp2)%m;
        arr[i]=ans;
    }
    return arr[n];
    
}

// memoisation O(n);

int memoHelper(int *arr,int n)
{
    if(n<=1)
        return 1;
    if(arr[n]!=-1)
        return arr[n];
     int m=(int)pow(10,9)+7;
    int x=memoHelper(arr,n-1);
     int y=memoHelper(arr,n-2);
    int temp1=(int)(((long)(x)*x)%m);
    int temp2=(int)((2*(long)(x)*y)%m);
    int ans =(temp1+temp2)%m;
    arr[n]=ans;
    return ans;
}

int balancedBTs(int n) {
    // Write your code here
    int *arr=new int[n+1];
    for(int i=0;i<=n;i++)
    	arr[i]=-1;
    return memoHelper(arr,n);
}








// recursive brutforce - O(2^n);
int balancedBTs(int h) {
    // Write your code here
    if(h<0)
        return 0;
    if(h==1||h==0)
        return 1;
    int m=(int)pow(10,9)+7;
    int x=balancedBTs(h-1);
     int y=balancedBTs(h-2);
    int temp1=(int)(((long)(x)*x)%m);
    int temp2=(int)((2*(long)(x)*y)%m);
    int ans =(temp1+temp2)%m;
    return ans;
}
*/
