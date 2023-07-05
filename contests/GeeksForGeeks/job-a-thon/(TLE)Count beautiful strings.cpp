//{ Driver Code Starts
//Initial Template for C++

#include "bits/stdc++.h"
using namespace std;

// } Driver Code Ends
//User function Template for C++
class stringCompare {
public:

    int hasChar[26];
    int isbeautifull;
    char oddChar;
    stringCompare(){
        memset(hasChar,0,sizeof(hasChar));
        oddChar = 'a';
        isbeautifull = 0;
    }
    stringCompare(string s){
        memset(hasChar,0,sizeof(hasChar));
        for(auto ch : s){
            hasChar[ch-'a']++;
        }
        int oddCount = 0;
        for(int i=0;i<26;i++){
            if(hasChar[i]%2!=0){
                oddCount++;
                oddChar = i+'a';
            }
        }
        isbeautifull = oddCount==1;
    }
    bool doesHasChar(char ch){
        return hasChar[ch-'a']>0;
    }
};
bool canBeBeautiful(stringCompare &a, stringCompare &b){
    int oddc=0;
    for(int i=0;i<26;i++){
        oddc += ((a.hasChar[i]+b.hasChar[i])%2!=0);
    }
    return oddc<=1;
}
class Solution{   
public:
    long long noOfPairs(vector<string> &box)
    {
        // Write your code here.
        vector<stringCompare> boxCompare(box.size());
        for(int i=0;i<box.size();i++){
            boxCompare[i] = stringCompare(box[i]);
        }
        long long ans = 0;
        for(int i=0;i<box.size();i++){
            for(int j=i+1;j<box.size();j++){
                if(boxCompare[i].isbeautifull && boxCompare[j].isbeautifull){
                    if(boxCompare[i].oddChar == boxCompare[j].oddChar){
                        ans++;
                    }
                    else if(boxCompare[i].doesHasChar(boxCompare[j].oddChar) ^ boxCompare[j].doesHasChar(boxCompare[i].oddChar) ){
                        ans++;
                    }
                }
                else{
                    if(canBeBeautiful(boxCompare[i],boxCompare[j])){
                        ans++;
                    }
                }
            }
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
        int n;
        cin>>n;
        vector<string>box(n);
        for(int i=0;i<n;i++)
            cin>>box[i];
        Solution ob;
        long long ans=ob.noOfPairs(box);
        cout<<ans<<endl;
    }
}
// } Driver Code Ends