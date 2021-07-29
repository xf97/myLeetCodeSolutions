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
