class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> smlToL(n);
        vector<int> smlToR(n);

        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            smlToL[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        while (!st.empty()) st.pop();

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            smlToR[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            int width = smlToR[i] - smlToL[i] - 1;
            int height = heights[i];
            ans = max(ans, width * height);
        }
        return ans;
    }
};

// getting tle in this due to using multiple functions and arrays

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int> smlToL = smallestToLeft(heights);
        vector<int> smlToR = smallestToRight(heights);
        // for(auto x: smlToL){
        //     cout<<x<<" ";
        // }
        // cout<<endl;
        // for(auto x: smlToR){
        //     cout<<x<<" ";
        // }
        // cout<<endl;

        int ans = 0;
        for(int i=0;i<heights.size();i++){
            int width = smlToR[i] - smlToL[i] - 1;
            int height = heights[i];
            // cout<<width<<" "<<height<<endl;
            ans = max(ans, width*height);
        }
        return ans;
    }
private: 
    vector<int> smallestToLeft(vector<int> & nums){
        vector<int> answer;
        stack<int> st;
        for(int i=0;i<nums.size();i++){
            while(!st.empty()&& nums[st.top()]>=nums[i]){
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
    vector<int> smallestToRight(vector<int>& nums){
        vector<int> answer;
        stack<int> st;
        for(int i=nums.size()-1;i>=0;i--){
            while(!st.empty()&& nums[st.top()]>=nums[i]){
                st.pop();
            }
            if(st.empty())
                answer.push_back(nums.size());
            else
                answer.push_back(st.top());
            st.push(i);
        }
        reverse(answer.begin(), answer.end());
        return answer;
    }
};