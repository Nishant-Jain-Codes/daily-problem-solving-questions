vector<int> nearestSmallerElementToRight(vector<int>& nums){
    vector<int> answer;
    stack<int> st;
    for(int i=nums.size()-1;i>=0;i--){
        while(!st.empty() && st.top()>= nums[i])
            st.pop();
        if(st.empty())
            answer.push_back(-1);
        else
            answer.push_back(st.top());
    }
    reverse(answer.begin(),answer.end());
    return answer;
}