class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        #累了，做个简单题吧
        #微微地干翻蚂蚁金服
        #最简单就是On2，然后要求各个字母保持顺序
        #我现在想用On解决，双指针
        #很棒，十分钟，一次提交
        #时间击败-65.99%，空间击败-35.31%
        len1 = len(s)
        len2 = len(t)
        if len1 > len2:
            return False
        p1 = 0
        p2 = 0
        while p1 < len1 and p2 < len2 and p1 <= p2:
            if s[p1] == t[p2]:
                #print(p1, p2)
                p1 += 1
                p2 += 1
            else:
                p2 += 1
        #最后应该是p1到末尾了，p2可以到可以不到
        return p1 == len1 
