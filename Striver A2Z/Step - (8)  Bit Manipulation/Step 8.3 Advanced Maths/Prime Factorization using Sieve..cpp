//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution
{
    const int MAX_SIZE =  1e5 + 1e4;
    vector<int> isPrime;

public:
    void sieve()
    {
        isPrime.resize(MAX_SIZE, true);

        for (int i = 2; i * i <= MAX_SIZE; i++)
        {
            if (isPrime[i])
            {
                for (int j = i * i; j <= MAX_SIZE; j += i)
                {
                    isPrime[j] = false;
                }
            }
        }
    }

    vector<int> findPrimeFactors(int N)
    {
        vector<int> ans;
        for (int i = 2; i <= N; i++)
        {
            if (isPrime[i])
            {
                while (N % i == 0)
                {
                    ans.push_back(i);
                    N /= i;
                }
            }
        }

        return ans;
    }
};



//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        int n;
        cin >> n;

        Solution obj;
        obj.sieve();
        vector<int> vec = obj.findPrimeFactors(n);
        for (int i = 0; i < vec.size(); i++) {
            cout << vec[i] << " ";
        }
        cout << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends