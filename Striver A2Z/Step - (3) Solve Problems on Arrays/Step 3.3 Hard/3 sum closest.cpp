// https://practice.geeksforgeeks.org/problems/3-sum-closest/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=3-sum-closest


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int closest3Sum(int nums[], int n, int X)
    {
        // code here
        int closest = INT_MAX;
        int MinDif = INT_MAX;
        sort(nums,nums+n);
        for(int i=0;i<n;i++){
            int first = nums[i];
            int si = i+1;
            int ei = n-1;
            while(si<ei){
                int curSum = nums[si]+nums[ei]+first;
                int curDif = abs(curSum-X);
                 if(curDif < MinDif){
                    MinDif = curDif;
                    closest = curSum;
                }
                if(curSum<X)
                    si++;
                else 
                    ei--;
            }

        }
        return closest;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        int Arr[N];
        for(int i=0;i<N;i++)    
            cin>>Arr[i];
        int X;
        cin>>X;
        Solution obj;
        cout<<obj.closest3Sum(Arr, N, X)<<endl;
    }
    return 0;
}
// } Driver Code Ends