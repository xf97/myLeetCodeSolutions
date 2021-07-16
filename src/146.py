class LRUCache(collections.OrderedDict):
    #我要开始了
    #今天新认识一个结构，有序字典
    #看了题解，五分钟，一次提交，时间击败-44.26%，空间击败-5.17%
    def __init__(self, capacity: int):
        #python3 要手动调用基类
        super().__init__()
        self.capacity = capacity

    def get(self, key: int) -> int:
        if key not in  self:
            #因为继承了字典，所以本身就是一个字典
            return -1
        #否则更新
        self.move_to_end(key)
        return self[key]

    def put(self, key: int, value: int) -> None:
        self[key] = value
        self.move_to_end(key)   #新来的在前面
        if len(self) > self.capacity:
            #删除最后的元素
            self.popitem(last = False)  #先进先出原则删除



# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)
