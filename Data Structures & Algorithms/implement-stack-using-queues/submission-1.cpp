class MyStack {
public:
    queue<int> q;

    void push(int x) {
        q.push(x);
        int n = q.size();
        // Rotate all previous elements behind the new element x
        while (n-- > 1) {
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        int val = q.front();
        q.pop();
        return val; // O(1)
    }
    
    int top() {
        return q.front(); // O(1)
    }
    
    bool empty() {
        return q.empty(); // O(1)
    }
};