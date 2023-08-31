//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> asteroidCollision(int N, vector<int> &asteroids) {
        // code here
        stack<int> st;
        for(auto curAsteroid : asteroids){
            bool collision = false;
            while(!st.empty() && curAsteroid<0 && st.top()>0){
                if(abs(curAsteroid)>st.top()){
                    st.pop();
                }
                else if(abs(curAsteroid) == st.top()){
                    st.pop();
                    collision = true;
                    break;
                }
                else{
                    collision = true;
                    break;
                }

            }
            if(!collision){
                st.push(curAsteroid);
            }
        }
        vector<int> answer(st.size());
        for(int i = st.size()-1; i>=0; i--){
            answer[i] = st.top();
            st.pop();
        }
        return answer;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> asteroids(N);
        for (int i = 0; i < N; i++) cin >> asteroids[i];

        Solution obj;
        vector<int> ans = obj.asteroidCollision(N, asteroids);
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends