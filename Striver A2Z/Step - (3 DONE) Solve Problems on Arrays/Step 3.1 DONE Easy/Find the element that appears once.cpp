// https://practice.geeksforgeeks.org/problems/element-appearing-once2552/0?company[]=Qualcomm&company[]=Qualcomm&difficulty[]=1&page=1&query=company[]Qualcommdifficulty[]1page1company[]Qualcomm&utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=element-appearing-once

//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	/*
	// method 1
	int search(int arr[], int N){
	    //code
	    for(int i=0;i<N-1;i+=2)
	    {
	        if(arr[i]!=arr[i+1])
	            return arr[i];
	    }
	    return arr[N-1];
	}
	*/
	// method 2
	int search(int arr[], int N){
	    //code
	    int ans=0;
	    for(int i=0;i<N;i++)
	    {
	        ans=ans^arr[i];
	    }
	    return ans;
	}
};

//{ Driver Code Starts.

// Driver program
int main()
{
    int t,len;
    cin>>t;
    while(t--)
    {
        cin>>len;
        int arr[len];
        for(int i=0;i<len;i++){
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.search(arr, len)<<'\n';
    }
    return 0;
}

// } Driver Code Ends