// https://practice.geeksforgeeks.org/problems/find-the-element-that-appears-once-in-sorted-array0624/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=find-the-element-that-appears-once-in-sorted-array


//{ Driver Code Starts
// Driver code

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
  public:
    int findOnce(int arr[], int n)
    {
        //code here.
        int lo=0;
        int hi=n-1;
        while(lo<=hi){
            int mid = (hi+lo)/2;
            if(mid==0 && arr[0]!=arr[1])
                return arr[0];
            if(mid==n-1 && arr[n-1]!=arr[n-2])
                return arr[n-1];
            if(arr[mid]!=arr[mid-1]&&arr[mid]!=arr[mid+1])
                    return arr[mid];
            int foundIdx = arr[mid]==arr[mid+1]?mid+1:mid;
            if((foundIdx+1)%2==0){
                lo=mid+1;
            }
            else {
                hi=mid-1;
            }
            
        } 
        return -1; 
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        int A[n];
        for(int i = 0;i < n;i++)
        {
            cin>>A[i];
        }
        
        Solution ob;
        
        int res = ob.findOnce(A,n);
        cout << res << endl;
    }
    
    return 0;
}
// } Driver Code Ends