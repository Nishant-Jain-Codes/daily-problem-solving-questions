//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<string> all_longest_common_subsequences(string s, string t)
    {
        // Code here
        vector<string> answer;
        string output = "";
        recursion(s.length()-1,t.length()-1,s, t, output, answer);
        return answer;
    }
private:
//! not giving proper answer
    void recursion(int idxS,int idxT,const string s, const string t,string & output , vector<string> & answer){
        if(idxS<0||idxT<0){
            if(output.length()==0)
                return;
            int curMaxLen = answer.empty() ? 0 : answer[0].length();
            if(output.length()>curMaxLen){
                answer.clear();
                answer.push_back(output);
            }
            else if(output.length()==curMaxLen){
                answer.push_back(output);
            }
            return;
        }
        if(s[idxS]==t[idxT]){
            output.push_back(s[idxS]);
            recursion(idxS-1,idxT-1,s,t,output,answer);
            output.pop_back();
        }
        else{
            recursion(idxS-1,idxT,s,t,output,answer);
            recursion(idxS,idxT-1,s,t,output,answer);
        }
    }
};



//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	string s, t;
    	cin >> s >> t;
    	Solution ob;
    	vector<string> ans = ob.all_longest_common_subsequences(s, t);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}


// } Driver Code Ends