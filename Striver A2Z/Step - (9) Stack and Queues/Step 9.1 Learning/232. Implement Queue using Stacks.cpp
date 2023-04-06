https://leetcode.com/problems/implement-queue-using-stacks/

class MyQueue {
    stack<int> main,temp;
public:
    MyQueue() {
        stack<int>  main,temp;
    }
    
    void push(int x) {
        this->main.push(x);
    }
    
    int pop() {
        if(this->empty())
            return -1;
        int pop_val;
        while(!this->main.empty()){
            pop_val = this->main.top();
            this->main.pop();
            this->temp.push(pop_val);
        }
        int ans = pop_val;
        this->temp.pop();
        while(!this->temp.empty()){
            pop_val=this->temp.top();
            this->temp.pop();
            this->main.push(pop_val);
        }
        return ans;
    }
    
    int peek() {
        if(this->empty())
            return -1;
        int pop_val;
        while(!this->main.empty()){
            pop_val = this->main.top();
            this->main.pop();
            this->temp.push(pop_val);
        }
        int ans = pop_val;
        while(!this->temp.empty()){
            pop_val=this->temp.top();
            this->temp.pop();
            this->main.push(pop_val);
        }
        return ans;
    }
    
    bool empty() {
        return this->main.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */