//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++
class customComp{
    public : 
    //value,index
    bool operator()(const pair<int,int> &p1,const pair<int,int> &p2){
        if(p1.first==p2.first){
            return p1.second<p2.second;
        }
        return p1.first<p2.first;
    }
};
class Solution
{
public:
    // Function to find maximum of each subarray of size k.
    vector<int> max_of_subarrays(int *arr, int n, int k)
    {
        vector<int> ans;
        int i=0,j=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,customComp> pq;
        while(j<n){
            pq.push({arr[j],j});
            if(j-i+1<k){
                j++;
            }
            else {
                while(!pq.empty() && pq.top().second<i){
                    pq.pop();
                }
                if(pq.empty()){
                    ans.push_back(-1);
                }
                else{
                    ans.push_back(pq.top().first);
                }
                i++;
                j++;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{

    int t;
    cin >> t;

    while (t--)
    {

        int n, k;
        cin >> n >> k;

        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution ob;
        vector<int> res = ob.max_of_subarrays(arr, n, k);
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;
    }

    return 0;
}
// } Driver Code Ends