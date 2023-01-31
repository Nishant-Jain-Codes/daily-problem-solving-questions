//https://practice.geeksforgeeks.org/problems/count-digits5716/1

//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public:
    int evenlyDivides(int N){
        //code here
        int ans=0;
        int Tn = N;
        while(Tn>0){
            int d = Tn%10;
            //cout<<d<<" ";
            Tn/=10;
            if(d==0)
                continue;
            if(N%d==0)
                ans++;
            
        }
        return ans;
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
        cin>>N;
        Solution ob;
        cout << ob.evenlyDivides(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends