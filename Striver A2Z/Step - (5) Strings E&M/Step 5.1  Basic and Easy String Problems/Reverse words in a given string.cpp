// https://practice.geeksforgeeks.org/problems/reverse-words-in-a-given-string5459/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=reverse-words-in-a-given-string

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string s) 
    { 
        // code here 
        vector<string> buff;
        string temp="";
        for(int i=0;i<s.length();i++){
            if(s[i]=='.'){
                if(!temp.empty())
                    buff.push_back(temp);
                temp="";
            }else{
                temp.push_back(s[i]);
            }
        }
        if(temp.length()!=0){
            buff.push_back(temp);
        }
        reverse(buff.begin(),buff.end());
        string ans;
        for(int i =0; i<buff.size();i++){
            ans+= (buff[i]);
            if(i+1!=buff.size())
                ans+='.';
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
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}
// } Driver Code Ends