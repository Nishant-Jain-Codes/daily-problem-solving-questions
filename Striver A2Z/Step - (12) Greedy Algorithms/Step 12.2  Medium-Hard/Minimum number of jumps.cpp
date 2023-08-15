//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// Function to return minimum number of jumps to end of array

class Solution
{
public:
    int minJumps(int nums[], int n)
    {
        // Your code here
        int maxReach = 0;
        for (int i = 0; i < n; i++)
        {
            if (i > maxReach)
                return -1;
            maxReach = max(maxReach, i + nums[i]);
            if (maxReach >= n)
                break;
        }
        int jumps = 0, currEnd = 0, currFarthest = 0;
        for (int i = 0; i < n - 1; i++)
        {
            currFarthest = max(currFarthest, i + nums[i]);
            if (i == currEnd)
            {
                jumps++;
                currEnd = currFarthest;
            }
        }
        return jumps;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, i, j;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution obj;
        cout << obj.minJumps(arr, n) << endl;
    }
    return 0;
}

// } Driver Code Ends