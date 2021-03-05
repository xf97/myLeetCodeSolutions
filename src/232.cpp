class MyQueue {
    /*
    time defeat: 100%
    space defeat: 74.23%
    */
private:
    stack<int> mainStack;   //用来实现先入先出操作的主栈
    stack<int> cacheStack;  //用来缓存元素的缓存栈
public:
    /** Initialize your data structure here. */
    MyQueue() {
        //可以不做吧
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        //只向主栈推入元素
        mainStack.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int topNum = 0, tempNum = 0;
        //把主栈中的元素都转移到缓存栈去
        while(mainStack.size() != 1){
            topNum = mainStack.top();   //获得栈顶元素
            cacheStack.emplace(topNum); //压入缓存
            mainStack.pop();    //弹出
        }
        //然后记录当前的最前元素
        topNum = mainStack.top();
        mainStack.pop();
        //然后再从缓存栈压回去
        while(!cacheStack.empty()){
            tempNum = cacheStack.top();
            mainStack.emplace(tempNum);
            cacheStack.pop();
        }
        return topNum;
    }
    
    /** Get the front element. */
    int peek() {
        int topNum = 0, tempNum = 0;
        //把主栈中的元素都转移到缓存栈去
        while(mainStack.size() != 1){
            topNum = mainStack.top();   //获得栈顶元素
            cacheStack.emplace(topNum); //压入缓存
            mainStack.pop();    //弹出
        }
        //然后记录当前的最前元素
        topNum = mainStack.top();
        //然后再从缓存栈压回去
        while(!cacheStack.empty()){
            tempNum = cacheStack.top();
            mainStack.emplace(tempNum);
            cacheStack.pop();
        }
        return topNum;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return mainStack.empty();
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
