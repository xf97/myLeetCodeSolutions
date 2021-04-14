class MinStack {
public:
    /** initialize your data structure here. */
    //要注意弹出最小元素后的次小元素更新问题
    //用一个最小元素栈
    //还有点难想
    //两次提交，十五分钟，时间击败：22.97%，空间击败：74.11%
    MinStack() {
    }
    
    void push(int x) {
        element.push(x);
        //如果当前最小元素栈为空，或者是压入元素小于等于最小元素栈栈顶
        //则压入此元素到最小元素栈中
        if(minElement.empty() || (x <= minElement.top())){
            minElement.push(x);
        }
    }
    
    void pop() {
        //如果被pop的元素是当前最小的元素，那么最小元素栈也pop
        if(element.top() == minElement.top()){
            element.pop();
            minElement.pop();
        }
        else{
            element.pop();
        }
    }
    
    int top() {
        return element.top();
    }
    
    int min() {
        return minElement.top();
    }
private:
    stack<int> element; //主栈
    stack<int> minElement;  //最小元素栈
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */
