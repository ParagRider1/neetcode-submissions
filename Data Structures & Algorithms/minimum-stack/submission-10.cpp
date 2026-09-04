class MinStack {
public:
    stack<int> s; 
    stack<int> prevmin; 

    MinStack() {}
    
    void push(int val) {
        s.push(val);
        // Push to prevmin if it's empty, OR if the new value is <= the current minimum.
        // Using <= ensures duplicate minimums are tracked correctly!
        if (prevmin.empty() || val <= prevmin.top()) {
            prevmin.push(val);
        }
    }
    
    void pop() {
        // Only pop from prevmin if the element we are removing from 's' 
        // is exactly the current minimum.
        if (s.top() == prevmin.top()) {
            prevmin.pop();
        }
        s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return prevmin.top();
    }
};