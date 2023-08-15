//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution
{

public:
    struct comp
    {
        bool operator()(pair<int, int> &a, pair<int, int> &b)
        {
            return a.first > b.first;
        }
    };
    vector<int> replaceWithRank(vector<int> &arr, int N)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, comp> pq;
        vector<int> answer(arr.size());
        for (int i = 0; i < arr.size(); i++)
        {
            pq.push({arr[i], i});
        }
        int rank = 0;
        int prevNo = -1;
        while (!pq.empty())
        {
            auto [CurrNo, index] = pq.top();
            pq.pop();
            if (prevNo != CurrNo)
            {
                rank++;
            }
            answer[index] = rank;
            prevNo = CurrNo;
        }
        return answer;
    }
};

//{ Driver Code Starts.
int main()
{
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--)
    {
        // Input

        int n;
        cin >> n;
        vector<int> vec(n);
        for (int i = 0; i < n; i++)
            cin >> vec[i];

        Solution obj;
        vector<int> ans = obj.replaceWithRank(vec, n);
        for (int i = 0; i < n; i++)
            cout << ans[i] << " ";
        cout << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends