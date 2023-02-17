// https://practice.geeksforgeeks.org/problems/first-and-last-occurrences-of-x3116/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=first-and-last-occurrences-of-x

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


int lower_bound(int *arr,int n,int x){
    int lo=0;
    int hi=n-1;
    while(hi-lo>1){
        int mid = (hi+lo)/2;
        if(arr[mid]<x){
            lo=mid+1;
        }else{
            hi=mid;
        }
    }
    if(arr[lo]>=x)
        return lo;
    if(arr[hi]>=x)
        return hi;
    return n;
    
}
int upper_bound(int *arr ,int n,int x){
    int lo=0;
    int hi=n-1;
    while(hi-lo>1){
        int mid = (hi+lo)/2;
        if(arr[mid]<=x){
            lo=mid+1;
        }else{
            hi=mid;
        }
    } 
    if(arr[lo]>x)
            return lo;
    if(arr[hi]>x)
        return hi;
    return n;
}
vector<int> find(int arr[], int n , int x )
{
    // code here
    int lb = lower_bound(arr,n,x);
    int ub = upper_bound(arr,n,x);
    if(lb!=n && arr[lb]==x)
        return {lb,ub-1};
    else 
        return {-1,-1};
}


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        ans=find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends