//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    int subarrayCount(vector<int> &nums, int N, int k)
    {
        // code here
        auto atMostK = [&nums, N](int k)
        {
            if (k <= 0)
                return 0;
            vector<int> m(N + 1, 0);
            int unique = 0;
            int i = 0, j = 0, ans = 0;

            while (j < nums.size())
            {
                m[nums[j]]++;
                if (m[nums[j]] == 1)
                    unique++;
                j++;
                while (unique > k)
                {
                    m[nums[i]]--;
                    if (m[nums[i]] == 0)
                        unique--;
                    i++;
                }
                if (unique <= k)
                {
                    ans += (j - i);
                }
            }
            return ans;
        };
        return atMostK(k) - atMostK(k - 1);
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, k;
        cin >> N >> k;

        vector<int> arr(N);
        for (int i = 0; i < N; i++)
            cin >> arr[i];

        Solution obj;
        cout << obj.subarrayCount(arr, N, k) << endl;
    }
    return 0;
}
// } Driver Code Ends