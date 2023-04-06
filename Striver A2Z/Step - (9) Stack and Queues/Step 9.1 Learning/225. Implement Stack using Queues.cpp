https://leetcode.com/problems/implement-stack-using-queues/

class MyStack {
    queue<int> q;
public:
    MyStack() {
        queue<int> q;
    }
    
    void push(int x) {
        this->q.push(x);
    }
    
    int pop() {
        if(this->empty())
            return -1;
        int ref = INT_MAX;
        this->q.push(ref);
        int pop_val;
        while(true){
            pop_val = this->q.front();
            q.pop();
            if(this->q.front()==ref)
            {
                this->q.pop();
                return pop_val;
            }else {
                this->q.push(pop_val);
            }
        }
    }
    
    int top() {
        if(this->empty())
            return -1;
        int ref = INT_MAX;
        this->q.push(ref);
        int pop_val;
        while(true){
            pop_val = this->q.front();
            q.pop();
            if(this->q.front()==ref)
            {
                this->q.pop();
                this->q.push(pop_val);
                return pop_val;
            }else {
                this->q.push(pop_val);
            }
        }
    }
    
    bool empty() {
        return this->q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */