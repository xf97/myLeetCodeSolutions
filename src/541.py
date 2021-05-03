class Solution:
    def reverseStr(self, s: str, k: int) -> str:
        #逐个缩小问题，递归解决
        #使用python解决就方便
        #一次提交，十分钟那个，时间击败-53.65%，空间击败-5.81%
        if len(s) < k:
            return s[::-1]
        elif len(s) >= k and len(s) < (2*k):
            return s[:k][::-1] + s[k:]
        else:
            return s[:k][::-1] + s[k:(2*k)] + self.reverseStr(s[(2*k):], k)
