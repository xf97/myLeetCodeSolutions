class Solution:
    def firstUniqChar(self, s: str) -> str:
        #今天有点小累，虐一道简单题
        #用哈希表，两次遍历，时间On，空间On
        #s会不会只包含空格——测试过，测试用例中不包含"       "这种输入
        #题目保证测试用例中只包含小写字母——不用处理大小写
        #三次提交，五分钟解决，时间击败：33.38%，空间击败：95.21%
        if s == "":
            return " "
        else:
            charAndCount = dict()
            for i in s:
                if i in charAndCount:
                    charAndCount[i] += 1
                else:
                    charAndCount[i] = 1
            #再次遍历
            for i in s:
                if charAndCount[i] == 1:
                    return i
                else:
                    continue
            #如果所有字母都重复，那么就返回指定串
            return " "
