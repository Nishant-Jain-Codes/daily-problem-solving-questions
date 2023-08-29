//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int sumSubarrayMins(int N, vector<int> &arr)
    {
        // code here
        vector<int> smlLeft = smallerToLeft(arr);
        vector<int> smlRight = smallerToRight(arr);

        int answer = 0;
        const int mod = 1e9 + 7;
        for (int i = 0; i < arr.size(); i++)
        {
            int leftNo = i - smlLeft[i];
            int rightNo = smlRight[i] - i;
            answer = (answer + (static_cast<long long int>(leftNo) * rightNo * arr[i]) % mod) % mod;
        }
        return answer;
    }

private:
    vector<int> smallerToLeft(vector<int> &arr)
    {
        vector<int> answer;
        stack<int> st;
        for (int i = 0; i < arr.size(); i++)
        {
            while (!st.empty() && arr[st.top()] > arr[i])
            {
                st.pop();
            }
            if (st.empty())
                answer.push_back(-1);
            else
                answer.push_back(st.top());
            st.push(i);
        }
        return answer;
    }
    vector<int> smallerToRight(vector<int> &arr)
    {
        vector<int> answer;
        stack<int> st;
        for (int i = arr.size() - 1; i >= 0; i--)
        {
            while (!st.empty() && arr[st.top()] >= arr[i])
            {
                st.pop();
            }
            if (st.empty())
                answer.push_back(arr.size());
            else
                answer.push_back(st.top());
            st.push(i);
        }
        reverse(answer.begin(), answer.end());
        return answer;
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

        vector<int> arr(N);
        for (int i = 0; i < N; i++)
            cin >> arr[i];

        Solution obj;
        cout << obj.sumSubarrayMins(N, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends