//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

// Back-end complete function Template for C++

class Solution
{
public:
    long long solve(vector<int> &bt)
    {
        // code here
        priority_queue<int, vector<int>, greater<int>> pq;
        for (auto x : bt)
        {
            pq.push(x);
        }
        long long totalWT = 0;
        long long cpuTime = 0;
        while (!pq.empty())
        {
            int BT = pq.top();
            pq.pop();
            totalWT += cpuTime;
            cpuTime += BT;
        }
        return totalWT / bt.size();
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
        vector<int> bt(n), p(n);
        for (int i = 0; i < n; i++)
        {
            cin >> bt[i];
        }
        Solution obj;
        long long ans = obj.solve(bt);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends