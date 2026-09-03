class MinStack {
public:
    vector<int> s;
    MinStack() {
       
    }
    
    void push(int val) {
        s.push_back(val);
    }
    
    void pop() {
        s.pop_back();
    }
    
    int top() {
        return s[s.size()-1];
    }
    
    int getMin() {
        int min=INT_MAX;
        for(int e:s){
            if(e<min){
                min=e;
            }
        }
        return min;
    }
};
