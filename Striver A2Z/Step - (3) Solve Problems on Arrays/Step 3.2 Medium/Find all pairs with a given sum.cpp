// https://practice.geeksforgeeks.org/problems/find-all-pairs-whose-sum-is-x5808/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=find-all-pairs-whose-sum-is-x

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:

    /*
    !logic
    store all the values of array in map 1 and 2
    check if X-A[i] exists in B 
    if yes mark both as false and push both value in the answer vector
    */
    vector<pair<int,int>> allPairs(int A[], int B[], int N, int M, int X)
    {
        // Your code goes here   
        vector<pair<int,int>> ans;
        unordered_map<int,bool> m1,m2;
        for(int i=0;i<N;i++){
            m1[A[i]]=true;
        }
        for(int i=0;i<M;i++){
            m2[B[i]]=true;
        }
        for(auto x : m1){
            if(x.second&&m2.count(X-x.first)){
                x.second=false;
                m2[X-x.first]=false;
                ans.push_back({x.first,X-x.first});
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
        
    }
};


//{ Driver Code Starts.
int main() {
	long long t;
	cin >> t;
	
	while(t--){
	    int N, M, X;
	    cin >> N >> M >> X;
        int A[N], B[M];
        
	    for(int i = 0;i<N;i++)
	        cin >> A[i];
	    for(int i = 0;i<M;i++)
	        cin >> B[i];
	        
	   Solution ob;
	   vector<pair<int,int>> vp = ob.allPairs(A, B, N, M, X);
	   int sz = vp.size();
        if(sz==0)
        cout<<-1<<endl;
        else{
            for(int i=0;i<sz;i++){
                if(i==0)
                cout<<vp[i].first<<" "<<vp[i].second;
                else
                cout<<", "<<vp[i].first<<" "<<vp[i].second;
            }
            cout<<endl;
        }
	}
	return 0;
}
// } Driver Code Ends