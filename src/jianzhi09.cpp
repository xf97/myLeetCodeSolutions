class CQueue {
    //两个栈实现队列
    /*
    time defeat: 10.79%
    space defeat: 11.72%
    */
public:
    CQueue() {
    }
    
    void appendTail(int value) {
        //cout<<value<<endl;
        mainStack.push(value);
        //cout<<1<<endl;
    }
    
    int deleteHead() {
        //边界条件
        if(mainStack.empty()){
            return -1;
        }
        //把主栈的元素都导出到缓存栈中
        transferStack(mainStack, cacheStack);
        int result = cacheStack.top();
        cacheStack.pop();
        //再倒回去
        transferStack(cacheStack, mainStack);
        return result;
    }

private:
    stack<int> mainStack;   //主栈
    stack<int> cacheStack;  //用于元素出队时缓存其他元素

    void transferStack(stack<int> & _stack1, stack<int> & _stack2){
        while(! _stack1.empty()){
            int temp = _stack1.top();
            _stack2.push(temp);
            _stack1.pop();
        }
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */
