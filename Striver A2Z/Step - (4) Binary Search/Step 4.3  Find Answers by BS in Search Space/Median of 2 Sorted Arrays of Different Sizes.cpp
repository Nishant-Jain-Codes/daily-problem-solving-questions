// https://practice.geeksforgeeks.org/problems/median-of-2-sorted-arrays-of-different-sizes/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=median-of-2-sorted-arrays-of-different-sizes


//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
double MedianOfArrays(vector<int>& array1, vector<int>& array2);


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    double MedianOfArrays(vector<int>& nums1, vector<int>& nums2)
    {
        // Your code goes here
    if(nums1.size()>nums2.size())
            return MedianOfArrays(nums2,nums1);
        int n1 = nums1.size();
        int n2 = nums2.size();
        int lo = 0;
        int hi = n1;
        while(lo<=hi){
            int cut1 = (lo+hi)>>1;
            int cut2 = ((n1+n2+1)/2)-cut1;
            int left1 = cut1==0?INT_MIN : nums1[cut1-1];
            int left2 = cut2==0?INT_MIN : nums2[cut2-1];
            int right1 = cut1==n1?INT_MAX:nums1[cut1];
            int right2 = cut2==n2?INT_MAX:nums2[cut2];

            if(left1<=right2 && left2<=right1){
                if((n1+n2)%2 == 0){
                    return ((max(left1,left2) + min(right1,right2))/2.0);
                }
                else {
                    return max(left1,left2);
                }
            }
            else if(left1>right2){
                hi=cut1-1;
            }
            else {
                lo=cut1+1;
            }
        }
        return 0.0;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m,n;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        cin>>n;
        vector<int> array2(n);
        for (int i = 0; i < n; ++i){
            cin>>array2[i];
        }
        Solution ob;
        cout<<ob.MedianOfArrays(array1, array2)<<endl;
    }
    return 0; 
}



// } Driver Code Ends