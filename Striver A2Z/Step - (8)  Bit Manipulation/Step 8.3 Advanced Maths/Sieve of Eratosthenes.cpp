//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++
class Solution
{
public:
    vector<int> sieveOfEratosthenes(int N)
    {
        // Write Your Code here
        vector<bool> isPrime(N+1,true);
        vector<int> ans ;
        int p=2;
        while(p*p<=N){
            if(isPrime[p]){
                for(int i=p*p;i<=N;i+=p){
                    isPrime[i]=false;
                }
            }
            p++;
        }
        for(int i=2;i<=N;i++){
            if(isPrime[i]){
                ans.push_back(i);
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
        int N;
        cin>>N;
        Solution ob;
        vector<int> primes  = ob.sieveOfEratosthenes(N);
        for(auto prime : primes) {
            cout<< prime <<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends