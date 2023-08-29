class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        vector<int> smlLeft = smallerToLeft(arr);
        vector<int> smlRight = smallerToRight(arr);
        // for(int i=0;i<arr.size();i++){
        //     cout<<smlLeft[i]<<" ";
        // }
        // cout<<endl;
        // for(int i=0;i<arr.size();i++){
        //     cout<<smlRight[i]<<" ";
        // }
        // cout<<endl;
        int answer = 0;
        const int mod = 1e9 + 7;
        for(int i=0;i<arr.size();i++){
            int leftNo = i-smlLeft[i];
            int rightNo = smlRight[i]-i;
            // cout<<arr[i]<<" "<<leftNo<<" "<<rightNo<<" "<<endl;
answer = (answer + (static_cast<long long int>(leftNo) * rightNo * arr[i]) % mod) % mod;
        }
        return answer;
    }
private: 
    vector<int> smallerToLeft(vector<int> & arr){
        vector<int> answer;
        stack<int> st;
        for(int i=0;i<arr.size();i++){
            while(!st.empty() && arr[st.top()]>arr[i]){
                st.pop();
            }
            if(st.empty())
                answer.push_back(-1);
            else
                answer.push_back(st.top());
            st.push(i);
        }
        return answer;
    }
    vector<int> smallerToRight(vector<int> & arr){
        vector<int> answer;
        stack<int> st;
        for(int i=arr.size()-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            if(st.empty())
                answer.push_back(arr.size());
            else
                answer.push_back(st.top());
            st.push(i);
        }
        reverse(answer.begin(), answer.end());
        return answer;
    }
};