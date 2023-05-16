// https://practice.geeksforgeeks.org/problems/isomorphic-strings-1587115620/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=isomorphic-strings

//{ Driver Code Starts
// C++ program to check if two strings are isomorphic


#include<bits/stdc++.h>


using namespace std;
#define MAX_CHARS 256

// } Driver Code Ends
class Solution
{
    public:
    //Function to check if two strings are isomorphic.
    bool areIsomorphic(string s, string t)
    {
        
        // Your code here
        unordered_map<char,char> map,map2;
        if(s.length()!=t.length())
            return false;
        for(int i=0;i<s.length();i++){
            char c = s[i];
            char c2 = t[i];
            if((map.find(c)!=map.end() && map[c] != c2) || map2.find(c2)!=map2.end()&&map2[c2]!=c)
                return false;
            else 
                {
                    map[c]=c2;
                    map2[c2]=c;
                }
        }
        return true;
        
    }
};

//{ Driver Code Starts.

// Driver program
int main()
{
    int t;
    cin>>t;
    string s1,s2;
    while (t--) {
        cin>>s1;
        cin>>s2;
        Solution obj;
        cout<<obj.areIsomorphic(s1,s2)<<endl;
    }
    
    return 0;
}
// } Driver Code Ends