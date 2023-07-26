//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool lemonadeChange(int N, vector<int> &bills) {
        // code here
         int five =0; 
        int ten =0;
        for(auto bill : bills){
            if(bill == 5)
                five++;
            else if(bill==10){
                if(five>0)
                    {
                        five--;
                        ten++;
                    }
                else
                    return false;
            }
            else if(bill == 20){
                if(ten>0 && five>0){
                    ten--;
                    five--;
                }
                else if(five>=3)
                    five-=3;
                else
                    return false;
            }
        }
        return true;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> bills(N);
        for (int i = 0; i < N; i++) cin >> bills[i];

        Solution obj;
        int ans = obj.lemonadeChange(N, bills);
        if (ans)
            cout << "True" << endl;
        else
            cout << "False" << endl;
    }
    return 0;
}
// } Driver Code Ends