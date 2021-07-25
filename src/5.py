class Solution:
    #不可以用滑动窗口，我居然想用递归做，我也是疯了
    #感觉应该是动态规划
    def longestPalindrome(self, s: str) -> str:
        #干翻拼多多！
        #字符串最长问题，滑动窗口
        #果然是动态规划
        #递推公式是  dp(i,j) = dp(i+1, j-1) && s[i] == s[j]
        #二维，On2辅助空间
        #两次提交，二十分钟，时间击败-35.70%，空间击败-31.58%
        #边界情况处理
        length = len(s)
        if length <= 1:
            return s
        elif length == 2:
            if s[0] == s[1]:
                return s
            else:
                return s[0]
        else:
            #构建辅助空间
            dp = [[False] * length for _ in range(length)]  #n*n空间
            #初始化
            dp[0][0] = True
            result = s[0] #结果
            #开始枚举子串
            #从短向长，从左到右
            for L in range(2, length + 1):
                #L是子串长度
                for left in range(length):
                    #left是左起点
                    right = left + L - 1    #右边界
                    if right >= length:
                        break
                    else:
                        #判断当前字串
                        if s[left] != s[right]:
                            dp[left][right] = False
                        else:
                            if L <= 3:
                                dp[left][right] = True
                            else:
                                dp[left][right] = dp[left+1][right-1]
                    #判断当前结果
                    if dp[left][right] and L > len(result):
                        result = s[left:right + 1]
            return result 


