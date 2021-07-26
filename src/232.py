class MyQueue:
    #要用两个栈
    #一个主栈，一个在出队时的辅助栈
    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.mainStack = list() #后进后出
        self.assistStack = list()


    def push(self, x: int) -> None:
        """
        Push element x to the back of queue.
        """
        self.mainStack.append(x)


    def pop(self) -> int:
        """
        Removes the element from in front of queue and returns that element.
        """
        #弹出主栈元素到辅助栈中
        while len(self.mainStack):
            self.assistStack.append(self.mainStack[-1])
            #弹出元素
            self.mainStack.pop()
        result = self.assistStack[-1]   #获得栈顶
        self.assistStack.pop()
        while len(self.assistStack):
            self.mainStack.append(self.assistStack[-1])
            self.assistStack.pop()
        return result


    def peek(self) -> int:
        """
        Get the front element.
        """
        #弹出主栈元素到辅助栈中
        while len(self.mainStack):
            self.assistStack.append(self.mainStack[-1])
            #弹出元素
            self.mainStack.pop()
        result = self.assistStack[-1]   #获得栈顶
        while len(self.assistStack):
            self.mainStack.append(self.assistStack[-1])
            self.assistStack.pop()
        return result

    def empty(self) -> bool:
        """
        Returns whether the queue is empty.
        """
        return len(self.mainStack) == 0



# Your MyQueue object will be instantiated and called as such:
# obj = MyQueue()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.peek()
# param_4 = obj.empty()
