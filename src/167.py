class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        #干翻出这个题的公司
        #左右指针，缩进来
        #五分钟，一次提交，On时间复杂度，时间击败-52.02%，空间-86.01%
        length = len(numbers)
        #题目保证答案一定存在
        left = 0
        right = length - 1
        while numbers[left] + numbers[right] != target:
            if numbers[left] + numbers[right] < target:
                left += 1
            else:
                right -= 1
        return [left + 1, right + 1]
