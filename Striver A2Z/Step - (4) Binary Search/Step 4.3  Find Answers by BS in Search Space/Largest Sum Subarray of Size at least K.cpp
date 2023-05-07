// https://practice.geeksforgeeks.org/problems/largest-sum-subarray-of-size-at-least-k3121/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=largest-sum-subarray-of-size-at-least-k


//{ Driver Code Starts
// C++ program to find largest subarray sum with
// at-least k elements in it.
#include <bits/stdc++.h>
using namespace std;

long long int maxSumWithK(long long int a[], long long int n, long long int k);

// Driver code
int main() {
    long long int t;
    cin >> t;
    while (t--) {
        long long int n, k, i;
        cin >> n;
        long long int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        cin >> k;
        cout << maxSumWithK(a, n, k) << endl;
    }
    return 0;
}

// } Driver Code Ends



long long int maxSumWithK(long long int a[], long long int n, long long int k) {
    using ll=long long int;
ll curr_sum=0;
for(int i=0;i<k;i++)
{
    curr_sum+=a[i];
}
ll ans=curr_sum;
ll left_sum=0;
ll left_min=0;
for(int i=k;i<n;i++)
{
    curr_sum+=a[i];
    left_sum+=a[i-k];
    left_min=min(left_min,left_sum);
    ans=max(ans,curr_sum-left_min);
}
return ans;
}