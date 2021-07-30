class Solution:
    def isSubList(self, _source, _dest):
        source = [str(i) for i in _source]
        dest = [str(i) for i in _dest]
        if " ".join(source) in " ".join(dest):
            return True
        else:
            return False

    def findLength(self, nums1: List[int], nums2: List[int]) -> int:
        #干翻拼多多！
        #要么动态规划，要么双指针
        #动态规划
        #左闭右闭, num1[i:j]是公共子数组的前提是
        #num1[x+i:x+j-1]是公共子数组并且num1[j] == num2[j]
        #或者num1[x+i-1:x+j]是公共子数组并且num1[i] == num2[i]
        #x是边界情况, 范围从[-i, length-j-1]
        #我先暴力做一回
        #复杂度O好多n方
        #递归加试探回溯
        #短的往长的走
        #不暴力了，动态规划，就离谱
        m = len(nums1)
        n = len(nums2)
        dp = [[0] * (n + 1) for _ in range(m + 1)]
        ans = 0
        for i in range(m - 1, -1, -1):
            for j in range(n - 1, -1, -1):
                dp[i][j] = dp[i + 1][j + 1] + 1 if nums1[i] == nums2[j] else 0
                ans = max(ans, dp[i][j])
        return ans
