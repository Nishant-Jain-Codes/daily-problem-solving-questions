// https://practice.geeksforgeeks.org/problems/minimum-number-of-jumps-1587115620/1


//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// Function to return minimum number of jumps to end of array

class Solution{
  public:
    int minJumps(int arr[], int n){
        // Your code here
        int farthest =0;
        int current = 0;
        int jumps = 0;
        if(n<=1)
            return 0;
        if(arr[0]==0)
            return -1;
        for(int i=0;i<n-1;i++){
            farthest = max(farthest , i+arr[i]);
            if(i==current){
                jumps++;
                current=farthest;
            }
            
        }
        if(current>=n-1)
            return jumps;
        else 
            return -1;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,j;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution obj;
        cout<<obj.minJumps(arr, n)<<endl;
    }
    return 0;
}

// } Driver Code Ends