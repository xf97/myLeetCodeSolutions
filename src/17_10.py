class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        #虽然标记为简单题，但是要求时间复杂度是On，空间复杂度是O1
        #是不是位运算？
        #感觉又要用那个投票算法
        #这个用简单的方法做就没意思了，但是OnO1的方法就肯定不是个简单题
        #想起来了，摩尔投票，开搞
        result = nums[0]   #列表不为空
        count = 1
        #开始投票
        #相同count+1，不相同-1
        #count为0时重新赋值
        for num in nums[1:]:
            if count == 0:
                result = num
                count += 1
            else:
                if num == result:
                    count += 1
                else:
                    count -= 1
        #print(result)
        #要处理没有主要元素的情况
        resultCount = 0 #检查当前被认定的主要元素在列表中出现了几次
        for num in nums:
            if  result == num:
                resultCount += 1
            else:
                continue
        #当不存在主要元素时返回-1
        if (resultCount << 1) > len(nums):
            return result
        else:
            return -1
