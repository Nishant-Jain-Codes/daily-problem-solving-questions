class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> nge ;
        stack<int> st ;
        for(int i=nums2.size()-1;i>=0;i--){
            while(!st.empty() && st.top()<=nums2[i]){
                st.pop();
            }
            if(st.empty()){
                nge.push_back(-1);
            }
            else{
                nge.push_back(st.top());
            }
            st.push(nums2[i]);
        }
        reverse(nge.begin(),nge.end());
        unordered_map<int,int>mp;
        for(int i=0;i<nums2.size();i++){
            mp[nums2[i]]=nge[i];
        }
        vector<int> answer;
        for(int i=0;i<nums1.size();i++){
            answer.push_back(mp[nums1[i]]);
        }
        return answer;
    }
};