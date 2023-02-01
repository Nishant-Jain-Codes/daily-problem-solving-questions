// https://practice.geeksforgeeks.org/problems/remove-duplicate-elements-from-sorted-array/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=remove-duplicate-elements-from-sorted-array

//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
public:
    int remove_duplicate(int nums[],int n){
        // code here
       int uIdx=0;//unique index
       int tIdx=0;
       while(tIdx<n-1){
           while(nums[tIdx]==nums[tIdx+1])
           {
               tIdx++;
           }
           nums[uIdx++]=nums[tIdx++];
       }
       if(nums[uIdx-1]!=nums[n-1])
       {
           nums[uIdx++]=nums[n-1];
       }
       return uIdx;
    }
};

//{ Driver Code Starts.
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N;
        cin>>N;
        int a[N];
        for(int i=0;i<N;i++)
        {
            cin>>a[i];
        }
    Solution ob;
    int n = ob.remove_duplicate(a,N);

    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
    }
}
// } Driver Code Ends