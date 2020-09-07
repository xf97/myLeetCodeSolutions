class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        res = list()
	#记录每个元素的出现次数
        for i in set(nums):
            res.append((i, nums.count(i)))
	#按出现次数从大到小排序
        res = sorted(res, key = (lambda x:x[1]), reverse = True)
        finalRes = list()
	#返回出现次数前k多的元素
        for i in range(0, k):
            finalRes.append(res[i][0])
        return finalRes
            #res[i] = nums.count(i)
            #res.append(nums.(count(i)))
