class MyStack {
public:
    queue< int> q;
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
    }
    
    int pop() {
        int n= q.size();
        while( n-->1){
            int front = q.front();
            q.pop();
            q.push(front);
        }
        int front = q.front();
        q.pop();
        return front;
    }
    
    int top() {
        int n= q.size();
        while( n-->1){
         int front = q.front();
            q.pop();
            q.push(front);
        }
        int front = q.front();
        q.pop();
        q.push(front);
        return front;
        
    }
    
    bool empty() {
        return q.empty();
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