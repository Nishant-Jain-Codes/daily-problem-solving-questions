//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    // Function to calculate the span of stockâ€™s price for all n days.
    vector<int> calculateSpan(int price[], int n)
    {
        // Your code here
        vector<int> ngeToLeft = nearestGreatestToLeft(price, n); // index array
        vector<int> answer;
        for (int i = 0; i < n; i++)
        {
            answer.push_back(i - ngeToLeft[i]);
        }
        return answer;
    }

private:
    vector<int> nearestGreatestToLeft(int arr[], int n)
    {
        vector<int> answer;
        stack<int> st;
        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && arr[st.top()] <= arr[i])
                st.pop();
            if (st.empty())
                answer.push_back(-1);
            else
                answer.push_back(st.top());
            st.push(i);
        }
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
        int n;
        cin >> n;
        int i, a[n];
        for (i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        Solution obj;
        vector<int> s = obj.calculateSpan(a, n);

        for (i = 0; i < n; i++)
        {
            cout << s[i] << " ";
        }
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends