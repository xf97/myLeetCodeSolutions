class Solution:
    def sortArray(self, nums: List[int]) -> List[int]:
        #干翻腾讯！
        #今天手写堆排序
        #四个步骤
        #主函数调用堆排序
        #堆排序里，先初始化堆，再从后向前逐个构造堆
        #初始化堆方法，从后向前，从当前i到最后元素构造堆
        #构造堆方法，先交换当前最后元素和堆首元素，然后从0到当前元素构造堆
        #如何构造堆，从root到尾，在左元素在堆中时，判断下一个要跟根元素比较的元素，然后看是否要和根元素的交换，如果要交换就交换后更改根几点，否则跳出循环
        self.heapSort(nums)
        return nums

    def heapSort(self, nums):
        #先初始化堆
        self.buildHeap(nums)
        #然后从后向前，交换每一个元素后重新构造堆
        for i in range(len(nums) - 1, -1, -1):
            nums[i], nums[0] = nums[0], nums[i]
            self.maxHeap(nums, 0, i)    #构造0-i的堆
        return

    def buildHeap(self, nums):
        for i in range(len(nums) - 1, -1, -1):
            self.maxHeap(nums, i, len(nums))

    def maxHeap(self, nums, root, length):
        p = root
        while p * 2 + 1 < length:
            l, r = p * 2 + 1, p * 2 + 2
            #判断下一个节点是谁
            if length <= r or nums[r] < nums[l]:
                nex = l
            else:
                nex = r
            if nums[p] < nums[nex]:
                #交换根节点
                nums[p], nums[nex] = nums[nex], nums[p]
                p = nex
            else:
                break
