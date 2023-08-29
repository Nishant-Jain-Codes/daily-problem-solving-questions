https://leetcode.com/problems/min-stack/description/
//O(1) space
class MinStack {
    stack<long long int> s;
    long long int minEle;
    
public:
    MinStack() {
        
    }
    
    void push(long long int val) {
        if (s.empty()) {
            s.push(val);
            minEle = val;
        } else if (val <= minEle) {
            s.push(2 * val - minEle);
            minEle = val;
        } else {
            s.push(val);
        }
    }
    
    void pop() {
        if (s.empty())
            return;
        
        long long int topVal = s.top();
        s.pop();
        
        if (topVal < minEle) {
            minEle = 2 * minEle - topVal;
        }
    }
    
    int top() {
        if (s.empty())
            return -1;
        
        long long int topVal = s.top();
        if (topVal < minEle) {
            return minEle;
        }
        return topVal;
    }
    
    int getMin() {
        if (s.empty())
            return -1;
        return minEle;
    }
};

//O(n) space
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