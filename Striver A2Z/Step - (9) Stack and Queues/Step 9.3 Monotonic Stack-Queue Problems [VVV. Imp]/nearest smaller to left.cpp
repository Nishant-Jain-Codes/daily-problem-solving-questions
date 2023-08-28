vector<int> nearestSmallerElementToLeft(vector<int>& nums){
    vector<int> answer;
    stack<int> st;
    for(int i=0;i<nums.size();i++){
        while(!st.empty() && st.top()>= nums[i])
            st.pop();
        if(st.empty())
            answer.push_back(-1);
        else
            answer.push_back(st.top());
    }
    return answer;
}