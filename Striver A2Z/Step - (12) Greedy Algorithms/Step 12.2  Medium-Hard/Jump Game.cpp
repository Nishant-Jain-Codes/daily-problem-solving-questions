//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int canReach(int nums[], int N)
    {
        // code here
        int maxReach = 0;
        for (int i = 0; i < N; i++)
        {
            if (i > maxReach)
                return false;
            maxReach = max(maxReach, i + nums[i]);
            if (maxReach >= N)
                return true;
        }
        return true;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;

        int A[N];

        for (int i = 0; i < N; i++)
            cin >> A[i];

        Solution ob;
        cout << ob.canReach(A, N) << endl;
    }
    return 0;
}
// } Driver Code Ends