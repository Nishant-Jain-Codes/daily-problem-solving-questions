https://leetcode.com/problems/min-stack/description/

class MinStack {
    stack<pair<int,int>> stk ; //<top,curMin>
public:
    MinStack() {
        stack<pair<int,int>> stk;  
    }
    
    void push(int val) {
        int curMin;
        if(this->stk.empty())
            curMin = val;
        else 
            curMin = min(this->stk.top().second,val);
        
        this->stk.push({val,curMin});

    }
    
    void pop() {
        this->stk.pop();
    }
    
    int top() {
        return this->stk.top().first;
    }
    
    int getMin() {
        return this->stk.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */