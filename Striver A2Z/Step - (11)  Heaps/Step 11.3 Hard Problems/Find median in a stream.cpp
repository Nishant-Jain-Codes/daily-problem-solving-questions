//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
private:
    priority_queue<int> left;
    priority_queue<int, vector<int>, greater<int>> right;

public:
    // Function to insert heap.
    void insertHeap(int &num)
    {
        if (left.empty())
            left.push(num);
        else if (left.top() <= num)
            right.push(num);
        else
        {
            left.push(num);
        }
        balanceHeaps();
    }

    // Function to balance heaps.
    void balanceHeaps()
    {
        if (std::abs(int(left.size() - right.size())) > 1)
        {
            if (left.size() > right.size())
            {
                right.push(left.top());
                left.pop();
            }
            else
            {
                left.push(right.top());
                right.pop();
            }
        }
    }

    // Function to return Median.
    double getMedian()
    {
        if (left.size() == right.size())
            return (left.top() + right.top()) / 2.0;
        if (left.size() > right.size())
            return left.top();
        else
            return right.top();
    }
};

//{ Driver Code Starts.

int main()
{
    int n, x;
    int t;
    cin >> t;
    while (t--)
    {
        Solution ob;
        cin >> n;
        for (int i = 1; i <= n; ++i)
        {
            cin >> x;
            ob.insertHeap(x);
            cout << floor(ob.getMedian()) << endl;
        }
    }
    return 0;
}
// } Driver Code Ends