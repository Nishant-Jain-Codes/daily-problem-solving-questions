class StockSpanner {
    int curDay;
    vector<int> days;
    vector<int> nge;
    stack<int> st;
public:
    StockSpanner() {
        curDay=-1;
    }
    
    int next(int price) {
        days.push_back(price);
        int curDayIndex = days.size()-1;
        while(!st.empty() && days[st.top()]<= price)
            st.pop();
        if(st.empty())
            nge.push_back(-1);
        else
            nge.push_back(st.top());
        st.push(curDayIndex);
        return curDayIndex-nge.back();
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */