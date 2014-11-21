class MinStack {
private:
    stack<int> sta;
    stack<int> minSta;
public:
    void push(int x) {
        sta.push(x);
        if(!minSta.size() || minSta.top() >= x)
            minSta.push(x);
    }

    void pop() {
        if(!sta.empty()) {
            if(!minSta.empty() && sta.top() == minSta.top())
                minSta.pop();
            sta.pop();
        }
    }

    int top() {
        if(!sta.empty()) return sta.top();
    }

    int getMin() {
        if(!minSta.empty()) return minSta.top();
    }
};
