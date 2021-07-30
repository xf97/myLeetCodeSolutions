class MinStack {
private:
    stack<int> nums;
    int minNumCount;
    int minNum;
public:
    /** initialize your data structure here. */
    //十五分钟，差点被简单题坑了
    //一次提交，时间击败—98.47%, 空间击败-25.48%
    MinStack(): minNum(INT_MAX), minNumCount(0){

    }
    
    void push(int val) {
        nums.push(val);
        if(val < minNum){
            minNum = val;
            minNumCount = 1;
        }
        else if(val == minNum){
            minNumCount ++;
        }
    }
    
    void pop() {
        int popItem = nums.top();
        nums.pop();
        //非空栈进行
        if(popItem == minNum){
            minNumCount --;
            if(minNumCount == 0){
                //要更换最小元素了
                stack<int> temp;
                minNum = INT_MAX;
                while(!nums.empty()){
                    if(nums.top() < minNum){
                        minNum = nums.top();
                    }
                    temp.push(nums.top());
                    nums.pop();
                }
                //倒回去
                while(!temp.empty()){
                    if(temp.top() == minNum){
                        minNumCount ++;
                    }
                    nums.push(temp.top());
                    temp.pop();
                }
            }
        }
    }
    
    int top() {
        return nums.top();
    }
    
    int getMin() {
        return minNum;
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
