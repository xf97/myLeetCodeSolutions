class MyHashSet:
    '''
    事情有点多，就随便写了
    两分钟，一次提交，时间击败-23.12%，空间击败-93.03%
    '''
    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.element = list()


    def add(self, key: int) -> None:
        if key not in self.element:
            self.element.append(key)

    def remove(self, key: int) -> None:
        if key in self.element:
            self.element.remove(key)


    def contains(self, key: int) -> bool:
        """
        Returns true if this set contains the specified element
        """
        return key in self.element



# Your MyHashSet object will be instantiated and called as such:
# obj = MyHashSet()
# obj.add(key)
# obj.remove(key)
# param_3 = obj.contains(key)
