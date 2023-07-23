vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    // Write your code here.
    vector<int> answer(arr.size(),-1);
    stack<int> stk;
    for(int i=arr.size()-1;i>=0;i--){
        while(!stk.empty() && stk.top()>=arr[i]){
            stk.pop();
        }
        if(!stk.empty()){
            answer[i]=stk.top();
        }
        stk.push(arr[i]);
    }
    return answer;
}