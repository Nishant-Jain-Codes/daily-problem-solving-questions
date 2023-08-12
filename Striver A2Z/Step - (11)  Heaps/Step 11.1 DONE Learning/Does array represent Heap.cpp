//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    bool isMaxHeap(int a[], int n)
    {
        // Your code goes here
        int parent = 0;
        while (parent < n)
        {
            int leftChild = (2 * parent) + 1;
            int rightChild = (2 * parent) + 2;
            if (leftChild < n && a[leftChild] > a[parent])
            {
                return false;
            }
            if (rightChild < n && a[rightChild] > a[parent])
            {
                return false;
            }
            parent++;
        }
        return true;
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
        int a[4 * n] = {0};
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        Solution ob;
        cout << ob.isMaxHeap(a, n) << endl;
    }
    return 0;
}

// } Driver Code Ends