'''
class Solution:
    def reverseWords(self, s: str) -> str:
        #干翻蚂蚁链
        #感觉不太像中等题呀
        #s = s.strip()
        wordsList = s.split(" ")
        #print(wordsList)
        wordsList.reverse()
        result = list()
        for i in wordsList:
            if i != "":
                result.append(i)
            else:
                continue
        return " ".join(result)
 '''
class Solution:
    def reverseWords(self, s: str) -> str:
        #先整体翻转，再逐个翻转
        #很棒，一行代码的体验
        #一分钟，时间击败-40.22%，空间击败-5.17%
        return " ".join([i[::-1] for i in s[::-1].strip().split()])
