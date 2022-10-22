/*

LCS Problem Statement:
Given two sequences, find the length of longest subsequence present in both of them.
A subsequence is a sequence that appears in the same relative order, but not necessarily contiguous.
For example, “abc”, “abg”, “bdf”, “aeg”, ‘”acefg”, .. etc are subsequences of “abcdefg”. 

*/

//solution 


#include<bits/stdc++.h>
using namespace std;
// dynamic programming 

int LCS_DP(string a , string b)
{
    int **arr = new int* [a.size()+1];
    for(int i=0;i<=a.size();i++)
    {
        arr[i]=new int [b.size()+1];
    }   
    for(int i=0;i<=a.size();i++)
    {
        arr[i][0]=0;
    }
    for(int j=0;j<=b.size();j++)
    {
        arr[0][j]=0;
    }
    for(int i=1;i<=a.size();i++)
    {
        for(int j=1;j<=b.size();j++)
        {
            if(a[a.size()-i]==b[b.size()-j])
            {
                arr[i][j]=1+arr[i-1][j-1];
            }
            else 
            {
                arr[i][j]=max(arr[i-1][j-1],max(arr[i][j-1],arr[i-1][j]));
            }
        }
    }
    return arr[a.size()][b.size()];
}

// memoisation 

int memoHelper(string a,string b,int ** arr)
{
    if(a.size()==0||b.size()==0)
        return 0;
    if(arr[a.size()][b.size()]!=-1)
        return arr[a.size()][b.size()];
    int ans;
    if(a[0]==b[0])
        ans= 1+memoHelper(a.substr(1),b.substr(1),arr);
    else 
    {
        int aa = memoHelper(a,b.substr(1),arr);
        int bb = memoHelper(a.substr(1),b,arr);
        ans=max(aa,bb);

    }
    arr[a.size()][b.size()]=ans;
    return ans;

}
int LCS_memo(string a , string b)
{
    int **arr = new int* [a.size()+1];
    for(int i=0;i<=a.size();i++)
    {
        arr[i]=new int [b.size()+1];
        for( int j=0;j<=b.size();j++)
            arr[i][j]=-1;
    }
    return memoHelper(a,b,arr);
}

// brute force
int LCS_recursive(string a , string b)
{
    if(a.size()==0||b.size()==0)
        return 0;
    if(a[0]==b[0])
        return 1+LCS_recursive(a.substr(1),b.substr(1));
    else 
    {
        int aa =LCS_recursive(a,b.substr(1));
        int bb =LCS_recursive(a.substr(1),b);
        return max(aa,bb);

    }
}
int main()
{
    string a,b;
    cin>>a>>b;
    cout<<LCS_recursive(a,b)<<" <- using brute force \n";
    cout<<LCS_memo(a,b)<<" <- using memoisation \n";
    cout<<LCS_DP(a,b)<<" <- using DP \n";
    return 0;
}
