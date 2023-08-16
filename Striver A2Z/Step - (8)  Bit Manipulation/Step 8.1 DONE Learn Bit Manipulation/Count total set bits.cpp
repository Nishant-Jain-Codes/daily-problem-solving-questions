//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    // n: input to count the number of set bits
    // Function to return sum of count of set bits in the integers from 1 to n.
    int countSetBits(int n)
    {
        // Your logic here
        if(n==0)
            return 0;
        int x = largestPowOf2(n);
        int BitsTill2x = x*(1<<(x-1));// 2^x * x
        int msb2xToN = n - (1<<x) + 1; // n - 2^x + 1
        int rest = countSetBits(n - (1<<x));// n - 2^x
        return BitsTill2x + msb2xToN + rest;
    }
private : 
    // function to find the largest power of 2 less than or equal to n
    // O(logn)
    int largestPowOf2(int n ){
        int x = 0;
        while((1<<x) <= n){
            x++;
        }
        return x-1;
    }
};

//{ Driver Code Starts.

// Driver code
int main()
{
    int t;
    cin >> t;   // input testcases
    while (t--) // while testcases exist
    {
        int n;
        cin >> n; // input n
        Solution ob;
        cout << ob.countSetBits(n) << endl; // print the answer
    }
    return 0;
}

// } Driver Code Ends