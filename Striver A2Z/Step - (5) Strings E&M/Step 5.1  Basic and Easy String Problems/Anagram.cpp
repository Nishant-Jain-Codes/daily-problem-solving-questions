// https://practice.geeksforgeeks.org/problems/anagram-1587115620/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=anagram

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function is to check whether two strings are anagram of each other or not.
    bool isAnagram(string s, string t){
        
        // Your code here
        unordered_map<char,int> sMap,tMap;
        for(auto c : s){
            sMap[c]++;
        }
        for(auto c : t){
            tMap[c]++;
        }
        for(auto x : sMap){
            if(x.second != tMap[x.first])
                return false;
        }
        for(auto x : tMap){
            if(x.second != sMap[x.first])
                return false;
        }
        return true ;
        
    }

};

//{ Driver Code Starts.

int main() {
    
    int t;

    cin >> t;

    while(t--){
        string c, d;

        cin >> c >> d;
        Solution obj;
        if(obj.isAnagram(c, d)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

}

// } Driver Code Ends