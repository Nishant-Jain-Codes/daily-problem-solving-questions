//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    long long maxScore(vector<int> &cardPoints, int N, int k)
    {
        // code here
        long long totalSum = 0;
        for(auto x : cardPoints) totalSum += x;
        long long minSum = totalSum;
        int n = cardPoints.size();
        int windowSize = n - k;

        int si = 0, ei = 0;
        long long curSum =0;
        while(ei<n){
            curSum+=cardPoints[ei];
            if(ei-si+1 == windowSize){
                minSum = min(minSum, curSum);
                curSum-=cardPoints[si];
                si++;
            }
            ei++;
        }
        if(minSum==totalSum)
            minSum =0;
        return totalSum - minSum;    
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

        vector<int> cardPoints(N);
        for (int i = 0; i < N; i++)
            cin >> cardPoints[i];

        Solution obj;
        cout << obj.maxScore(cardPoints, N, k) << endl;
    }
    return 0;
}
// } Driver Code Ends