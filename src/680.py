class Solution:
    def validPalindrome(self, s: str) -> bool:
        #最简单的方法，每个字符都尝试，时间复杂度On2
        #果然超时，391/466
        #使用双指针是解决回文字符串的另一个方法，十分钟
        #两次提交，时间击败-85.88%，空间击败-80.56%
        if len(s) <= 1:
            return True
        def isReverse(_str):
            return _str == _str[::-1]
        result = isReverse(s)
        left, right = 0, len(s) - 1
        while result != True and left < right:
            if s[left] == s[right]:
                left += 1
                right -= 1
            else:
                return isReverse(s[left + 1 : right + 1]) or isReverse(s[left: right])
        return result
        '''
        index = 0
        while result != True and index < len(s):
            tempList = list(s)
            tempList.pop(index)
            tempStr = "".join(tempList)
            result = isReverse(tempStr)
            index += 1
        return result
        '''
