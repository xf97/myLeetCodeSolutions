class Solution:
    def findWords(self, words: List[str]) -> List[str]:
        #最基础的想法就是遍历
        #今天有点累了，做个简单题
        #15分钟，索然无味（虽然用的是最舔狗的方法）
        #时间击败：11.09%，空间击败：49.83%
        lines = ["qwertyuiop", "asdfghjkl", "zxcvbnm"]
        result = list() #结果数组
        #题目保证，words长度不为0，words中的每个单词长度也不为0
        #先转换
        flag = True
        for word in words:
            #先确定是哪一排
            _1stChar = word[0]
            lineNum = -1
            #注意字母大小写
            for index, line in enumerate(lines):
                if _1stChar.lower() in line:
                    lineNum = index
                    break
                else:
                    continue
            #lineNum总会得到赋值，不会等于-1的
            #然后把后面的字母后那一行对
            for char in word[1:]:
                if char.lower() not in lines[lineNum]:
                    flag = False
                    break
                else:
                    continue
            #直到最后还可以活着的人才能入围
            if flag == True:
                result.append(word)
                lineNum = -1
            else:
                flag = True
        return result



