//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    struct comp
    {
        bool operator()(pair<int, int> &p1, pair<int, int> &p2)
        {
            if (p1.first == p2.first)
           {
               return p1.second > p2.second;
            }
            return p1.first < p2.first;
        }
    };
    vector<int> printKClosest(vector<int> arr, int n, int k, int x)
    {
        // code here
        priority_queue<pair<int, int>, vector<pair<int, int>>, comp> pq;
        vector<int> answer;
        for (int i = 0; i < arr.size(); i++)
        {
            if((arr[i]-x)==0)   
                continue;
            pq.push({abs(arr[i] - x), arr[i]});
            if (pq.size() > k)
            {
                //   answer.push_back(pq.top().second);
                pq.pop();
            }
        }
        while (!pq.empty())
        {
            answer.push_back(pq.top().second);
            pq.pop();
        }
         reverse(answer.begin(),answer.end());
        return answer;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, x;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cin >> k >> x;
        Solution ob;
        auto ans = ob.printKClosest(arr, n, k, x);
        for (auto e : ans) {
            cout << e << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends