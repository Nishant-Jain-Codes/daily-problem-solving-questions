//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
#include <string>

using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    private:
    void recursive(int curIdx,const string & digits ,
    unordered_map<char,string> & dict , vector<string> & ans){
        if(curIdx>=digits.size())
            return ;

        if(curIdx == digits.size()-1){
            vector<string> temp;
            string curVals = dict[digits[curIdx]];
            for(auto& ch : curVals){
                temp.push_back( string(1, ch));
            }
            ans = temp;
            return;
        }
        recursive(curIdx+1,digits,dict,ans);
        vector<string> temp;
        string curVals = dict[digits[curIdx]];
        for(auto & ch : curVals){
            for(auto & str : ans){
                temp.push_back(ch+str);
            }
        }
        ans = temp;
    }

    public:
    //Function to find list of all words possible by pressing given numbers.
    vector<string> possibleWords(int a[], int N)
    {
        //Your code here
        unordered_map<char, string> dict = {
            {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"},
            {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}
        };
        string digits = "";
        for(int i=0;i<N;i++){
            digits.push_back(a[i]+'0');
        }
        vector<string> ans;
        recursive(0, digits, dict, ans);
        return ans;
    }
};



//{ Driver Code Starts.

int main() {
  
	int T;
	
	cin >> T; //testcases
	
	while(T--){ //while testcases exist
	   int N;
	    
	   cin >> N; //input size of array
	   
	   int a[N]; //declare the array
	   
	   for(int i =0;i<N;i++){
	       cin >> a[i]; //input the elements of array that are keys to be pressed
	   }
	   
	   Solution obj;
	   
	  vector <string> res = obj.possibleWords(a,N);
	  for (string i : res) cout << i << " ";
	   cout << endl;
	}
	
	return 0;
}
// } Driver Code Ends