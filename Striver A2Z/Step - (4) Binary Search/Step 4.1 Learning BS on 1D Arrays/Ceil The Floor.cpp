// https://practice.geeksforgeeks.org/problems/ceil-the-floor2802/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=ceil-the-floor

//{ Driver Code Starts

#include <bits/stdc++.h>

using namespace std;

pair<int, int> getFloorAndCeil(int arr[], int n, int x);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        auto ans = getFloorAndCeil(arr, n, x);
        cout << ans.first << " " << ans.second << "\n";
    }
    return 0;
}

// } Driver Code Ends

// for unsorted array O(n)
pair<int, int> getFloorAndCeil(int arr[], int n, int x) {
    int fl=INT_MIN,ce=INT_MAX;
    for(int i=0;i<n;i++){
        if(arr[i]>fl && arr[i]<=x)
            fl=arr[i];
        if(arr[i]<ce && arr[i]>=x)
            ce = arr[i];
    }
    if(fl==INT_MIN)
        fl=-1;
    if(ce==INT_MAX)
        ce=-1;
        return {fl,ce};
}
//for sorted array  O(logn)
/*
pair<int, int> getFloorAndCeil(int arr[], int n, int x) {
    // code here
    int fl=-1,ce=-1;
    int si=0,ei=n-1;
    while(si<ei){
        int mid = si + ((ei-si)/2);
        if(arr[mid]>x){
            ei=mid-1;
        }
        else if(arr[mid]<x){
            fl=arr[mid];
            si=mid+1;
        }else{
            fl=arr[mid];
            break;
        }
    }
    si=0;
    ei=n-1;
    while(si<ei){
        int mid = si + ((ei-si)/2);
        if(arr[mid]>x){
            ce=arr[mid];
            ei=mid-1;
        }
        else if(arr[mid]<x){
            si=mid+1;
        }else{
            ce=arr[mid];
            break;
        }
    }
    return {fl,ce};
}*/
