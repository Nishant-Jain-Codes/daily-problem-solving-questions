// https://practice.geeksforgeeks.org/problems/good-numbers4629/1

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
private:
    bool isGoodNumber(int i ,int D ,int sum){
        if(i == 0){
            return true ;
        }
        int digit = i %10;
        if(digit == D ){
            return false;
        }
        if(sum == -1){
            return isGoodNumber(i/10 , D , digit);
        }
        
        if(digit > sum){
            return isGoodNumber(i/10 , D , sum+digit);
        }
        return false ;
    }

public:
    vector<int> goodNumbers(int L, int R, int D) {
        vector<int> answer;
        for (int i = L; i <= R; i++) {
            bool sol = isGoodNumber(i, D, -1);
            if (sol) {
                answer.push_back(i);
            }
        }
        return answer;
    }
};




//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int L, R, D;
        cin >> L >> R >> D;
        Solution ob;
        vector<int> ans = ob.goodNumbers(L, R, D);
        for (auto u : ans) cout << u << " ";
        cout << "\n";
    }
}
// } Driver Code Ends