//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to return the sorted array.
    vector<int> nearlySorted(int array[], int n, int k)
    {
        // Your code here
        priority_queue<int, vector<int>, greater<int>> pq;
        vector<int> answer;
        for (int i = 0; i < n; i++)
        {
            pq.push(array[i]);
            if (pq.size() > k)
            {
                answer.push_back(pq.top());
                pq.pop();
            }
        }
        while (!pq.empty())
        {
            answer.push_back(pq.top());
            pq.pop();
        }
        return answer;
    }
};

//{ Driver Code Starts.

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int num, K;
        cin >> num >> K;

        int arr[num];
        for (int i = 0; i < num; ++i)
        {
            cin >> arr[i];
        }
        Solution ob;
        vector<int> res = ob.nearlySorted(arr, num, K);
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";

        cout << endl;
    }

    return 0;
}

// } Driver Code Ends