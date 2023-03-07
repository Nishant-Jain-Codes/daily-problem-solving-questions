//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int searchInsertK(vector<int>Arr, int N, int k)
    {
        // code here
        int lb=-1;
        int si=0,ei=N-1;
        while(si<=ei){
            int mid = si + ((ei-si)/2);
            if(Arr[mid]>k){
                ei=mid-1;
            }else if(Arr[mid]<k){
                lb=mid;
                si=mid+1;
            }
            else 
                return mid;
        }
        return lb+1;
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
        vector<int>Arr(N);
        for(int i=0;i<N;i++)    
            cin>>Arr[i];
        int k;
        cin>>k;
        Solution obj;
        cout<<obj.searchInsertK(Arr, N, k)<<endl;
    }
    return 0;
}
// } Driver Code Ends