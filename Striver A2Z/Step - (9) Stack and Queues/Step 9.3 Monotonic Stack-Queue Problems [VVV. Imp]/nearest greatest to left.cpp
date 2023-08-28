vector<int> nearestGratestToLeft(vector<int>& arr){
    vector<int> answer;
    stack<int> st;
    for(int i=0;i<arr.size();i++){
        while(!st.empty() && arr[i]>= st.top())
            st.pop();
        if(st.empty())
            answer.push_back(-1);
        else
            answer.push_back(st.top());
    }
    return answer;
}