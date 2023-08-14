//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
vector<string> AllParenthesis(int n) ;


// } Driver Code Ends
//User function Template for C++

// N is the number of pairs of parentheses
// Return list of all combinations of balanced parantheses
class Solution
{
    public:
    vector<string> AllParenthesis(int n) 
    {
        // Your code goes here 
        vector<string> ans;
        string output = "";
        helper(n,0,0,output,ans);
        return ans;
    }
    private:
    void helper(int size , int curOpen , int curClosed , string & output , vector<string> & ans){
        if(curOpen==size && curClosed==size){
            ans.push_back(output);
            return;
        }
        if(curOpen<size){
            output.push_back('(');
            helper(size,curOpen+1,curClosed,output,ans);
            output.pop_back();
        }
        if(curClosed<curOpen){
            output.push_back(')');
            helper(size,curOpen,curClosed+1,output,ans);
            output.pop_back();
        }
    }
};

//{ Driver Code Starts.


int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		Solution ob;
		vector<string> result = ob.AllParenthesis(n); 
		sort(result.begin(),result.end());
		for (int i = 0; i < result.size(); ++i)
			cout<<result[i]<<"\n";
	}
	return 0; 
} 

// } Driver Code Ends