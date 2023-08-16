//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    long long divide(long long dividend, long long divisor)
    {
        int sign = (dividend < 0) ^ (divisor < 0) ? -1 : 1;
        dividend = abs(dividend);
        divisor = abs(divisor);

        long long quotient = 0;
        while (dividend >= divisor)
        {
            long long tempDivisor = divisor;
            long long multiple = 1;

            while (dividend >= (tempDivisor << 1))
            {
                tempDivisor <<= 1;
                multiple <<= 1;
            }

            dividend -= tempDivisor;
            quotient += multiple;
        }

        return sign * quotient;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;

    while (t--)
    {

        long long a, b;
        cin >> a >> b;

        Solution ob;
        cout << ob.divide(a, b) << "\n";
    }

    return 0;
}

// } Driver Code Ends