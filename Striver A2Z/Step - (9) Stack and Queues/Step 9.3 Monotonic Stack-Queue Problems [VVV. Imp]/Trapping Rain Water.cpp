//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution
{

    // Function to find the trapped water between the blocks.
public:
    long long trappingWater(int arr[], int n)
    {
        // code here
        vector<int> mxL(n,0);
        vector<int> mxR(n,0);
        for(int i=0;i<n;i++){
            if(i==0)
                mxL[i]=arr[i];
            else 
                maxL[i]=max(arr[i],mxL[i-1]);
        }
        for(int i=n-1;i>=0;i--){
            if(i==n-1)
                mxR[i]=arr[i];
            else 
                maxR[i]=max(arr[i],mxR[i+1]);
        }
        long long int ans=0;
        for(int i=0;i<n;i++){
            ans+=min(mxL[i],mxR[i])-arr[i];
        }
        return ans;

    }
};

//{ Driver Code Starts.

int main()
{

    int t;
    // testcases
    cin >> t;

    while (t--)
    {
        int n;

        // size of array
        cin >> n;

        int a[n];

        // adding elements to the array
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        Solution obj;
        // calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
    }

    return 0;
}
// } Driver Code Ends