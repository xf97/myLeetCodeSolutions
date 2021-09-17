class MyCircularQueue:
    '''
    设计类的题目就很奇特
    感觉用取余会更好一些
    五分钟，一次提交，时间击败-6.01%，空间击败-64.26%
    '''
    def __init__(self, k: int):
        self.list = [0] * k
        self.length = 0 #当前长度
        self.limit = k  #最大长度


    def enQueue(self, value: int) -> bool:
        if self.length == self.limit:
            #队列已满，不可删除
            return False
        self.list[self.length] = value  #赋值
        self.length += 1
        return True

    def deQueue(self) -> bool:
        if self.length == 0:
            return False
        #从后向前覆盖
        self.length -= 1
        for i in range(self.length):
            self.list[i] = self.list[i + 1]
        return True

    def Front(self) -> int:
        if self.length == 0:
            return -1
        return self.list[0]

    def Rear(self) -> int:
        if self.length == 0:
            return -1
        return self.list[self.length - 1]

    def isEmpty(self) -> bool:
        return self.length == 0

    def isFull(self) -> bool:
        return self.length == self.limit



# Your MyCircularQueue object will be instantiated and called as such:
# obj = MyCircularQueue(k)
# param_1 = obj.enQueue(value)
# param_2 = obj.deQueue()
# param_3 = obj.Front()
# param_4 = obj.Rear()
# param_5 = obj.isEmpty()
# param_6 = obj.isFull()
