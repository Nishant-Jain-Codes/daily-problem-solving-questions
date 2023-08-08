//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution2
{
public:
    int totalFruit(vector<int> &fruits)
    {
        return longestSubarrayWithAtmostKDistinct(fruits, 2);
    }

private:
    int longestSubarrayWithAtmostKDistinct(vector<int> &arr, int k)
    {
        unordered_map<int, int> hash;
        int i = 0, j = 0, ans = 0;
        while (j < arr.size())
        {
            hash[arr[j]]++;
            if (hash.size() <= k)
            {
                ans = max(ans, j - i + 1);
                j++;
            }
            else if (hash.size() > k)
            {
                while (hash.size() > k)
                {
                    hash[arr[i]]--;
                    if (hash[arr[i]] == 0)
                        hash.erase(arr[i]);
                    i++;
                }
                j++;
            }
        }
        return ans;
    }
};

// } Driver Code Ends
class Solution {
  public:
    int totalFruits(int N, vector<int> &fruits) {
        Solution2 s;
        return s.totalFruit(fruits);
    }
};




//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> fruits(N);
        for (int i = 0; i < N; i++) cin >> fruits[i];
        Solution obj;
        cout << obj.totalFruits(N, fruits) << endl;
    }
    return 0;
}

// } Driver Code Ends