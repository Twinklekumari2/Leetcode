#include<vector>
class MinStack {
public:
    vector<pair<int, int>> st;
    int ind = -1;
    MinStack() {
        
    }
    
    void push(int value) {
        if(ind == -1){
            st.push_back({value, value});
        }else{
            int mini = min(st.back().second, value);
            st.push_back({value, mini});
        }
        ind++;
    }
    
    void pop() {
        st.pop_back();
        ind--;
    }
    
    int top() {
        return ind==-1 ? -1 : st.back().first;
    }
    
    int getMin() {
        return ind==-1 ? -1 : st.back().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */