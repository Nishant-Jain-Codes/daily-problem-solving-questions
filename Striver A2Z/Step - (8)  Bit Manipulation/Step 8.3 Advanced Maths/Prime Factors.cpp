//{ Driver Code Starts


#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
public:
    vector<int> AllPrimeFactors(int N) {
        vector<int> ans;
        for (int p = 2; p * p <= N; p++) {
            bool inserted = false;
            while (N % p == 0) {
                if(!inserted)
                {
                    ans.push_back(p);
                    inserted = true;
                }
                N /= p;
            }
        }
        if (N > 1) {
            ans.push_back(N);
        }
        return ans;
    }
};



//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		long long int N;
		cin >> N;
		Solution ob;
		vector<int>ans = ob.AllPrimeFactors(N);
		for(auto i: ans)
			cout << i <<" ";
		cout <<"\n";
	}  
	return 0;
}
// } Driver Code Ends