class Solution:
    def PredictTheWinner(self, nums: List[int]) -> bool:
        length = len(nums)
        #init the two-division array
        dp = [[0] * length for _ in range(length)]
        #填充对角线
        for _index, _value in enumerate(nums):
            dp[_index][_index] = _value
        #填充上半区，最远一个元素dp[length-2][length-1]，最近一个dp[0][1]
        for i in range(length - 2, -1, -1):
            for j in range(i + 1, length):
                dp[i][j] = max(nums[i] - dp[i + 1][j], nums[j] - dp[i][j - 1])
        return dp[0][length - 1] >= 0
