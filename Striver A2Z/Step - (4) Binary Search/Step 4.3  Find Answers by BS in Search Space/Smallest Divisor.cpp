// https://practice.geeksforgeeks.org/problems/smallest-divisor/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=smallest-divisor

//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  int divSum(vector<int>& nums,int threshold,int divisor){
        int sum =0;
        for(auto x : nums){
            sum+= ceil((x*1.0)/divisor);
            if(sum>threshold)
                return false;
        }
        return sum<=threshold;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {

        // Write your code here.
    int lo=1;
        int hi=1e7;
        while(hi-lo>1){
            int mid = (hi+lo)/2;
            if(divSum(nums,threshold,mid)){
                hi=mid;
            }
            else 
             {
                lo = mid+1;
             }   
        }
        if(divSum(nums,threshold,lo))
            return lo;
        if(divSum(nums,threshold,hi))
            return hi;
        return -1;}
};


//{ Driver Code Starts.
int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        int n, k;
        cin >> n >> k;
        vector<int> vec(n);
        for (int i = 0; i < n; i++) cin >> vec[i];

        Solution obj;
        cout << obj.smallestDivisor(vec, k) << endl;
        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends