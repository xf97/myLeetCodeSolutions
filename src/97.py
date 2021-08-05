class Solution:
    def isInterleave(self, s1: str, s2: str, s3: str) -> bool:
        #干翻蚂蚁金服！
        #这个题目都快给我整懵了
        #读懂了，按顺序交错，每个子串非空
        #s1和s2长度相差小于等于1
        #现在的想法是三个指针
        #成功情况是三个指针都走到末尾
        #当其中一个指针与目标串指针所指字母相同时，前进指针
        #只要有一个没到末尾，就失败
        #要处理极端情况，比如两个前缀相同，你移动哪一个
        #aabcc, aaccc, aaaacbcc
        #没事，先移动哪一个都无所谓
        #哭了，指针不可以，要动态规划
        '''
        len1 = len(s1)
        len2 = len(s2)
        len3 = len(s3)
        if len1 + len2 != len3:
            return False
        p1, p2, p3 = 0, 0, 0    #指针
        #相同时，默认移动p1
        while p1 < len1 and p2 < len2 and p3 < len3:
            if s1[p1] == s3[p3]:
                p1 += 1
                p3 += 1
            elif s2[p2] == s3[p3]:
                p2 += 1
                p3 += 1
            else:
                #都不相等，G了
                return False
        #处理没完的那一个
        if p1 == len1:
            while p2 < len2 and p3 < len3:
                if s2[p2] == s3[p3]:
                    p2 += 1
                    p3 += 1
                else:
                    return False
        elif p2 == len2:
            while p1 < len1 and p3 < len3:
                if s1[p1] == s3[p3]:
                    p1 += 1
                    p3 += 1
                else:
                    return False
        #成功条件判断
        print(p1, len1, p2, len2, p3, len3)
        return p1 == len1 and p2 == len2 and p3 == len3
        '''
        #要用动态规划，哭了，给我打了这么多
        #f(i,j)=[f(i−1,j) and s1[i] == s3[i+j-1]] or [f(i,j-1) and s2[j] == s3[i + j - 1]]
        #初始状态
        #f(0,0) = True
        #一次提交，三十分钟，时间击败-39.41%，空间击败-42.06%
        #开始动态规划
        len1 = len(s1)
        len2 = len(s2)
        len3 = len(s3)
        if len1 + len2 != len3:
            return False
        #s1是行, s2是列，要有m+1和n+1个
        dp = [[False] * (len2 + 1) for _ in range(len1 + 1)]
        dp[0][0] = True
        #开始动态规划
        #记得给第一行和第一列填值
        for i in range(len1 + 1):
            for j in range(len2 + 1):
                p = i + j - 1
                if i > 0:
                    #记得减1，减1不超限
                    dp[i][j] = dp[i][j] or (dp[i - 1][j] and s1[i - 1] == s3[p])
                if j > 0:
                    dp[i][j] = dp[i][j] or (dp[i][j - 1] and s2[j - 1] == s3[p])
        #print(dp)
        return dp[len1][len2]
                
