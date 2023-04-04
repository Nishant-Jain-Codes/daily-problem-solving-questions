// https://practice.geeksforgeeks.org/problems/maximum-product-subarray3604/0?qa-rewrite=3336/print-all-valid-combinations-of-ip-address&show=3350&utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=maximum-product-subarray
//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution
{
public:
    // Function to find maximum product subarray
    // Function to find maximum product subarray
    long long maxProduct(vector<int> arr, int n)
    {
        long long cur_max = arr[0]; // initialize current max to first element
        long long cur_min = arr[0]; // initialize current min to first element
        long long ans = arr[0];     // initialize answer to first element
        for (int i = 1; i < n; i++)
        {                                                                                   // loop through the array starting from the second element
            long long temp_max = max((long long)arr[i], max(cur_maxarr[i], cur_minarr[i])); // calculate temporary maximum
            cur_min = min((long long)arr[i], min(cur_maxarr[i], cur_minarr[i]));            // update current minimum
            cur_max = temp_max;                                                             // update current maximum
            ans = max(ans, cur_max);                                                        // update answer if current maximum is greater
        }
        return ans; // return maximum product subarray
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, i;
        cin >> n;
        vector<int> arr(n);
        for (i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.maxProduct(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends