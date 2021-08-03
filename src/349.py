class Solution:
    def intersection(self, nums1: List[int], nums2: List[int]) -> List[int]:
        #干翻蚂蚁金服！
        #这个是不是太简单了，On2吗，有没有好办法
        #整个哈希表，On的时间和On的空间
        #五分钟，一次提交，时间击败-90.53%，空间击败-21.26%
        length1 = len(nums1)
        length2 = len(nums2)
        result = set()
        if length1 == 0 or length2 == 0:
            return result
        #num1是短的那个
        if length1 > length2:
            nums1, nums2 = nums2, nums1
        appeardNum = set()
        for i in nums1:
            appeardNum.add(i)
        #然后再遍历nums2就可以了
        for i in nums2:
            if i in appeardNum:
                result.add(i)
            else:
                continue
        return list(result)
