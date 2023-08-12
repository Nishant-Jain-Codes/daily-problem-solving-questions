//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to return k largest elements from an array.
    vector<int> kLargest(int nums[], int n, int k)
    {
        // code here
         priority_queue<int, vector<int>, greater<int> > pq; // min heap
        for(int i=0;i<n;i++){
            pq.push(nums[i]);
            if(pq.size()>k){
                pq.pop();
            }
        }
        vector<int> answer;
        while(!pq.empty()){
            answer.push_back(pq.top());
            pq.pop();
        }
        reverse(answer.begin(), answer.end());
        return answer;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        
        int arr[n];
        for(int i = 0; i < n;i++)
            cin>>arr[i];
        Solution ob;
        vector<int> result = ob.kLargest(arr, n, k);
        for (int i = 0; i < result.size(); ++i)
            cout<<result[i]<<" ";
        cout << endl;
        
    }
    return 0;
}

// } Driver Code Ends