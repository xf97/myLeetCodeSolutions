class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        #复仇字节第二步
        #空格不算重复也不算长度，数字符号算
        #滑动窗口
        #好久好久，整得烦了
        #五次提交，四十分钟，时间击败-24.52%，空间击败-8.7%
        result = 0  #最长子串长度
        tempResult = 0  #当前最长子串长度
        longestStrList = list() #当前最长子串
        #边界处理
        if len(s) == 0:
            return result
        left = 0 #左指针
        right =  0 #右指针
        while left <  len(s):
            #right =  left
            while right < len(s) and s[right] not  in longestStrList:
                #right += 1
                longestStrList.append(s[right])
                right += 1
            #print(longestStrList)
            if left == 0:
                result = max(result,  len(longestStrList))
                #print(longestStrList, result)
            else:
                result  =  max(result, len(longestStrList))
                #print(longestStrList, result)
            left += 1
            longestStrList = longestStrList[1:]
        #最后处理末尾情况
        result = max(result, len(longestStrList))
        return result
